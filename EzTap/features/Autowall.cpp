#include "Autowall.hpp"

Vector Autowall::calculateRelativeAngle(Vector& source, Vector& destination, Vector& viewAngles)
{
    return ((destination - source) - viewAngles).Clamped();
}

bool Autowall::traceToExit(Trace_t& enterTrace, Vector& start, Vector& direction, Vector& end, Trace_t& exitTrace)
{
    const auto traceToExitFn = Memory::traceToExit;
    bool result;
    __asm {
        push exitTrace
        mov eax, direction
        push[eax]Vector.z
        push[eax]Vector.y
        push[eax]Vector.x
        mov eax, start
        push[eax]Vector.z
        push[eax]Vector.y
        push[eax]Vector.x
        mov edx, enterTrace
        mov ecx, end
        call traceToExitFn
        add esp, 28
        mov result, al
    }
    return result;
}

float Autowall::handleBulletPenetration(SurfaceData* enterSurfaceData, Trace_t& enterTrace, Vector& direction, Vector& result, float penetration, float damage)
{
    Vector end;
    Trace_t exitTrace;

    if (!traceToExit(enterTrace, enterTrace.endpos, direction, end, exitTrace))
        return -1.0f;

    SurfaceData* exitSurfaceData = interfaces.physicsSurfaceProps->getSurfaceData(exitTrace.surface.surfaceProps);

    float damageModifier = 0.16f;
    float penetrationModifier = (enterSurfaceData->penetrationmodifier + exitSurfaceData->penetrationmodifier) / 2.0f;

    if (enterSurfaceData->material == 71 || enterSurfaceData->material == 89) {
        damageModifier = 0.05f;
        penetrationModifier = 3.0f;
    }
    else if (enterTrace.contents >> 3 & 1 || enterTrace.surface.flags >> 7 & 1) {
        penetrationModifier = 1.0f;
    }

    if (enterSurfaceData->material == exitSurfaceData->material) {
        if (exitSurfaceData->material == 85 || exitSurfaceData->material == 87)
            penetrationModifier = 3.0f;
        else if (exitSurfaceData->material == 76)
            penetrationModifier = 2.0f;
    }

    damage -= 11.25f / penetration / penetrationModifier + damage * damageModifier + (exitTrace.endpos - enterTrace.endpos).LengthSqr() / 24.0f / penetrationModifier;

    result = exitTrace.endpos;
    return damage;
}

bool Autowall::canScan(C_BaseEntity* entity, Vector destination, WeaponInfo* weaponData, int minDamage, bool allowFriendlyFire)
{
    if (!LocalPlayer)
        return false;

    if (entity->isTeammate() && !allowFriendlyFire)
        return false;

    float damage{ static_cast<float>(weaponData->damage) };

    Vector start{ LocalPlayer->getEyePosition() };
    Vector direction{ destination - start };
    direction = direction / direction.Length();

    int hitsLeft = 4;

    while (damage >= 1.0f && hitsLeft) {
        Trace_t trace;
        interfaces.EngineTrace->traceRay({ start, destination }, 0x4600400B, LocalPlayer, trace);

        if (!allowFriendlyFire && trace.entity && trace.entity->isPlayer())
            return false;

        if (trace.fraction == 1.0f)
            break;

        if (trace.entity == entity && trace.hitgroup > HitGroup::Generic && trace.hitgroup <= HitGroup::RightLeg) {
            damage = HitGroup::getDamageMultiplier(trace.hitgroup) * damage * powf(weaponData->rangeModifier, trace.fraction * weaponData->range / 500.0f);

            if (float armorRatio{ weaponData->armorRatio / 2.0f }; HitGroup::isArmored(trace.hitgroup, trace.entity->hasHelmet()))
                damage -= (trace.entity->armor() < damage * armorRatio / 2.0f ? trace.entity->armor() * 4.0f : damage) * (1.0f - armorRatio);

            return damage >= minDamage;
        }
        const auto surfaceData = interfaces.physicsSurfaceProps->getSurfaceData(trace.surface.surfaceProps);

        if (surfaceData->penetrationmodifier < 0.1f)
            break;

        damage = handleBulletPenetration(surfaceData, trace, direction, start, weaponData->penetration, damage);
        hitsLeft--;
    }
    return false;
}