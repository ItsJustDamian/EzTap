#pragma once
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "valve_sdk/includes.hpp"
#include "Memory.hpp"

class IEngineClient;
class IClientEntityList;
class ICvar;
class IBaseClientDLL;
class IEngineTrace;
class IGameUI;
class IGameEventManager2;
class IMaterialSystem;
class IInputSystem;
class IPrediction;
class ISurface;
class IStudioRender;
class PhysicsSurfaceProps;
class IVDebugOverlay;
class IVModelRender;
class IEngineSound;
class IClientMode;
class CGlobalVars;
class CInput;

class Interfaces
{
private:
	#define DEFINE_INTERFACE(type, name, module, ifacename, bruteforce) \
	type* name = reinterpret_cast<type*>(find(L##module, ifacename, bruteforce));
public:
	//Define interfaces here!
	//example DEFINE_INTERFACE(IClientEntityList, clientEntityList, "client.dll", "VClientEntityList")
	DEFINE_INTERFACE(IClientEntityList, ClientEntityList, "client.dll", "VClientEntityList", true);
	DEFINE_INTERFACE(ICvar, cvar, "vstdlib.dll", "VEngineCvar", true);
	DEFINE_INTERFACE(IEngineClient, Engine, "engine.dll", "VEngineClient", true);
	DEFINE_INTERFACE(IBaseClientDLL, Client, "client.dll", "VClient", true);
	DEFINE_INTERFACE(IEngineTrace, EngineTrace, "engine.dll", "EngineTraceClient", true);
	DEFINE_INTERFACE(IGameUI, GameUI, "client.dll", "GameUI", true);
	DEFINE_INTERFACE(IGameEventManager2, GameEventManager, "engine.dll", "GAMEEVENTSMANAGER002", false);
	DEFINE_INTERFACE(IMaterialSystem, MaterialSystem, "materialsystem.dll", "VMaterialSystem", true);
	DEFINE_INTERFACE(IInputSystem, InputSystem, "inputsystem.dll", "InputSystemVersion", true);
	DEFINE_INTERFACE(IPrediction, Prediction, "client.dll", "VClientPrediction", true);
	DEFINE_INTERFACE(ISurface, Surface, "vguimatsurface", "VGUI_Surface", true);
	DEFINE_INTERFACE(IStudioRender, StudioRender, "studiorender.dll", "VStudioRender", true);
	DEFINE_INTERFACE(PhysicsSurfaceProps, physicsSurfaceProps, "vphysics.dll", "VPhysicsSurfaceProps", true);
	DEFINE_INTERFACE(IVDebugOverlay, DebugOverlay, "engine.dll", "VDebugOverlay004", false);
	DEFINE_INTERFACE(IVModelRender, ModelRender, "engine.dll", "VEngineModel", true);
	DEFINE_INTERFACE(IEngineSound, EngineSound, "engine.dll", "IEngineSoundClient", true);

	IClientMode* ClientMode = **reinterpret_cast<IClientMode***>((*reinterpret_cast<uintptr_t**>(Client))[10] + 0x5);
	CGlobalVars* GlobalVars = **reinterpret_cast<CGlobalVars***>(Memory::FindPattern(reinterpret_cast<DWORD>(GetModuleHandleA("client.dll")), "A1 ? ? ? ? 5E 8B 40 10") + 1);
	CInput* Input = *reinterpret_cast<CInput**>((*reinterpret_cast<uintptr_t**>(Client))[16] + 1);

private:
#undef DEFINE_INTERFACE
	typedef void* (__cdecl* tCreateInterface)(const char* name, int* returnCode);
	static void* find(const wchar_t* module, const char* name, bool bruteforce) noexcept
	{
		tCreateInterface CreateInterface = (tCreateInterface)GetProcAddress(GetModuleHandleW(module), "CreateInterface");

		if (!CreateInterface)
			return nullptr;

		std::stringstream ss;
		void* result = nullptr;

		if (bruteforce)
		{
			for (int i = 1; i <= 100; i++)
			{
				ss.str("");
				ss << name << std::setfill('0') << std::setw(3) << i;

				result = CreateInterface(ss.str().c_str(), nullptr);

				if (result)
					break;
			}
		}
		else {
			result = CreateInterface(name, nullptr);
		}

		return result;
	}
};

inline Interfaces interfaces;