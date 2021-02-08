#pragma once
#include "../Hooks.hpp"
#include "../Interfaces.hpp"
#include "Autowall.hpp"

namespace Aimbot
{
	C_BaseEntity* GetEntityNearCrosshair(Vector viewAngles, float FOV = 20);
	void CreateMove(CUserCmd * pCmd);
}