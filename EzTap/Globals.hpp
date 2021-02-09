#pragma once
#include <iostream>
#include "valve_sdk/Classes/C_BaseEntity.hpp"

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx9.h"
#include "../ImGui/imgui_impl_win32.h"

class C_BaseEntity;

namespace Modules
{
	inline DWORD Client, Engine;
}

namespace Offsets
{
	inline DWORD ViewMatrix;
}

//namespace Features
//{
//	inline bool BoxEsp, BoxEspName, BoxEspHealth, BoxEspArmor, NoPanoramaBlur;
//}

#define FV(var, type, defaultValue) \
	type var = defaultValue;

class Features_t {

public:
<<<<<<< HEAD
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

	FV(AutowallMinDmg, int, 10);
	FV(Aimbot_FOV, float, 20);
	FV(Aimbot_Bone, int, 8);
	FV(FOV, int, 90);
=======
	FeatureVariable(BoxEsp, bool, false);
	FeatureVariable(BoxEspName, bool, false);
	FeatureVariable(BoxEspHealth, bool, false);
	FeatureVariable(BoxEspArmor, bool, false);
	FeatureVariable(NoPanoramaBlur, bool, true);
	FeatureVariable(NoHands, bool, false);
	FeatureVariable(Bunnyhop, bool, false);
	FeatureVariable(Chams, bool, false);
	FeatureVariable(Chams_Arms, bool, false);
	FeatureVariable(Chams_Arms_Wireframe, bool, false);
	FeatureVariable(Aimbot, bool, false);
	FeatureVariable(Autowall, bool, false);
	FeatureVariable(Aimbot_Silent, bool, false);
	FeatureVariable(Aimbot_AutoFire, bool, false);
	FeatureVariable(Aimbot_AutoScope, bool, false);
	FeatureVariable(ForceCrosshair, bool, false);
	FeatureVariable(RankReveal, bool, false);
	FeatureVariable(NoFlash, bool, false);
	FeatureVariable(Clantag, bool, false);

	FeatureVariable(AutowallMinDmg, int, 10);
	FeatureVariable(Aimbot_FOV, float, 20);
	FeatureVariable(Aimbot_Bone, int, 8);
	FeatureVariable(FOV, int, 90);
>>>>>>> 325338314b611b38e1f96f21013958df56bf8a2a

} inline features;

#undef FV

inline C_BaseEntity* LocalPlayer;
inline ImDrawList* drawList;
inline ImFont* IconFont;