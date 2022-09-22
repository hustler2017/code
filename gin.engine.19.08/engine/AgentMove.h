#pragma once
#include "Command.h"
#include "AgentBehaviourContext.h"

namespace Engine
{
	using namespace BT;

	class AgentMove : public Task
	{
	protected:
		AgentBehaviourContext* m_context;
	public:
		AgentMove(AgentBehaviourContext* context);
		void setCommand(Command* command);
		Status tick();
		std::string getType();
	};
}

