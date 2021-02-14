#include "RageBot.hpp"

void RageBot::AntiAim(CUserCmd* pCmd, bool & bSendPackets)
{
	if (pCmd->buttons & IN_USE || pCmd->buttons & IN_ATTACK)
		return;

	static bool ChokeYourDaddy;
	if (ChokeYourDaddy)
	{
		bSendPackets = true;
		pCmd->viewangles.y = LocalPlayer->getMaxDesyncAngle();
		pCmd->viewangles.x = 89;
	}
	else {
		bSendPackets = false;
	}
	ChokeYourDaddy ^= true;
}
