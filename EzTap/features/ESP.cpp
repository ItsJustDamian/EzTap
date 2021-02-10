#include "ESP.hpp"

void ESP::BoxEsp(int index, C_BaseEntity * pEntity, bool nameEsp, bool healthEsp, bool armorEsp)
{
	Vector head, feet;
	if (interfaces.Engine->WorldToScreen(pEntity->getBonePosition(8), head) && interfaces.Engine->WorldToScreen(pEntity->origin(), feet))
	{
		if (!pEntity->isValid() || pEntity->isTeammate())
			return;

		float height = feet.y - head.y + 10.f;
		float width = height / 2.4f + 10;

		float x = feet.x - (width / 2);
		float y = feet.y - height;

		if (features.BoxEsp)
		{
			drawList->AddRect({ x, y }, { x + width, y + height }, ImColor(204, 27, 207));
			drawList->AddCircle({ head.x, head.y }, 5, ImColor(1.f, 1.f, 1.f));
		}

		playerInfo plrInfo;
		if (nameEsp && interfaces.Engine->getPlayerInfo(index, &plrInfo))
			drawList->AddText({ feet.x - (width / 2), feet.y - height - 15 }, ImColor(204, 27, 207), plrInfo.name);
	
		if (healthEsp)
			drawList->AddText({feet.x, feet.y}, ImColor(204, 27, 207), ("Health: " + std::to_string(pEntity->oHealth())).c_str());

		if (armorEsp)
			drawList->AddText({ feet.x, feet.y + 10 }, ImColor(204, 27, 207), ("Armor: " + std::to_string(pEntity->armor())).c_str());
	}
}

void ESP::DrawMisc(C_BaseEntity* pEntity, ClientClass* pEntityClientClass)
{
	Vector w2s;
	if (interfaces.Engine->WorldToScreen(pEntity->origin(), w2s))
	{
		if (std::string(pEntityClientClass->m_pNetworkName).rfind("CWeapon") != -1)
			drawList->AddText({ w2s.x, w2s.y }, ImColor(204, 27, 207), pEntityClientClass->m_pNetworkName + 7);
		else if (std::string(pEntityClientClass->m_pNetworkName).rfind("CAK47") != -1 || std::string(pEntityClientClass->m_pNetworkName).rfind("CDEagle") != -1 || std::string(pEntityClientClass->m_pNetworkName).rfind("CC4") != -1)
			drawList->AddText({ w2s.x, w2s.y }, ImColor(204, 27, 207), pEntityClientClass->m_pNetworkName + 1);
		else if (std::string(pEntityClientClass->m_pNetworkName).rfind("CPlantedC4") != -1)
			drawList->AddText({ w2s.x, w2s.y }, ImColor(204, 27, 207), std::to_string(pEntity->c4BlowTime()).c_str());
		else if (std::string(pEntityClientClass->m_pNetworkName).rfind("CSmokeGrenade") != -1)
			drawList->AddText({ w2s.x, w2s.y }, ImColor(204, 27, 207), "** SMOKE GRENADE **");
	}
}

void ESP::Render()
{
	for (unsigned long i = 0; i < interfaces.ClientEntityList->GetHighestEntityIndex(); i++)
	{
		C_BaseEntity* pEntity = interfaces.ClientEntityList->GetClientEntity(i);

		if (!pEntity || i == interfaces.Engine->getLocalPlayer())
			continue;

		ClientClass* pEntityClientClass = pEntity->getClientClass();

		if (pEntityClientClass->m_ClassID == EClassIds::CBasePlayer)
			BoxEsp(i, pEntity, features.BoxEspName, features.BoxEspHealth, features.BoxEspArmor);
		//else DrawMisc(pEntity, pEntityClientClass);
	}
}
