#pragma once
#include <iostream>
#include "../Classes/matrix3x4.hpp"
#include "../../VirtualFunction.hpp"
#include "../../Globals.hpp"

//struct playerInfo
//{
//	int64_t __pad0;
//	union {
//		int64_t xuid;
//		struct {
//			int xuidlow;
//			int xuidhigh;
//		};
//	};
//	char name[128];
//	int userid;
//	char guid[33]; // steam id
//	unsigned int friendsid;
//	char friendsname[128];
//	bool fakeplayer;
//	bool ishltv;
//	unsigned int customfiles[4];
//	unsigned char filesdownloaded;
//};

class IEngineClient
{
public:
	VF(void*, getViewMatrix, 36, (), (this));
	VF(int, getMaxClients, 20, (), (this));
	VF(void, getScreenSize, 5, (int* width, int* height), (this, width, height));
	VF(int, getLocalPlayer, 12, (), (this));
	VF(bool, getPlayerInfo, 8, (int id, void* plrinfo), (this, id, plrinfo));
	VF(int, getViewAngles, 18, (Vector* angles), (this, angles));
	VF(void, setViewAngles, 19, (Vector* angles), (this, angles));
	VF(bool, isIngame, 26, (), (this));
	VF(matrix3x4&, worldToScreenMatrix, 37, (), (this));
	VF(void, executeClientCmd, 108, (const char* szCmdString), (this, szCmdString));
	VF(void, executeClientCmd_Unrestricted, 114, (const char* szCmdString), (this, szCmdString));
	VF(const char*, getLevelName, 52, (), (this));
	VF(const char*, getLevelNameShort, 53, (), (this));
	VF(bool, isTakingScreenshot, 92, (), (this));
	VF(int, getPlayerForUserID, 9, (int uid), (this, uid));

	Vector CalcAngle(Vector src, Vector dst);
	void VectorAngles(Vector& forward, Vector& angles);
	bool ScreenTransform(Vector in, Vector& out);
	bool WorldToScreen(Vector in, Vector& out);
};