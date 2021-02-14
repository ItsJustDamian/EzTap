#include "ExportedFunctions.hpp"

ExportedEngine ExportedInterfaces::GetEngine()
{
	static ExportedEngine engine(interfaces.Engine);
	return engine;
}

ExportedUtils ExportedInterfaces::GetUtils()
{
	static ExportedUtils utils;
	return utils;
}

ExportedDrawLib ExportedInterfaces::GetDrawLibrary()
{
	static ExportedDrawLib dlib;
	return dlib;
}

ExportedClientEntityList ExportedInterfaces::GetClientEntityList()
{
	static ExportedClientEntityList elist(interfaces.ClientEntityList);
	return elist;
}

ExportedGameUI ExportedInterfaces::GetGameUI()
{
	static ExportedGameUI gameUI(interfaces.GameUI);
	return gameUI;
}

ExportedCvar ExportedInterfaces::GetCvar()
{
	static ExportedCvar cvar(interfaces.cvar);
	return cvar;
}

ExportedMaterialSystem ExportedInterfaces::GetMaterialSystem()
{
	static ExportedMaterialSystem matSys(interfaces.MaterialSystem);
	return matSys;
}

void ExportedEngine::ExecuteCommand(const char* str)
{
	Engine->executeClientCmd(str);
}

void ExportedEngine::ExecuteCommandUnrestricted(const char* str)
{
	Engine->executeClientCmd_Unrestricted(str);
}

int ExportedEngine::GetLocalPlayer()
{
	return Engine->getLocalPlayer();
}

int ExportedEngine::GetPlayerIDByUserID(int id)
{
	return Engine->getPlayerForUserID(id);
}

int ExportedEngine::GetMaxClients()
{
	return Engine->getMaxClients();
}

bool ExportedEngine::IsInGame()
{
	return Engine->isIngame();
}

void ExportedEngine::SetViewAngles(float x, float y)
{
	static Vector vec;
	vec = Vector(x, y, 0);
	vec.Clamp();
	interfaces.Engine->setViewAngles(&vec);
}

ExportedPlayerInfo ExportedEngine::GetPlayerInfo(int id)
{
	playerInfo pInfo;
	if (interfaces.Engine->getPlayerInfo(id, &pInfo))
		return ExportedPlayerInfo(pInfo);

	return ExportedPlayerInfo(pInfo);
}

//ExportedVector ExportedEngine::WorldToScreen(ExportedPlayer player, int boneID)
//{
//	ExportedVector vec = ExportedVector();
//	ExportedVector bonePos = player.GetBonePos(boneID);
//
//	Vector vecBonePos = Vector(bonePos.GetX(), bonePos.GetY(), bonePos.GetZ());
//	Vector w2s;
//	if (interfaces.Engine->WorldToScreen(vecBonePos, w2s))
//	{
//		vec.SetX(w2s.x);
//		vec.SetY(w2s.y);
//		vec.SetZ(w2s.z);
//	}
//
//	return vec;
//}

ExportedVector ExportedEngine::WorldToScreen(ExportedEntity player)
{
	ExportedVector vec = ExportedVector();
	ExportedVector bonePos = player.GetOrigin();

	Vector vecBonePos = Vector(bonePos.GetX(), bonePos.GetY(), bonePos.GetZ());
	Vector w2s;
	if (interfaces.Engine->WorldToScreen(vecBonePos, w2s))
	{
		vec.SetX(w2s.x);
		vec.SetY(w2s.y);
		vec.SetZ(w2s.z);
	}

	return vec;
}

void ExportedDrawLib::DrawText(const char* str, float x, float y, int r, int g, int b)
{
	drawList->AddText({ x, y }, ImColor(r, g, b), str);
}

void ExportedDrawLib::DrawFilledRect(float x, float y, float w, float h, float rounding, int r, int g, int b, int a)
{
	drawList->AddRectFilled({ x, y }, { x + w, y + h }, ImColor(r, g, b, a), rounding);
}

void ExportedDrawLib::DrawRect(float x, float y, float w, float h, float rounding, int r, int g, int b, int a)
{
	drawList->AddRect({ x, y }, { x + w, y + h }, ImColor(r, g, b, a), rounding);
}

bool ExportedDrawLib::BeginGUI(const char* name)
{
	if(menuOpen)
		ImGui::Begin(name, 0, ImGuiWindowFlags_NoSavedSettings);

	return menuOpen;
}

void ExportedDrawLib::GUICheckbox(const char* name, bool boolean)
{
	if (menuOpen)
		ImGui::FancyCheckbox(name, &boolean);
}

