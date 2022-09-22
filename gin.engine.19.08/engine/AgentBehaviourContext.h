#pragma once

#include "Agent.h"
#include "INavigation.h"
#include "Liner.h"

namespace Engine
{
	struct AgentBehaviourContext
	{
	public:
		float target_x;
		float target_y;

		float speed;

		Vector2 moveToPoint;

		Agent* agent;
		Liner* pLiner;
		Navigation::INavigation* navigation;

		AgentBehaviourContext(Agent* _agent, Navigation::INavigation* nav, Liner* liner);
	};
}
