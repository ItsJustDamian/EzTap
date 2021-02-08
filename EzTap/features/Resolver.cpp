#include "Resolver.hpp"

void Resolver::SolveDesync(C_BaseEntity* pEntity)
{
	if (!pEntity || pEntity->oIsDormant())
		return;

	auto feet_yaw = pEntity->getAnimstate()->current_feet_yaw;
	auto body_max_rotation = pEntity->getMaxDesyncAngle();

	if (feet_yaw <= 58)
	{
		
	}
	else {

	}
}
