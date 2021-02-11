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
	int time = interfaces.GlobalVars->realtime;

	std::string curClantag;
	switch (time % 26)
	{
		case 0: { Utils::SetClantag("............"); } break;
		case 1: { Utils::SetClantag("E..........."); } break;
		case 2: { Utils::SetClantag("Ez.........."); } break;
		case 3: { Utils::SetClantag("EzT........."); } break;
		case 4: { Utils::SetClantag("EzTa........"); } break;
		case 5: { Utils::SetClantag("EzTap......."); } break;
		case 6: { Utils::SetClantag("EzTap......."); } break;
		case 7: { Utils::SetClantag("EzTap.O....."); } break;
		case 8: { Utils::SetClantag("EzTap.On...."); } break;
		case 9: { Utils::SetClantag("EzTap.Onl..."); } break;
		case 10: { Utils::SetClantag("EzTap.Onli.."); } break;
		case 11: { Utils::SetClantag("EzTap.Onlin."); } break;
		case 12: { Utils::SetClantag("EzTap.Online"); } break;
		case 13: { Utils::SetClantag("EzTap.Online"); } break;
		case 14: { Utils::SetClantag("EzTap.Online"); } break;
		case 15: { Utils::SetClantag(".zTap.Online"); } break;
		case 16: { Utils::SetClantag("..Tap.Online"); } break;
		case 17: { Utils::SetClantag("...ap.Online"); } break;
		case 18: { Utils::SetClantag("....p.Online"); } break;
		case 19: { Utils::SetClantag("......Online"); } break;
		case 20: { Utils::SetClantag("......Online"); } break;
		case 21: { Utils::SetClantag(".......nline"); } break;
		case 22: { Utils::SetClantag("........line"); } break;
		case 23: { Utils::SetClantag(".........ine"); } break;
		case 24: { Utils::SetClantag("..........ne"); } break;
		case 25: { Utils::SetClantag("...........e"); } break;
		case 26: { Utils::SetClantag("............"); } break;
	}
}
