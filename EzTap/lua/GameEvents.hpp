#include "../Hooks.hpp"
#include "../Interfaces.hpp"
#include "../valve_sdk/Interfaces/IGameEvent.hpp"
#include <string>
#include <vector>
#include "LuaEngine.hpp"

class GameEvents : IGameEventListener2
{
public:
	GameEvents();
	~GameEvents();
	virtual void FireGameEvent(IGameEvent* pEvent);
	int GetEventDebugID() override;
};