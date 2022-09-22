#pragma once
#include "Behaviour.h"
#include "AgentMove.h"

namespace Engine
{
	using namespace BT;

	class StepBehaviour : public Behaviour
	{
	private:
		AgentBehaviourContext* m_context;

		int steps;
		int step;

		float stepX;
		float stepY;

	protected:
		void onInitialize();
		Status update();
		void onTerminate(Status);
	public:
		StepBehaviour(AgentBehaviourContext* context);
		~StepBehaviour();
		

	};
}

