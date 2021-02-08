#pragma once

#include <cstddef>
#include "../Classes/Vector.hpp"
#include "../../VirtualFunction.hpp"
#include "../Classes/C_BaseEntity.hpp"

class C_BaseEntity;

struct Ray_t {
	Ray_t(const Vector& src, const Vector& dest) : start(src), delta(Vector(dest.x - src.x, dest.y - src.y, dest.z - src.z)) { isSwept = delta.x || delta.y || delta.z; }
	Vector start{ };
	float pad{ };
	Vector delta{ };
	std::byte pad2[40]{ };
	bool isRay{ true };
	bool isSwept{ };
};

struct TraceFilter_t {
	TraceFilter_t(const C_BaseEntity* entity) : skip{ entity } { }
	virtual bool shouldHitEntity(C_BaseEntity* entity, int) { return entity != skip; }
	virtual int getTraceType() const { return 0; }
	const void* skip;
};

namespace HitGroup {
	enum {
		Invalid = -1,
		Generic,
		Head,
		Chest,
		Stomach,
		LeftArm,
		RightArm,
		LeftLeg,
		RightLeg,
		Gear = 10
	};

	constexpr float getDamageMultiplier(int hitGroup) noexcept
	{
		switch (hitGroup) {
		case Head:
			return 4.0f;
		case Stomach:
			return 1.25f;
		case LeftLeg:
		case RightLeg:
			return 0.75f;
		default:
			return 1.0f;
		}
	}

	constexpr bool isArmored(int hitGroup, bool helmet) noexcept
	{
		switch (hitGroup) {
		case Head:
			return helmet;

		case Chest:
		case Stomach:
		case LeftArm:
		case RightArm:
			return true;
		default:
			return false;
		}
	}
}

struct Trace_t {
	Vector startpos;
	Vector endpos;
	std::byte pad[20];
	float fraction;
	int contents;
	unsigned short dispFlags;
	bool allSolid;
	bool startSolid;
	std::byte pad1[4];
	struct Surface {
		const char* name;
		short surfaceProps;
		unsigned short flags;
	} surface;
	int hitgroup;
	std::byte pad2[4];
	C_BaseEntity* entity;
	int hitbox;
};

class IEngineTrace
{
public:
	VF(int, getPointContents, 0, (const Vector& absPosition, int contentsMask), (this, absPosition, contentsMask, nullptr));
	VF(void, traceRay, 5, (const Ray_t& ray, unsigned int mask, const TraceFilter_t& filter, Trace_t& trace), (this, std::cref(ray), mask, std::cref(filter), std::ref(trace)));
};