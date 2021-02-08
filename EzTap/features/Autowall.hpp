#pragma once
#include "../valve_sdk/Classes/Vector.hpp"
#include "../Hooks.hpp"
#include "../Interfaces.hpp"
#include "../valve_sdk/Interfaces/IEngineTrace.hpp"

class Vector;
struct Trace_t;
struct SurfaceData;
struct WeaponInfo;

namespace Autowall
{
	Vector calculateRelativeAngle(Vector& source, Vector& destination, Vector& viewAngles);
	bool traceToExit(Trace_t& enterTrace, Vector& start, Vector& direction, Vector& end, Trace_t& exitTrace);
	float handleBulletPenetration(SurfaceData* enterSurfaceData, Trace_t& enterTrace, Vector& direction, Vector& result, float penetration, float damage);
	bool canScan(C_BaseEntity* entity, Vector destination, WeaponInfo* weaponData, int minDamage, bool allowFriendlyFire);
}