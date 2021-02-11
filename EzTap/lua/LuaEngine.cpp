#include "LuaEngine.hpp"
#include <iostream>

LuaEngine* g_pLuaEngine = new LuaEngine();

lua_State* LuaEngine::L()
{
	return m_L;
}

ExportedInterfaces gl_Interfaces;
void LuaEngine::RegisterLuaObjects()
{
	CreateDirectoryA("EzTap", NULL);
	CreateDirectoryA("EzTap\\LUA", NULL);
	CreateDirectoryA("EzTap\\CONFIGS", NULL);
	CreateDirectoryA("EzTap\\CRASH-REPORTS", NULL);
	CreateDirectoryA("EzTap\\LOGS", NULL);

	LOCKLUA();
	using namespace luabridge;

	getGlobalNamespace(m_L).beginNamespace("EzTap")

		.beginClass<ExportedInterfaces>("InterfaceClass")
		.addFunction("GetEngine", &ExportedInterfaces::GetEngine)
		.addFunction("GetUtils", &ExportedInterfaces::GetUtils)
		.addFunction("GetDrawLibrary", &ExportedInterfaces::GetDrawLibrary)
		.addFunction("GetClientEntityList", &ExportedInterfaces::GetClientEntityList)
		.addFunction("GetGameUI", &ExportedInterfaces::GetGameUI)
		.addFunction("GetCvar", &ExportedInterfaces::GetCvar)
		.endClass()

		.beginClass<ExportedEngine>("EngineInterface")
		.addFunction("GetLocalPlayer", &ExportedEngine::GetLocalPlayer)
		.addFunction("ExecuteCmd", &ExportedEngine::ExecuteCommand)
		.addFunction("ExecuteCmdUnrestricted", &ExportedEngine::ExecuteCommandUnrestricted)
		.addFunction("GetMaxClients", &ExportedEngine::GetMaxClients)
		.addFunction("IsInGame", &ExportedEngine::IsInGame)
		.addFunction("WorldToScreen", &ExportedEngine::WorldToScreen)
		.addFunction("GetPlayerIDByUserID", &ExportedEngine::GetPlayerIDByUserID)
		.addFunction("GetPlayerInfo", &ExportedEngine::GetPlayerInfo)
		.endClass()

		.beginClass<ExportedEntity>("PlayerClass")
		.addFunction("GetHealth", &ExportedEntity::GetHealth)
		.addFunction("GetArmor", &ExportedEntity::GetArmor)
		.addFunction("GetTeamNum", &ExportedEntity::GetTeamNum)
		.addFunction("GetShotsFired", &ExportedEntity::GetShotsFired)
		.addFunction("GetNextPrimaryAttack", &ExportedEntity::GetNextPrimaryAttack)
		.addFunction("GetNextAttack", &ExportedEntity::GetNextAttack)
		.addFunction("GetGlowIndex", &ExportedEntity::GetGlowIndex)
		.addFunction("GetCorsshairIndex", &ExportedEntity::GetCorsshairIndex)
		.addFunction("GetBonePosition", &ExportedEntity::GetBonePos)
		.addFunction("GetOrigin", &ExportedEntity::GetOrigin)
		.addFunction("IsValid", &ExportedEntity::IsValid)
		.addFunction("HasHelmet", &ExportedEntity::HasHelmet)
		.addFunction("HasDefuser", &ExportedEntity::HasDefuser)
		.addFunction("IsDormant", &ExportedEntity::IsDormant)
		.addFunction("IsFlashed", &ExportedEntity::IsFlashed)
		.addFunction("IsPlayer", &ExportedEntity::IsPlayer)
		.addFunction("SetSpotted", &ExportedEntity::SetSpotted)
		.addFunction("SetFlashMaxAlpha", &ExportedEntity::SetFlashMaxAlpha)
		.endClass()

		.beginClass<ExportedUtils>("MiscClass")
		.addFunction("SetClantag", &ExportedUtils::SetClantag)
		.endClass()

		.beginClass<ExportedDrawLib>("DrawLibraryClass")
		.addFunction("DrawText", &ExportedDrawLib::DrawTextA)
		.addFunction("DrawFilledRect", &ExportedDrawLib::DrawFilledRect)
		.addFunction("DrawRect", &ExportedDrawLib::DrawRect)
		.addFunction("BeginGUI", &ExportedDrawLib::BeginGUI)
		.addFunction("GUICheckbox", &ExportedDrawLib::GUICheckbox)
		.addFunction("GUIButton", &ExportedDrawLib::GUIButton)
		.addFunction("EndGUI", &ExportedDrawLib::EndGUI)
		.endClass()

		.beginClass<ExportedClientEntityList>("ClientEntityListClass")
		.addFunction("GetHighestEntityIndex", &ExportedClientEntityList::GetHighestEntityIndex)
		.addFunction("GetPlayer", &ExportedClientEntityList::GetPlayer)
		.endClass()

		.beginClass<ExportedVector>("VectorClass")
		.addFunction("GetX", &ExportedVector::GetX)
		.addFunction("GetY", &ExportedVector::GetY)
		.addFunction("GetZ", &ExportedVector::GetZ)
		.addFunction("SetX", &ExportedVector::SetX)
		.addFunction("SetY", &ExportedVector::SetY)
		.addFunction("SetZ", &ExportedVector::SetZ)
		.endClass()

		.beginClass<ExportedGameUI>("InterfaceGameUI")
		.addFunction("ShowMessageBox", &ExportedGameUI::ShowMessageBox)
		.endClass()

		.beginClass<ExportedGameEvent>("GameEventClass")
		.addFunction("GetName", &ExportedGameEvent::GetName)
		.addFunction("IsEmpty", &ExportedGameEvent::IsEmpty)
		.addFunction("GetBool", &ExportedGameEvent::GetBool)
		.addFunction("GetInt", &ExportedGameEvent::GetInt)
		.addFunction("GetFloat", &ExportedGameEvent::GetFloat)
		.addFunction("GetString", &ExportedGameEvent::GetString)
		.addFunction("SetBool", &ExportedGameEvent::SetBool)
		.addFunction("SetInt", &ExportedGameEvent::SetInt)
		.addFunction("SetFloat", &ExportedGameEvent::SetFloat)
		.addFunction("SetString", &ExportedGameEvent::SetString)
		.endClass()

		.beginClass<ExportedCvar>("CvarInterface")
		.addFunction("FindConvar", &ExportedCvar::FindConvar)
		.endClass()

		.beginClass<ExportedConvar>("ConvarClass")
		.addFunction("GetFloat", &ExportedConvar::GetFloat)
		.addFunction("GetInt", &ExportedConvar::GetInt)
		.addFunction("SetString", &ExportedConvar::SetString)
		.addFunction("SetFloat", &ExportedConvar::SetFloat)
		.addFunction("SetInt", &ExportedConvar::SetInt)
		.endClass()

		.beginClass<ExportedPlayerInfo>("PlayerInfoClass")
		.addFunction("GetName", &ExportedPlayerInfo::GetName)
		.addFunction("GetUserID", &ExportedPlayerInfo::GetUserID)
		.addFunction("GetSteamID", &ExportedPlayerInfo::GetSteamID)
		.addFunction("isHLTV", &ExportedPlayerInfo::isHLTV)
		.endClass()

		.beginClass<LUAHooks>("HooksClass")
		.addFunction("RegisterCallback", &LUAHooks::RegisterCallback)
		.addFunction("ExecuteAllCallbacks", &LUAHooks::ExecuteAllCallbacks)
		.addFunction("TerminateCallback", &LUAHooks::TerminateCallback)
		.endClass()

		.addVariable("Interfaces", &gl_Interfaces, false)
		.addVariable("CurTime", &interfaces.GlobalVars->curtime, false)

		.addVariable("hkDirectX", &DXHooks, false)
		.addVariable("hkCreateMove", &CMHooks, false)
		.addVariable("hkFrameStageNotify", &FSNHooks, false)
		.addVariable("hkEmitSound", &SNDHooks, false)
		.addVariable("hkGameEvents", &GMEHooks, false)

	.endNamespace();
}

void LuaEngine::report_errors(int state)
{
	if (state)
	{
		std::cerr << "ERR: " << lua_tostring(m_L, -1) << std::endl;
		console.Error("[LUA ERROR]: %s\n", lua_tostring(m_L, -1));
		lua_pop(m_L, 1); //remove error
	}
}

void LuaEngine::ExecuteFile(const char* file)
{
	if (!file || !m_L)
		return;

	int state = luaL_dofile(m_L, file);
	g_pLuaEngine->report_errors(state);
}


void LuaEngine::ExecuteString(const char* expression)
{
	if (!expression || !m_L)
	{
		std::cerr << "ERR: null expression passed to script engine!" << std::endl;
		return;
	}

	int state = luaL_dostring(m_L, expression);
	report_errors(state);
}
