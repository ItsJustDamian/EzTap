#include "Aimbot.hpp"

C_BaseEntity* Aimbot::GetEntityNearCrosshair(Vector viewAngles, float FOV)
{
    C_BaseEntity* pEntity = nullptr;
    float fDelta = FLT_MAX;

    for (unsigned long i = 0; i < interfaces.Engine->getMaxClients(); i++)
    {
        C_BaseEntity* cEntity = interfaces.ClientEntityList->GetClientEntity(i);

        if (!cEntity->isValid() || cEntity->isTeammate() || cEntity->gunGameImmunity())
            continue;

        bool bHittable = false;

        Vector bonePos = cEntity->getBonePosition(features.Aimbot_Bone);

        if (features.Autowall)
            bHittable = Autowall::canScan(cEntity, bonePos, LocalPlayer->getActiveWeapon()->getWeaponData(), features.AutowallMinDmg, true);
        else 
            bHittable = cEntity->isVisible(bonePos);

        if (!bHittable)
            continue;

        Vector angle = interfaces.Engine->CalcAngle(LocalPlayer->getEyePosition(), cEntity->getEyePosition());
        float delta = (angle - viewAngles).Clamped().Length();

        if (delta < fDelta && delta < FOV)
        {
            fDelta = delta;
            pEntity = cEntity;
        }
    }

    return pEntity;
}

void Aimbot::CreateMove(CUserCmd* pCmd)
{
    if (!LocalPlayer)
        return;

    if (pCmd->buttons & IN_USE)
        return;

    C_BaseEntity* activeWeapon = LocalPlayer->getActiveWeapon();

    if (!activeWeapon)
        return;

    WeaponType weaponType = activeWeapon->getWeaponData()->type;

    if (activeWeapon->clip() == 0)
        return;

    if (weaponType == WeaponType::WEAPONTYPE_KNIFE || weaponType == WeaponType::WEAPONTYPE_C4 || weaponType == WeaponType::WEAPONTYPE_GRENADE)
        return;

    Vector viewAngles;
    interfaces.Engine->getViewAngles(&viewAngles);

    C_BaseEntity* pEntity = GetEntityNearCrosshair(viewAngles, features.Aimbot_FOV);

    if (!pEntity)
        return;

    Vector aimAngles = interfaces.Engine->CalcAngle(LocalPlayer->getEyePosition(), pEntity->getBonePosition(features.Aimbot_Bone)) - LocalPlayer->aimPunchAngles() * 2;
    aimAngles = viewAngles + (aimAngles - viewAngles);
    aimAngles.Clamp();

    if (aimAngles.IsNan() || aimAngles.isNull())
        return;

    //Vector normalizedAngles = aimAngles.Normalized();

    if (features.Aimbot_Silent)
        pCmd->viewangles = aimAngles.Clamped();
    else
        interfaces.Engine->setViewAngles(&aimAngles.Clamped());

    if (!features.Aimbot_AutoFire)
        return;

    if (!LocalPlayer->velocity().isNull())
        return;

    if (activeWeapon->nextPrimaryAttack() > interfaces.GlobalVars->curtime && features.Aimbot_AutoFire)
    {
        pCmd->buttons &= ~IN_ATTACK;
    }
    else {
        if (activeWeapon->isWeaponSniper() && !LocalPlayer->isScoped() && features.Aimbot_AutoScope)
            pCmd->buttons |= IN_ATTACK2;
        else if (features.Aimbot_AutoFire)
        {
            if (weaponType == WeaponType::WEAPONTYPE_PISTOL || weaponType == WeaponType::WEAPONTYPE_SNIPER_RIFLE)
            {
                if (!LocalPlayer->aimPunchAngles().isNull())
                    return;

                pCmd->buttons |= IN_ATTACK;
            }
            else {
                pCmd->buttons |= IN_ATTACK;
            }
        }
    }
}
