#pragma once
#include "IInputSystem.hpp"

class CMoveData;
class C_BaseEntity;
struct CUserCmd;
class IMoveHelper;

class IGameMovement
{
public:
	VF(void, ProcessMovement, 1, (C_BaseEntity* player, BYTE* move), (this, player, move));
};

class IMoveHelper
{
public:
	VF(void, SetHost, 1, (C_BaseEntity* host), (this, host));
};

class IPrediction
{
public:
	VF(void, SetupMove, 20, (C_BaseEntity* player, CUserCmd* cmd, IMoveHelper* helper, BYTE* move), (this, player, cmd, helper, move));
	VF(void, FinishMove, 21, (C_BaseEntity* player, CUserCmd* cmd, BYTE* move), (this, player, cmd, move));
};