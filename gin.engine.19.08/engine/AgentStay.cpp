#include "pch.h"
#include "AgentStay.h"
#include "IdleBehaviour.h"

namespace Engine
{
	AgentStay::AgentStay(AgentBehaviourContext* context)
		: m_context(context)
	{
		m_behaviour = new IdleBehaviour(context);
	}

	void AgentStay::setCommand(Command* command)
	{
	}

	Status AgentStay::tick()
	{
		return m_behaviour->tick();
	}

	std::string AgentStay::getType()
	{ 
		return "stay"; 
	};
}
