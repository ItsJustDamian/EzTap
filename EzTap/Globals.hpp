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

#define FeatureVariable(var, type, defaultValue) \
	type var = defaultValue;

class Features_t {

public:
	FeatureVariable(BoxEsp, bool, false);
	FeatureVariable(BoxEspName, bool, false);
	FeatureVariable(BoxEspHealth, bool, false);
	FeatureVariable(BoxEspArmor, bool, false);
	FeatureVariable(NoPanoramaBlur, bool, true);
	FeatureVariable(NoHands, bool, false);
	FeatureVariable(Bunnyhop, bool, false);
	FeatureVariable(Chams, bool, false);

} inline features;

inline C_BaseEntity* LocalPlayer;
inline ImDrawList* drawList;