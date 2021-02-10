#include "KillChat.hpp"

KillChat::KillChat()
{
	if (!interfaces.GameEventManager->addListener(this, "player_death"))
		console.Error("Failed to load killchat\n");
	else
		console.Debug("Hooked player_death event!\n");
}

KillChat::~KillChat()
{
	interfaces.GameEventManager->removeListener(this);
	console.Debug("Unhooked player_death event!");
}

void KillChat::FireGameEvent(IGameEvent* pEvent)
{
	if (!features.TrashTalk)
		return;

	int userid = pEvent->GetInt("userid");
	int attackerid = pEvent->GetInt("attacker");

	if (LocalPlayer->getUserId() == attackerid)
	{
		static int randomId;
		static char outStr[1024];
		static std::vector <std::string> list;

		switch (features.TrashTalkType)
		{
		case 0:
			list = funnyTrashTalk;
			break;
		case 1:
			list = negativeTrashTalk;
			break;
		case 2:
			list = edgyTrashTalk;
			break;
		case 3:
			list = darkTrashTalk;
			break;
		}

		randomId = rand() % (list.size() + 1);
		sprintf(outStr, "say %s", list.at(randomId).c_str());

		interfaces.Engine->executeClientCmd(outStr);
	}
}

int KillChat::GetEventDebugID()
{
	return EVENT_DEBUG_ID_INIT;
}
