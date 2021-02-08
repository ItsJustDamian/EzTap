#pragma once
#include <cstddef>
#include <algorithm>

#include "../../VirtualFunction.hpp"
#include "../../Interfaces.hpp"
#include "../Defines.hpp"
#include "matrix3x4.hpp"
#include "../../Globals.hpp"

#include "../Interfaces/IEngineClient.hpp"
#include "../Interfaces/IBaseClientDLL.hpp"

#ifndef PAD
#define PAD(size) \
private: \
    std::byte _pad_##size[size]; \
public:
#endif

//struct AnimState {
//	std::byte pad[164];
//	float duckAmount;
//	std::byte pad1[80];
//	float footSpeed;
//	float footSpeed2;
//	std::byte pad2[22];
//	float stopToFullRunningFraction;
//	std::byte pad3[532];
//	float velocitySubtractY;
//};

struct AnimState {
	char	u0[0x18];
	float	anim_update_timer;
	char	u1[0xC];
	float	started_moving_time;
	float	last_move_time;
	char	u2[0x10];
	float	last_lby_time;
	char	u3[0x8];
	float	run_amount;
	char	u4[0x10];
	void* entity;
	__int32 active_weapon;
	__int32 last_active_weapon;
	float	last_clientside_anim_update_time;
	__int32 last_clientside_anim_update_framecount;
	float	eye_timer;
	float	eye_angles_y;
	float	eye_angles_x;
	float	goal_feet_yaw;
	float	current_feet_yaw;
	float	torso_yaw;
	float	last_move_yaw;
	float	lean_amount;
	char	u5[0x4];
	float	feet_cycle;
	float	feet_yaw_rate;
	char	u6[0x4];
	float	duck_amount;
	float	landing_duck_amount;
	char	u7[0x4];
	Vector	current_origin;
	Vector	last_origin;
	float	velocity_x;
	float	velocity_y;
	char	u8[0x10];
	float	move_direction_1;
	float	move_direction_2;
	char	u9[0x4];
	float	velocity;
	float	jump_fall_velocity;
	float	clamped_velocity;
	float	feet_speed_forwards_or_sideways;
	float	feet_speed_unknown_forwards_or_sideways;
	float	last_time_started_moving;
	float	last_time_stopped_moving;
	bool	on_ground;
	bool	hit_in_ground_anim;
	char	u10[0x4];
	float	last_origin_z;
	float	head_from_ground_distance_standing;
	float	stop_to_full_running_fraction;
	char	u11[0x14];
	__int32 is_not_moving;
	char	u12[0x20];
	float	last_anim_update_time;
	float	moving_direction_x;
	float	moving_direction_y;
	float	moving_direction_z;
	char	u13[0x44];
	__int32 started_moving;
	char	u14[0x8];
	float	lean_yaw;
	char	u15[0x8];
	float	poses_speed;
	char	u16[0x8];
	float	ladder_speed;
	char	u17[0x8];
	float	ladder_yaw;
	char	u18[0x8];
	float	some_pose;
	char	u19[0x14];
	float	body_yaw;
	char	u20[0x8];
	float	body_pitch;
	char	u21[0x8];
	float	death_yaw;
	char	u22[0x8];
	float	stand;
	char	u23[0x8];
	float	jump_fall;
	char	u24[0x8];
	float	aim_blend_stand_idle;
	char	u25[0x8];
	float	aim_blend_crouch_idle;
	char	u26[0x8];
	float	strafe_yaw;
	char	u27[0x8];
	float	aim_blend_stand_walk;
	char	u28[0x8];
	float	aim_blend_stand_run;
	char	u29[0x8];
	float	aim_blend_crouch_walk;
	char	u30[0x8];
	float	move_blend_walk;
	char	u31[0x8];
	float	move_blend_run;
	char	u32[0x8];
	float	move_blend_crouch;
	char	u33[0x4];
	float	speed;
	__int32 moving_in_any_direction;
	float	acceleration;
	char	u34[0x74];
	float	crouch_height;
	__int32 is_full_crouched;
	char	u35[0x4];
	float	velocity_subtract_x;
	float	velocity_subtract_y;
	float	velocity_subtract_z;
	float	standing_head_height;
};

struct Ray_t;
struct Trace_t;
struct TraceFilter_t;
class Interfaces;

class GlowObject_t {
public:
	DWORD dwBase;
	float r;
	float g;
	float b;
	float a;
	uint8_t padding[16];
	bool renderOccluded;
	bool renderUnoccluded;
	bool fullBloom;
	uint8_t padding2[14];
};

enum class MoveType {
	NOCLIP = 8,
	LADDER = 9
};

enum class ObsMode {
	None = 0,
	Deathcam,
	Freezecam,
	Fixed,
	InEye,
	Chase,
	Roaming
};

