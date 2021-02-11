#pragma once
#include <iostream>
#include <string>
#include <d3d9.h>
#include <d3dx9.h>
#include "MinHook.h"
#include "Memory.hpp"
#include "Render.hpp"
#include "Gui.hpp"
#include "Utils.hpp"
#include "lua/LuaEngine.hpp"
#include "Logger.hpp"

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx9.h"
#include "../ImGui/imgui_impl_win32.h"

#include "features/ESP.hpp"
#include "features/Chams.hpp"
#include "features/Misc.hpp"
#include "features/Aimbot.hpp"
#include "features/LegitBot.hpp"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "libMinHook.x86.lib")

class IMatRenderContext;

inline bool menuOpen = false;

static auto GetVFunc(void* base, unsigned int index)
{
	return static_cast<uintptr_t>((*reinterpret_cast<int**>(base))[index]);
}

template<typename T>
static T HookFunction(void* base, unsigned int index, void* func)
{
	void* oldFunction = nullptr;

	MH_CreateHook(reinterpret_cast<void*>(GetVFunc(base, index)), func, &oldFunction);
	MH_EnableHook(MH_ALL_HOOKS);

	if (oldFunction == nullptr)
		console.Error("Minhook returned nullptr function!\n");

	return reinterpret_cast<T>(oldFunction);
}

namespace Hooks
{
	void Setup();
	void Restore();
}