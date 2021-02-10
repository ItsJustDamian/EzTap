#include "C_BaseEntity.hpp"

const char* C_BaseEntity::GetCompRank()
{
	static unsigned int m_iCompetitiveRanking = 0x1A44;
	static unsigned int GameResources = *reinterpret_cast<unsigned int*>(Memory::FindPattern(Modules::Client, "8B 3D ? ? ? ? 85 FF 0F 84 ? ? ? ? 81 C7") + 0x2);
	int rankNum = *reinterpret_cast<int*>(GameResources + 0x1A84 + this->index() * 4);

	static const char* Ranks[] =
	{
		"None",
		"Silver I",
		"Silver II",
		"Silver III",
		"Silver IV",
		"Silver Elite",
		"Silver Elite Master",

		"Gold Nova I",
		"Gold Nova II",
		"Gold Nova III",
		"Gold Nova Master",
		"Master Guardian I",
		"Master Guardian II",

		"Master Guardian Elite",
		"Distinguished Master Guardian",
		"Legendary Eagle",
		"Legendary Eagle Master",
		"Supreme Master First Class",
		"Global Elite"
	};

	return Ranks[rankNum];
}

bool C_BaseEntity::isVisible(const Vector& position) noexcept
{
	if (!LocalPlayer)
		return false;

	Trace_t trace;
	interfaces.EngineTrace->traceRay({ LocalPlayer->getEyePosition(), position.notNull() ? position : getBonePosition(8) }, 0x46004009, { LocalPlayer }, trace);
	return trace.entity == this || trace.fraction > 0.97f;
}

bool C_BaseEntity::isBodyVisible() noexcept
{
	if (!LocalPlayer)
		return false;

	Trace_t trace;
	interfaces.EngineTrace->traceRay({ LocalPlayer->getEyePosition(), getBonePosition(90) }, 0x46004009, { LocalPlayer }, trace);
	
	if (trace.entity == this || trace.fraction > 0.97f)
		return true;
	
	interfaces.EngineTrace->traceRay({ LocalPlayer->getEyePosition(), getBonePosition(8) }, 0x46004009, { LocalPlayer }, trace);

	if (trace.entity == this || trace.fraction > 0.97f)
		return true;

	return false;
}

int C_BaseEntity::getUserId() noexcept
{
	if (playerInfo playerInfo; interfaces.Engine->getPlayerInfo(index(), &playerInfo))
		return playerInfo.userid;

	return -1;
}

char* C_BaseEntity::getPlayerName() noexcept
{
	playerInfo info;
	if (interfaces.Engine->getPlayerInfo(index(), &info))
	{
		return info.name;
	}

	return nullptr;
}

float C_BaseEntity::GetBombTimer() noexcept
{
	float bombTime = this->c4BlowTime();
	float returnValue = bombTime - interfaces.GlobalVars->curtime;
	return (returnValue < 0) ? 0.f : returnValue;
}

bool C_BaseEntity::isValid() noexcept
{
	return (this && this->isPlayer2() && this != LocalPlayer && this->oHealth() > 0 && !this->oIsDormant() && this->team() > 0);
}

bool C_BaseEntity::isTeammate() noexcept
{
	return this->team() == LocalPlayer->team();
}

bool C_BaseEntity::isWeaponSniper() noexcept
{
	WeaponType type = this->getWeaponType();

	switch (type)
	{
	case WeaponType::WEAPONTYPE_SNIPER_RIFLE: return true;
	default: return false;
	}

	return false;
}

bool C_BaseEntity::isGun() noexcept
{
	WeaponType type = this->getWeaponType();

	switch (type)
	{
	case WeaponType::WEAPONTYPE_MACHINEGUN:
	case WeaponType::WEAPONTYPE_PISTOL:
	case WeaponType::WEAPONTYPE_RIFLE:
	case WeaponType::WEAPONTYPE_SHOTGUN:
	case WeaponType::WEAPONTYPE_SNIPER_RIFLE:
	case WeaponType::WEAPONTYPE_SUBMACHINEGUN: return true;  break;
	default: return false;
	}

	return false;
}

