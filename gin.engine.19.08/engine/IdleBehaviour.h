#pragma once
#include "Behaviour.h"
#include "AgentBehaviourContext.h"

namespace Engine
{
	class IdleBehaviour : public BT::Behaviour
	{

		AgentBehaviourContext* m_context;

	protected:
		void onInitialize();
		Status update();
		void onTerminate(Status);
	public:
		IdleBehaviour(AgentBehaviourContext* context);
	};
}