bool ExportedDrawLib::GUIButton(const char* label)
{
	if (menuOpen)
		return ImGui::Button(label);
	else
		return false;
}

void ExportedDrawLib::EndGUI()
{
	if (menuOpen)
		ImGui::End();
}

void ExportedUtils::SetClantag(const char* tag)
{
	Utils::SetClantag(tag);
}

int ExportedClientEntityList::GetHighestEntityIndex()
{
	return clientEntityList->GetHighestEntityIndex();
}

ExportedEntity ExportedClientEntityList::GetPlayer(int id)
{
	C_BaseEntity* playerEntity = interfaces.ClientEntityList->GetClientEntity(id);
	ExportedEntity player(playerEntity);
	return player;
}

int ExportedEntity::GetHealth()
{
	if (entity)
		return entity->oHealth();
	else
		return 0;
}

int ExportedEntity::GetArmor()
{
	return entity->armor();
}

int ExportedEntity::GetTeamNum()
{
	return entity->team();
}

int ExportedEntity::GetShotsFired()
{
	return entity->shotsFired();
}

int ExportedEntity::GetNextPrimaryAttack()
{
	return entity->nextPrimaryAttack();
}

int ExportedEntity::GetNextAttack()
{
	return entity->nextAttack();
}

int ExportedEntity::GetGlowIndex()
{
	return entity->GlowIndex();
}

int ExportedEntity::GetCorsshairIndex()
{
	return entity->CrosshairId();
}

ExportedVector ExportedEntity::GetBonePos(int id)
{
	ExportedVector vec;
	Vector pos = entity->getBonePosition(id);

	vec.SetX(pos.x);
	vec.SetY(pos.y);
	vec.SetZ(pos.z);

	return vec;
}

ExportedVector ExportedEntity::GetOrigin()
{
	ExportedVector vec;
	Vector pos = entity->origin();

	vec.SetX(pos.x);
	vec.SetY(pos.y);
	vec.SetZ(pos.z);

	return vec;
}

bool ExportedEntity::IsValid()
{
	return entity->isValid();
}

bool ExportedEntity::HasHelmet()
{
	return entity->hasHelmet();
}

bool ExportedEntity::HasDefuser()
{
	return entity->hasDefuser();
}

bool ExportedEntity::IsDormant()
{
	return entity->oIsDormant();
}

bool ExportedEntity::IsFlashed()
{
	return entity->isFlashed();
}

bool ExportedEntity::IsPlayer()
{
	return entity->isPlayer2();
}

void ExportedEntity::SetSpotted(bool value)
{
	entity->Setspotted(value);
}

void ExportedEntity::SetFlashMaxAlpha(float value)
{
	entity->SetflashAlpha(value);
}

int ExportedVector::GetX()
{
	return x;
}

int ExportedVector::GetY()
{
	return y;
}

int ExportedVector::GetZ()
{
	return z;
}

void ExportedVector::SetX(float v)
{
	x = v;
}

void ExportedVector::SetY(float v)
{
	y = v;
}

void ExportedVector::SetZ(float v)
{
	z = v;
}

void LUAHooks::RegisterCallback(const char* identifier, luabridge::LuaRef func)
{
	console.Debug("Callback Identifier '%s' Registerd!\n", identifier);
	
	identList.push_back(identifier);
	funcList.push_back(func);
}

void LUAHooks::TerminateCallback(const char* identifier)
{
	int pos = FindCallbackByIdentifier(identifier);

	if (pos != -1)
	{
		identList.erase(identList.begin() + pos);
		funcList.erase(funcList.begin() + pos);
	}
	else
		console.Error("Failed to locate callback '%s'!\n", identifier);

}

void LUAHooks::ExecuteAllCallbacks()
{
	for (luabridge::LuaRef func : funcList)
		func();
}

int LUAHooks::FindCallbackByIdentifier(const char* identifier)
{
	for (int i = 0; i < identList.size(); i++)
	{
		std::string ident = identList.at(i);
		console.Debug("Found callback '%s'\n", ident.c_str());
		if (!strcmp(identifier, ident.c_str()))
			return i;
	}

	return -1;
}

void ExportedGameUI::ShowMessageBox(const char* title, const char* message)
{
	static char titleBuf[512];
	sprintf(titleBuf, "[EzTap - Lua]: %s", title);
	interfaces.GameUI->createCmdMsgBox(titleBuf, message);
}

const char* ExportedGameEvent::GetName()
{
	return GameEvent->GetName();
}

