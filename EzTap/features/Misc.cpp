#include "Misc.hpp"

void Misc::Bunnyhop(CUserCmd* pCmd)
{
	if (!LocalPlayer || !LocalPlayer->isAlive())
		return;

	static auto wasLastTimeOnGround{ LocalPlayer->flags() & 1 };
	
	if (!(LocalPlayer->flags() & 1) && LocalPlayer->moveType() != MoveType::LADDER && !wasLastTimeOnGround)
		pCmd->buttons &= ~IN_JUMP;

	wasLastTimeOnGround = LocalPlayer->flags() & 1;
}

void Misc::ForceCrosshair()
{
	static ConVar *crossVar1, *crossVar2;

	if (!crossVar1 || !crossVar2)
	{
		crossVar1 = interfaces.cvar->findVar("weapon_debug_spread_show");
		crossVar2 = interfaces.cvar->findVar("weapon_debug_spread_gap");
	}

	if (features.ForceCrosshair && crossVar1->getInt() != 1)
	{
		crossVar1->setValue(1);
		crossVar2->setValue(2);
	}
	else if (!features.ForceCrosshair && crossVar1->getInt() != 0)
		crossVar1->setValue(0);
}

void Misc::RankReveal()
{
	interfaces.Client->dispatchUserMessage(50, 0, 0, nullptr);
}

void Misc::NoFlash(bool enabled)
{
	LocalPlayer->SetflashAlpha((enabled ? 0.f : 255.f));
}

void Misc::ClanTag()
{
	float time = interfaces.GlobalVars->realtime;
	std::string clantag = "PETERHOOK ";
	std::string curClantag;
	for (int i = 0; i < clantag.length(); i++) {
		int curLetter = i + (int)(time * 2); // Rate is 2 characters a second
		curClantag += clantag[curLetter % clantag.length()]; // Current char is wrapped to clantag length so it loops
	}

	Utils::SetClantag(curClantag.c_str());
}
