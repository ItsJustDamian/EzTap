#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include "Interfaces.hpp"
#include "Console.hpp"
#include "lua/GameEvents.hpp"
#include "Logger.hpp"
#include <WtsApi32.h>
#pragma comment(lib, "WtsApi32.lib")

DWORD WINAPI MainThread(LPVOID lpParam)
{
	auto initBegin = std::chrono::high_resolution_clock::now();

	console.Init("EzTap", true);

	logs->append("Initializing cheat...");

	Modules::Client = (DWORD)GetModuleHandleA("client.dll");
	Modules::Engine = (DWORD)GetModuleHandleA("engine.dll");

	console.Info("Modules {Client (0x%X), Engine (0x%X)} Loaded successfully!\n", Modules::Client, Modules::Engine);

	logs->append("Read pointers and signatures...");

	Memory::ReadPointer("client.dll", "0F 10 05 ? ? ? ? 8D 85 ? ? ? ? B9", Offsets::ViewMatrix, 0x3, 176, true);
	Memory::traceToExit = Memory::FindPattern(Modules::Client, "55 8B EC 83 EC 30 F3 0F 10 75");

	console.Info("Pointers {ViewMatrix (0x%X), TraceToExit (0x%X)} read sucessfully!\n", Offsets::ViewMatrix, Memory::traceToExit);
	logs->append("Setting up hooks...");

	if (MH_Initialize() != MH_OK)
	{
		errorLogs->append("Minhook failed!");
		console.Error("Failed to initialize minhook!\n");
		MessageBoxA(NULL, "Minhook failed to initialize!", "Error!", 0);
		exit(-1);
	}
	else {
		Hooks::Setup();
	}

	console.Info("Hooks initialized successfully!\n");
	logs->append("Loading events...");

	KillChat* kc = new KillChat();
	GameEvents* ge = new GameEvents();

	logs->append("Registering lua objects into the namespace...");

	g_pLuaEngine->RegisterLuaObjects();

	Sleep(1000);

	g_pLuaEngine->ExecuteString("print = function(...) local Engine = EzTap.Interfaces:GetEngine() Engine:ExecuteCmd('echo ' .. ...) end");
	//g_pLuaEngine->ExecuteString("print = function(...) EzTap.Logs.Info(...) end");

	console.Info("Registerd lua objects successfully!\n");
	logs->append("Cheat ready for use!");

	auto initEnd = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(initEnd - initBegin).count();
	console.Write("Initializiation took %ldms!\n", duration);

	//delete logs;

	while (!features.EjectCheat)
	{
		Sleep(1000);
	}

	/* cleanup Event Handlers */
	delete kc;
	delete ge;

	/* cleanup lua engine */
	delete g_pLuaEngine;
	delete DXHooks;
	delete CMHooks;
	delete FSNHooks;
	delete SNDHooks;
	delete GMEHooks;

	Hooks::Restore();
	MH_Uninitialize();

	console.Close();
	FreeLibraryAndExitThread((HMODULE)lpParam, 0);
	return 0;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		HANDLE handle = CreateThread(NULL, NULL, MainThread, hModule, NULL, NULL);

		if (handle)
			CloseHandle(handle);

		return TRUE;
	}

	return FALSE;
}