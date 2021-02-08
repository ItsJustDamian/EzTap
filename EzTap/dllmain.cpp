#include <Windows.h>
#include <iostream>
#include "Interfaces.hpp"
#include "Console.hpp"

DWORD WINAPI MainThread(LPVOID lpParam)
{
	console.Init("EzTap", true);

	Modules::Client = (DWORD)GetModuleHandleA("client.dll");
	Modules::Engine = (DWORD)GetModuleHandleA("engine.dll");

	Memory::ReadPointer("client.dll", "0F 10 05 ? ? ? ? 8D 85 ? ? ? ? B9", Offsets::ViewMatrix, 0x3, 176, true);
	Memory::traceToExit = Memory::FindPattern(Modules::Client, "55 8B EC 83 EC 30 F3 0F 10 75");

	if (MH_Initialize() == MH_OK)
		Hooks::Setup();
	else
		console.Error("Failed to initialize minhook!");

	while (true)
	{

		Sleep(100);
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