enum class WeaponType {
	WEAPONTYPE_KNIFE = 0,
	WEAPONTYPE_PISTOL,
	WEAPONTYPE_SUBMACHINEGUN,
	WEAPONTYPE_RIFLE,
	WEAPONTYPE_SHOTGUN,
	WEAPONTYPE_SNIPER_RIFLE,
	WEAPONTYPE_MACHINEGUN,
	WEAPONTYPE_C4,
	WEAPONTYPE_GRENADE,
	WEAPONTYPE_UNKNOWN
};

struct WeaponInfo {
	PAD(20)
		int maxClip;
	PAD(112)
		char* name;
	PAD(60)
		WeaponType type;
	PAD(4)
		int price;
	PAD(0x8)
		float cycletime;
	PAD(12)
		bool fullAuto;
	PAD(3)
		int damage;
	float armorRatio;
	int bullets;
	float penetration;
	PAD(8)
		float range;
	float rangeModifier;
	PAD(0x10)
		bool silencer;
	PAD(15)
		float maxSpeed;
	float maxSpeedAlt;
	PAD(100)
		float recoilMagnitude;
	float recoilMagnitudeAlt;
	PAD(0x14)
		float recoveryTimeStand;
};

class Collideable {
public:
	VF(const Vector&, obbMins, 1, (), (this))
		VF(const Vector&, obbMaxs, 2, (), (this))
};

//struct Model {
//	void* handle;
//	int	flags;
//	Vector mins, maxs;
//};

struct Model_t;

class C_BaseEntity
{
public:
	VF(void, release, 1, (), (this + 8));
	VF(ClientClass*, getClientClass, 2, (), (this + 8));
	VF(void, preDataUpdate, 6, (int updateType), (this + 8, updateType));
	VF(void, postDataUpdate, 7, (int updateType), (this + 8, updateType));
	VF(bool, isDormant, 9, (), (this + 8));
	VF(int, index, 10, (), (this + 8));
	VF(void, setDestroyedOnRecreateEntities, 13, (), (this + 8));
	VF(const Model_t*, getModel, 8, (), (this + 4));
	VF(const matrix3x4&, toWorldTransform, 32, (), (this + 4));

	VF(int&, handle, 2, (), (this));
	VF(Collideable*, getCollideable, 3, (), (this));
	VF(const Vector&, getAbsOrigin, 10, (), (this));
	VF(void, setModelIndex, 75, (int index), (this, index));
	VF(int, health, 121, (), (this));
	VF(bool, isAlive, 155, (), (this));
	VF(bool, isPlayer, 157, (), (this));
	VF(bool, isWeapon, 165, (), (this));
	VF(C_BaseEntity*, getActiveWeapon, 267, (), (this));
	VF(int, getWeaponSubType, 281, (), (this));
	//VirtualFunc(Vector, getEyePosition, 284, (), (this));
	VF(ObsMode, getObserverMode, 293, (), (this));
	VF(C_BaseEntity*, getObserverTarget, 294, (), (this));
	VF(Vector, getAimPunch, 345, (), (this));
	VF(WeaponType, getWeaponType, 454, (), (this));
	VF(WeaponInfo*, getWeaponData, 460, (), (this));
	VF(float, getInaccuracy, 482, (), (this));
	VF(bool, setupBones, 13, (matrix3x4* out, int maxBones, int boneMask, float currentTime), (this + 4, out, maxBones, boneMask, currentTime));

