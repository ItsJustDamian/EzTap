#pragma once
#include "../valve_sdk/includes.hpp"
#include "../valve_sdk/Interfaces/IEngineClient.hpp"
#include <vector>
#include "LuaEngine.hpp"

class ExportedEngine;
class ExportedUtils;
class ExportedDrawLib;
class ExportedClientEntityList;
class ExportedEntity;
class ExportedVector;
class ExportedGameUI;
class ExportedGameEvent;

class IEngineClient;
class IClientEntityList;
class C_BaseEntity;
class IGameUI;
class IGameEvent;

/* EXPORTED INTERFACES */
class ExportedInterfaces
{
public:
	ExportedEngine GetEngine();
	ExportedUtils GetUtils();
	ExportedDrawLib GetDrawLibrary();
	ExportedClientEntityList GetClientEntityList();
	ExportedGameUI GetGameUI();
};

/* EXPORTED ENGINE */
class ExportedEngine
{
public:
	ExportedEngine(IEngineClient* engine) : Engine(engine) {};

	void ExecuteCommand(const char* str);
	int GetLocalPlayer();
	int GetMaxClients();
	bool IsInGame();

	//ExportedVector WorldToScreen(ExportedPlayer player, int boneID);
	ExportedVector WorldToScreen(ExportedEntity player);
private:
	IEngineClient* Engine;
};

/* EXPORTED DRAW LIBRARY */
class ExportedDrawLib
{
public:
	void DrawText(const char* str, float x, float y, int r = 255, int g = 255, int b = 255);
	void DrawFilledRect(float x, float y, float w, float h, float rounding = 0.f, int r = 255, int g = 255, int b = 255, int a = 255);
	void DrawRect(float x, float y, float w, float h, float rounding = 0.f, int r = 255, int g = 255, int b = 255, int a = 255);

	void BeginGUI(const char* name);
	void GUICheckbox(const char * name, bool boolean);
	void EndGUI();
};

/* EXPORTED UTILS */
class ExportedUtils
{
public:
	void SetClantag(const char* tag);
};

/* EXPORTED ENTITY LIST */
class ExportedClientEntityList
{
public:
	ExportedClientEntityList(IClientEntityList* entityList) : clientEntityList(entityList) {};
	int GetHighestEntityIndex();
	ExportedEntity GetPlayer(int id);

private:
	IClientEntityList* clientEntityList;
};

class ExportedEntity
{
public:
	ExportedEntity(C_BaseEntity* Entity) : entity(Entity) {};
	int GetHealth();
	int GetArmor();
	int GetTeamNum();
	int GetShotsFired();
	int GetNextPrimaryAttack();
	int GetNextAttack();
	int GetGlowIndex();
	int GetCorsshairIndex();
	ExportedVector GetBonePos(int id);
	ExportedVector GetOrigin();

	bool IsValid();
	bool HasHelmet();
	bool HasDefuser();
	bool IsDormant();
	bool IsFlashed();
	bool IsPlayer();

	void SetSpotted(bool value);
	void SetFlashMaxAlpha(float value);
	
private:
	C_BaseEntity * entity;
};

class ExportedVector
{
public:
	int GetX();
	int GetY();
	int GetZ();
	void SetX(float v);
	void SetY(float v);
	void SetZ(float v);

private:
	float x, y, z;
};

class ExportedGameUI
{
public:
	ExportedGameUI(IGameUI* gameUI) : GameUI(gameUI) {};
	void ShowMessageBox(const char* title, const char* message);

private:
	IGameUI* GameUI;
};

class ExportedGameEvent
{
public:
	ExportedGameEvent(IGameEvent* pEvent) : GameEvent(pEvent) {};

	const char* GetName();
	bool IsEmpty(const char * keyname);

	bool GetBool(const char* keyname);
	int GetInt(const char* keyname);
	float GetFloat(const char* keyname);
	const char* GetString(const char* keyname);

	void SetBool(const char* keyname, bool v);
	void SetInt(const char* keyname, int v);
	void SetFloat(const char* keyname, float v);
	void SetString(const char* keyname, const char* v);

private:
	IGameEvent* GameEvent;
};

#define LUAHooksExecWithArgs(hookClass, args) \
	for (luabridge::LuaRef func : hookClass->funcList) { \
		func##args; \
	}

class LUAHooks
{
public:
	void RegisterCallback(const char* identifier, luabridge::LuaRef func);
	void TerminateCallback(const char * identifier);
	void ExecuteAllCallbacks();

public:
	std::vector<std::string> identList;
	std::vector<luabridge::LuaRef> funcList;

	int FindCallbackByIdentifier(const char * identifier);
};

inline LUAHooks * DXHooks = new LUAHooks();
inline LUAHooks * CMHooks = new LUAHooks();
inline LUAHooks * FSNHooks = new LUAHooks();
inline LUAHooks * SNDHooks = new LUAHooks();
inline LUAHooks * GMEHooks = new LUAHooks();