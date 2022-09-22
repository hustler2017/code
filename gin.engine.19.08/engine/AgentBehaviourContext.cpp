#include "pch.h"
#include "AgentBehaviourContext.h"

namespace Engine
{
	AgentBehaviourContext::AgentBehaviourContext(Agent* _agent, Navigation::INavigation* nav, Liner* liner)
		: agent(_agent), navigation(nav), pLiner(liner)
	{
		target_x = 0;
		target_y = 0;
		speed = 0.6f;
	}
}