	RNETVAR(Vector, origin, this, 0x138)
	RNETVAR(MoveType, moveType, this, 0x25C)
	RNETVAR(float, simulationTime, this, 0x268)
	RNETVAR(C_BaseEntity*, ownerEntity, this, 0x14C)
	RNETVAR(int, team, this, 0xF4)
	ANETVAR(bool, spotted, this, 0x93D)
	RNETVAR(int*, weapons, this, 0x2DF8)
	ANETVAR(float, FOV, this, 0x31E4)
	RNETVAR(int, FOVStart, this, 0x31E8)
	RNETVAR(BYTE, flags, this, 0x104)
	RNETVAR(int, tickBase, this, 0x3430)
	RNETVAR(Vector, aimPunchAngles, this, 0x302C)
	RNETVAR(Vector, viewPunchAngles, this, 0x3020)
	RNETVAR(Vector, velocity, this, 0x114)
	RNETVAR(char*, lastPlaceName, this, 0x35B4)
	RNETVAR(int, armor, this, 0xB378)
	RNETVAR(Vector, eyeAngles, this, 0xB37C)
	RNETVAR(bool, isScoped, this, 0x3928)
	RNETVAR(bool, isDefusing, this, 0x3930)
	ANETVAR(float, flashDuration, this, 0xA420)
	ANETVAR(float, flashAlpha, this, 0xA41C)
	RNETVAR(bool, gunGameImmunity, this, 0x3944)
	RNETVAR(int, accountID, this, 0x2FC8)
	RNETVAR(bool, hasDefuser, this, 0xB388)
	RNETVAR(bool, hasHelmet, this, 0xB36C)
	RNETVAR(float, lby, this, 0x3A90)
	RNETVAR(int, shotsFired, this, 0xA390)
	RNETVAR(int, clip, this, 0x3264)
	RNETVAR(float, nextPrimaryAttack, this, 0x3238)
	RNETVAR(float, nextAttack, this, 0x2D70)
	RNETVAR(short, itemDefinitionIndex, this, 0x2FAA)
	ANETVAR(int, itemIDHigh, this, 0x2FC0)
	RNETVAR(int, entityQuality, this, 0x2FAC)
	RNETVAR(char*, customName, this, 0x303C)
	ANETVAR(unsigned, fallbackPaintKit, this, 0x31C8)
	ANETVAR(unsigned, fallbackSeed, this, 0x31CC)
	ANETVAR(float, fallbackWear, this, 0x31D0)
	ANETVAR(unsigned, fallbackStatTrak, this, 0x31D4)
	RNETVAR(int, owner, this, 0x29CC)
	RNETVAR(int, weapon, this, 0x2EF8)
	RNETVAR(bool, c4StartedArming, this, 0x33F0)
	RNETVAR(float, c4BlowTime, this, 0x2990)
	RNETVAR(float, c4DefuseCountDown, this, 0x29AC)
	RNETVAR(Vector, viewOffset, this, 0x108)
	RNETVAR(int, oHealth, this, 0x100)
	RNETVAR(bool, oIsDormant, this, 0xED)
	RNETVAR(int, GlowIndex, this, 0xA438)
	RNETVAR(int, CrosshairId, this, 0xB3E4)

	bool isFlashed() noexcept
	{
		return flashDuration() > 75.0f;
	}

	bool grenadeExploded() noexcept
	{
		return *reinterpret_cast<bool*>(this + 0x29E8);
	}

	bool isPlayer2() noexcept
	{
		return getClientClass()->m_ClassID == EClassIds::CBasePlayer;
	}

	AnimState* getAnimstate() noexcept
	{
		return *reinterpret_cast<AnimState**>(this + 0x3914);
	}

	/*float getMaxDesyncAngle() noexcept
	{
		const auto animState = getAnimstate();

		if (!animState)
			return 0.0f;

		float yawModifier = (animState->stopToFullRunningFraction * -0.3f - 0.2f) * std::clamp(animState->footSpeed, 0.0f, 1.0f) + 1.0f;

		if (animState->duckAmount > 0.0f)
			yawModifier += (animState->duckAmount * std::clamp(animState->footSpeed2, 0.0f, 1.0f) * (0.5f - yawModifier));

		return animState->velocitySubtractY * yawModifier;
	}*/

	float getMaxDesyncAngle() noexcept
	{
		const auto animState = getAnimstate();

		if (!animState)
			return 0.f;

		float yawModifier = (animState->stop_to_full_running_fraction * -0.3f - 0.2f) * std::clamp(animState->feet_speed_forwards_or_sideways, 0.f, 1.f) + 1.f;

		if (animState->duck_amount > 0.0f)
			yawModifier += (animState->duck_amount * std::clamp(animState->feet_speed_forwards_or_sideways, 0.0f, 1.0f) * (0.5f - yawModifier));

		return animState->velocity_subtract_y * yawModifier;
	}

	Vector getEyePosition() noexcept
	{
		return origin() + viewOffset();
	}

	auto isFullAuto() noexcept
	{
		const auto weaponData = getWeaponData();
		if (weaponData)
			return weaponData->fullAuto;
		return false;
	}

	auto requiresRecoilControl() noexcept
	{
		const auto weaponData = getWeaponData();
		if (weaponData)
			return weaponData->recoilMagnitude < 35.0f && weaponData->recoveryTimeStand > weaponData->cycletime;
		return false;
	}

	Vector getBonePosition(int bone) noexcept
	{
		if (matrix3x4 boneMatrices[256]; setupBones(boneMatrices, 256, 256, 0.0f))
			return boneMatrices[bone].origin();
		else
			return Vector{ };
	}

	bool isInReload() noexcept
	{
		return *reinterpret_cast<bool*>(uintptr_t(clip()) + 0x41);
	}

	const char* GetCompRank();

	bool isVisible(const Vector& position = { }) noexcept;
	bool isBodyVisible() noexcept;
	auto getUserId() noexcept;
	char* getPlayerName() noexcept;
	float GetBombTimer() noexcept;
	bool isValid() noexcept;
	bool isTeammate() noexcept;
	void SetGlow(Vector& Color, float alpha = 1.f) noexcept;
	bool isWeaponSniper() noexcept;
	bool isGun() noexcept;
};