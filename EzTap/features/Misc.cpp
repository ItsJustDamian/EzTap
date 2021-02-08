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
