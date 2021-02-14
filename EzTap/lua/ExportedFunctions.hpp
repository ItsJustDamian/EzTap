#pragma once
#include "../valve_sdk/includes.hpp"
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
class ExportedConvar;
class ExportedCvar;
class ExportedPlayerInfo;
class ExportedMaterialSystem;
class ExportedUserCmd;

class IEngineClient;
class IClientEntityList;
class C_BaseEntity;
class IGameUI;
class IGameEvent;
class ICvar;
class ConVar;
class IMaterialSystem;
class IMaterial;
struct CUserCmd;

struct playerInfo
{
	int64_t __pad0;
	union {
		int64_t xuid;
		struct {
			int xuidlow;
			int xuidhigh;
		};
	};
	char name[128];
	int userid;
	char guid[33]; // steam id
	unsigned int friendsid;
	char friendsname[128];
	bool fakeplayer;
	bool ishltv;
	unsigned int customfiles[4];
	unsigned char filesdownloaded;
};

/* EXPORTED INTERFACES */
class ExportedInterfaces
{
public:
	ExportedEngine GetEngine();
	ExportedUtils GetUtils();
	ExportedDrawLib GetDrawLibrary();
	ExportedClientEntityList GetClientEntityList();
	ExportedGameUI GetGameUI();
	ExportedCvar GetCvar();
	ExportedMaterialSystem GetMaterialSystem();
};

/* EXPORTED ENGINE */
class ExportedEngine
{
public:
	ExportedEngine(IEngineClient* engine) : Engine(engine) {};

	void ExecuteCommand(const char* str);
	void ExecuteCommandUnrestricted(const char* str);
	int GetLocalPlayer();
	int GetPlayerIDByUserID(int id);
	int GetMaxClients();
	bool IsInGame();
	void SetViewAngles(float x, float y);

	ExportedPlayerInfo GetPlayerInfo(int id);
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

	bool BeginGUI(const char* name);
	void GUICheckbox(const char * name, bool boolean);
	bool GUIButton(const char * label);
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
	ExportedVector() {}
	ExportedVector(float ix, float iy, float iz)
	{
		x = ix;
		y = iy;
		z = iz;
	}
	ExportedVector(Vector vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

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

class ExportedConvar
{
public:
	ExportedConvar(ConVar* ConVar) : convar(ConVar) {};
	float GetFloat();
	float GetInt();
	void SetString(const char * v);
	void SetFloat(float v);
	void SetInt(int v);

private:
	ConVar* convar;
};

class ExportedCvar
{
public:
	ExportedCvar(ICvar* cVar) : cvar(cVar) {};
	ExportedConvar FindConvar(const char * name);

private:
	ICvar* cvar;
};

class ExportedPlayerInfo
{
public:
	ExportedPlayerInfo(playerInfo plInfo) : pInfo(plInfo) {};
	const char* GetName();
	int GetUserID();
	const char* GetSteamID();
	bool isHLTV();

private:
	playerInfo pInfo;
};

class ExportedMaterialSystem
{
public:
	ExportedMaterialSystem(IMaterialSystem* matSystem) : materialSystem(matSystem) {};
	IMaterial* CreateMaterial(const char* pMaterialName);
	IMaterial* FindMaterial(const char * pMaterialName, const char * pMaterialGroup);

private:
	IMaterialSystem* materialSystem;
};

class ExportedLogs
{
public:
	void Info(const char* msg);
	void Ok(const char* msg);
	void Error(const char* msg);
	void Warning(const char* msg);
};

class ExportedUserCmd
{
public:
	ExportedUserCmd(CUserCmd* uCmd) : pCmd(uCmd) {}

	int Get_command_number();
	int Get_tick_count();
	ExportedVector Get_ViewAngles();
	ExportedVector Get_AimDirection();
	float Get_forwardMove();
	float Get_sideMove();
	float Get_upMove();
	int Get_buttons();
	ExportedVector Get_HeadAngles();
	ExportedVector Get_HeadOffset();

	void Set_ViewAngles(float x, float y);
	void Set_AimDirection(float x, float y);
private:
	CUserCmd* pCmd;
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