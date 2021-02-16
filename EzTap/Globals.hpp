#pragma once
#include <iostream>
#include "valve_sdk/Classes/C_BaseEntity.hpp"

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx9.h"
#include "../ImGui/imgui_impl_win32.h"
#include "lua/ExportedFunctions.hpp"

#include <chrono>

class C_BaseEntity;

namespace Modules
{
	inline DWORD Client, Engine;
}

namespace Offsets
{
	inline DWORD ViewMatrix;
}

#define FV(var, type, defaultValue) \
	type var = defaultValue

class Features_t {

public:
	FV(BoxEsp, bool, false);
	FV(BoxEspName, bool, false);
	FV(BoxEspHealth, bool, false);
	FV(BoxEspArmor, bool, false);
	FV(NoPanoramaBlur, bool, true);
	FV(NoHands, bool, false);
	FV(Bunnyhop, bool, false);
	FV(Chams, bool, false);
	FV(Chams_Arms, bool, false);
	FV(Chams_Arms_Wireframe, bool, false);
	FV(Aimbot, bool, false);
	FV(Autowall, bool, false);
	FV(Aimbot_Silent, bool, false);
	FV(Aimbot_AutoFire, bool, false);
	FV(Aimbot_AutoScope, bool, false);
	FV(ForceCrosshair, bool, false);
	FV(RankReveal, bool, false);
	FV(NoFlash, bool, false);
	FV(Legit_Triggerbot, bool, false);
	FV(Legit_RadarHack, bool, false);
	FV(AutoAccept, bool, false);
	FV(ClanTag, bool, false);
	FV(TrashTalk, bool, false);
	FV(FakeLag, bool, false);
	FV(FakeLag_Adaptive, bool, false);
	FV(AntiAim, bool, false);

	FV(AutowallMinDmg, int, 10);
	FV(Aimbot_FOV, float, 20);
	FV(Aimbot_Bone, int, 8);
	FV(FOV, int, 90);
	FV(TrashTalkType, int, 0);
	FV(FakeLag_value, int, 9);

	FV(EjectCheat, bool, false);

} inline features;

#undef FV

inline C_BaseEntity* LocalPlayer;
inline ImDrawList* drawList;
inline ImFont* IconFont;

inline int result1 = 0;
inline int result2 = 0;

inline bool MELikEYCheeSE = false;