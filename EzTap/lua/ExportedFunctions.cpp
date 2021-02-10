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

void ExportedEngine::ExecuteCommand(const char* str)
{
	Engine->executeClientCmd(str);
}

int ExportedEngine::GetLocalPlayer()
{
	return Engine->getLocalPlayer();
}

int ExportedEngine::GetMaxClients()
{
	return Engine->getMaxClients();
}

bool ExportedEngine::IsInGame()
{
	return Engine->isIngame();
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

void ExportedDrawLib::BeginGUI(const char* name)
{
	if(menuOpen)
		ImGui::Begin(name, 0, ImGuiWindowFlags_NoSavedSettings);
}

void ExportedDrawLib::GUICheckbox(const char* name, bool boolean)
{
	if (menuOpen)
		ImGui::FancyCheckbox(name, &boolean);
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
