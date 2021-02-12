#include "FakeLag.hpp"

int ticks = 0;
int maxTicks = 16;
void FakeLag::CreateMove(CUserCmd* pCmd, bool& bSendPackets)
{
	if (!features.FakeLag)
		return;

	if (!LocalPlayer->isValid())
		return;

	if (LocalPlayer->flags() & FL_ONGROUND && features.FakeLag_Adaptive)
		return;

	if (pCmd->buttons & IN_ATTACK)
	{
		bSendPackets = true;
		return;
	}

	if (ticks >= maxTicks)
	{
		bSendPackets = true;
		ticks = 0;
	}
	else {
		if (features.FakeLag_Adaptive)
		{
			int packetsToChoke;

			if (LocalPlayer->velocity().Length() > 0.f)
			{
				packetsToChoke = static_cast<int>((64.f / interfaces.GlobalVars->interval_per_tick) / LocalPlayer->velocity().Length()) + 1;
				if (packetsToChoke >= 15)
					packetsToChoke = 14;
				if (packetsToChoke < features.FakeLag_value)
					packetsToChoke = features.FakeLag_value;
			}
			else packetsToChoke = 0;

			bSendPackets = ticks < 16 - packetsToChoke;
		}
		else 
			bSendPackets = ticks < maxTicks - features.FakeLag_value;
	}

	ticks++;
}