bool ExportedGameEvent::IsEmpty(const char* keyname)
{
	return GameEvent->IsEmpty(keyname);
}

bool ExportedGameEvent::GetBool(const char* keyname)
{
	return GameEvent->GetBool(keyname);
}

int ExportedGameEvent::GetInt(const char* keyname)
{
	return GameEvent->GetInt(keyname, -1);
}

float ExportedGameEvent::GetFloat(const char* keyname)
{
	return GameEvent->GetFloat(keyname, -1);
}

const char* ExportedGameEvent::GetString(const char* keyname)
{
	return GameEvent->GetString(keyname);
}

void ExportedGameEvent::SetBool(const char* keyname, bool v)
{
	GameEvent->SetBool(keyname, v);
}

void ExportedGameEvent::SetInt(const char* keyname, int v)
{
	GameEvent->SetInt(keyname, v);
}

void ExportedGameEvent::SetFloat(const char* keyname, float v)
{
	GameEvent->SetFloat(keyname, v);
}

void ExportedGameEvent::SetString(const char* keyname, const char* v)
{
	GameEvent->SetString(keyname, v);
}

float ExportedConvar::GetFloat()
{
	return convar->getFloat();
}

float ExportedConvar::GetInt()
{
	return convar->getInt();
}

void ExportedConvar::SetString(const char* v)
{
	convar->setValue(v);
}

void ExportedConvar::SetFloat(float v)
{
	convar->setValue(v);
}

void ExportedConvar::SetInt(int v)
{
	convar->setValue(v);
}

ExportedConvar ExportedCvar::FindConvar(const char* name)
{
	ConVar* var = interfaces.cvar->findVar(name);
	return ExportedConvar(var);
}

const char* ExportedPlayerInfo::GetName()
{
	return pInfo.name;
}

int ExportedPlayerInfo::GetUserID()
{
	return pInfo.userid;
}

const char* ExportedPlayerInfo::GetSteamID()
{
	return pInfo.guid;
}

bool ExportedPlayerInfo::isHLTV()
{
	return pInfo.ishltv;
}

IMaterial* ExportedMaterialSystem::CreateMaterial(const char* pMaterialName)
{
	return materialSystem->CreateMaterial(pMaterialName, nullptr);
}

IMaterial* ExportedMaterialSystem::FindMaterial(const char* pMaterialName, const char* pMaterialGroup)
{
	return materialSystem->FindMaterial(pMaterialName, pMaterialGroup);
}

void ExportedLogs::Info(const char * msg)
{
	static char buf[1024];
	sprintf(buf, "<LUA> %s\n", msg);
	console.Write(buf);
}

void ExportedLogs::Ok(const char* msg)
{
	static char buf[1024];
	sprintf(buf, "<LUA> %s\n", msg);
	console.Info(buf);
}

void ExportedLogs::Error(const char* msg)
{
	static char buf[1024];
	sprintf(buf, "<LUA> %s\n", msg);
	console.Error(buf);
}

void ExportedLogs::Warning(const char* msg)
{
	static char buf[1024];
	sprintf(buf, "<LUA> %s\n", msg);
	console.Warning(buf);
}

int ExportedUserCmd::Get_command_number()
{
	return pCmd->command_number;
}

int ExportedUserCmd::Get_tick_count()
{
	return pCmd->tick_count;
}

ExportedVector ExportedUserCmd::Get_ViewAngles()
{
	return ExportedVector(pCmd->viewangles);
}

ExportedVector ExportedUserCmd::Get_AimDirection()
{
	return ExportedVector(pCmd->aimdirection);
}

float ExportedUserCmd::Get_forwardMove()
{
	return pCmd->forwardmove;
}

float ExportedUserCmd::Get_sideMove()
{
	return pCmd->sidemove;
}

float ExportedUserCmd::Get_upMove()
{
	return pCmd->upmove;
}

int ExportedUserCmd::Get_buttons()
{
	return pCmd->buttons;
}

ExportedVector ExportedUserCmd::Get_HeadAngles()
{
	return ExportedVector(pCmd->headangles);
}

ExportedVector ExportedUserCmd::Get_HeadOffset()
{
	return ExportedVector(pCmd->headoffset);
}

void ExportedUserCmd::Set_ViewAngles(float x, float y)
{
	Vector vec = Vector(x, y, 0);
	vec.Clamp();

	pCmd->viewangles = vec;
}

void ExportedUserCmd::Set_AimDirection(float x, float y)
{
	Vector vec = Vector(x, y, 0);
	vec.Clamp();

	pCmd->aimdirection = vec;
}
