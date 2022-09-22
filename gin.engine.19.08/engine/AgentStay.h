#pragma once
#include "Task.h"
#include <string>
#include "Command.h"
#include "AgentBehaviourContext.h"

namespace Engine
{
    class AgentStay : public Task
    {
	protected:
		AgentBehaviourContext* m_context;
	public:
		AgentStay(AgentBehaviourContext* context);
		void setCommand(Command* command);
		Status tick();
		std::string getType();
    };
}

