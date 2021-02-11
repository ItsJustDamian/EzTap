#include <Windows.h>
#include <iostream>
#include "Interfaces.hpp"
#include "Console.hpp"
#include "lua/GameEvents.hpp"
#include "Logger.hpp"

DWORD WINAPI MainThread(LPVOID lpParam)
{
	console.Init("EzTap", true);

	logs->append("Initializing cheat...");

	Modules::Client = (DWORD)GetModuleHandleA("client.dll");
	Modules::Engine = (DWORD)GetModuleHandleA("engine.dll");

	logs->append("Read pointers and signatures...");

	Memory::ReadPointer("client.dll", "0F 10 05 ? ? ? ? 8D 85 ? ? ? ? B9", Offsets::ViewMatrix, 0x3, 176, true);
	Memory::traceToExit = Memory::FindPattern(Modules::Client, "55 8B EC 83 EC 30 F3 0F 10 75");

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

	logs->append("Loading events...");

	KillChat* kc = new KillChat();
	GameEvents* ge = new GameEvents();

	logs->append("Registering lua objects into the namespace...");

	g_pLuaEngine->RegisterLuaObjects();

	Sleep(1000);

	g_pLuaEngine->ExecuteString("print = function(...) local Engine = EzTap.Interfaces:GetEngine() Engine:ExecuteCmd('echo ' .. ...) end");

	logs->append("Cheat ready for use!");

	//delete logs;

	while (true)
	{
		
		Sleep(1000);
	}

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