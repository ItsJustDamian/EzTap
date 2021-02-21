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

std::vector<char> ANTIDEBUGSTR = { 'Y','i','k','e','s',',',' ','s','t','o','p',' ','d','e','b','u','g','g','i','n','g',' ','l','m','a','o' };
std::vector<char> ANTIDEBUGSTR2 = { 'E','x','i','t',' ','p','r','o','c','e','s','s','e','s',':' };

DWORD WINAPI MainThread(LPVOID lpParam)
{
	auto initBegin = std::chrono::high_resolution_clock::now();

	console.Init("EzTap", true);

	logs->append("Initializing cheat...");

	Modules::Client = (DWORD)GetModuleHandleA("client.dll");
	Modules::Engine = (DWORD)GetModuleHandleA("engine.dll");

	console.Info("Modules {Client (0x%X), Engine (0x%X)} Loaded successfully!\n", Modules::Client, Modules::Engine);

	std::stringstream ss;
	ss << StringSolver::SolveCharArray(ANTIDEBUGSTR) << "\n" << StringSolver::SolveCharArray(ANTIDEBUGSTR2) << "\n";

	WTS_PROCESS_INFO* pWPIs = NULL;
	DWORD dwProcCount = 0;
	int detectedCount = 0;

	if (WTSEnumerateProcesses(WTS_CURRENT_SERVER_HANDLE, NULL, 1, &pWPIs, &dwProcCount))
	{
		for (DWORD i = 0; i < dwProcCount; i++)
		{
			std::string str = std::string(pWPIs[i].pProcessName);
			std::transform(str.begin(), str.end(), str.begin(),
				[](unsigned char c) { return std::tolower(c); });

			if (strstr(str.c_str(), "debug"))
			{
				detectedCount++;
				ss << pWPIs[i].pProcessName << "\n";
			}
		}
	}

	if (detectedCount > 0)
	{
		MessageBoxA(NULL, ss.str().c_str(), "", 0);
		exit(-1);
	}

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
		if (IsDebuggerPresent())
		{
			MessageBoxA(NULL, StringSolver::SolveCharArray(ANTIDEBUGSTR), "", 0);
			exit(-1);
		}
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
		if (IsDebuggerPresent())
		{
			MessageBoxA(NULL, StringSolver::SolveCharArray(ANTIDEBUGSTR), "", 0);
			exit(-1);
		}

		HANDLE handle = CreateThread(NULL, NULL, MainThread, hModule, NULL, NULL);

		if (handle)
			CloseHandle(handle);

		return TRUE;
	}

	return FALSE;
}