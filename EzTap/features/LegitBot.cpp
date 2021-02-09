#include "LegitBot.hpp"

void LegitBot::Triggerbot(CUserCmd* pCmd)
{
	int crossId = LocalPlayer->CrosshairId();

	if (crossId >= 0 && crossId <= 64)
	{
		C_BaseEntity* pEntity = interfaces.ClientEntityList->GetClientEntity(crossId);

		if (!pEntity->isValid() || pEntity->isTeammate())
			return;

		pCmd->buttons |= IN_ATTACK;
	}
}

void LegitBot::RadarHack()
{
	for (unsigned long i = 0; i < interfaces.Engine->getMaxClients(); i++)
	{
		C_BaseEntity* pEntity = interfaces.ClientEntityList->GetClientEntity(i);

		if (!pEntity->isValid() || pEntity->isTeammate())
			continue;

		pEntity->Setspotted(true);
	}
}
