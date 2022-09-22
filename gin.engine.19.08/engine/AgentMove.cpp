#include "pch.h"
#include "AgentMove.h"
#include "MovingBehaviour.h"
#include "StepBehaviour.h"
#include "CommandMove.h"

namespace Engine
{
	AgentMove::AgentMove(AgentBehaviourContext* context)
		: m_context(context)
	{
		MovingBehaviour* b = new MovingBehaviour(m_context);
		b->addChild(new StepBehaviour(m_context));
		m_behaviour = b;
	}

	void AgentMove::setCommand(Command* command)
	{
		CommandMove* com = dynamic_cast<CommandMove*>(command);
		m_context->target_x = com->x;
		m_context->target_y = com->y;
	}

	BT::Status AgentMove::tick()
	{
		return m_behaviour->tick();
	}

	std::string AgentMove::getType()
	{
		return "walk";
	}
}