#pragma once
#include "Behaviour.h"
#include "AgentBehaviourContext.h"
#include <list>

namespace Engine
{
	using namespace BT;

	class MovingBehaviour : public Behaviour
	{
	private:
		AgentBehaviourContext* m_context;
		Behaviour* m_child;
		std::list<Vector2> path;
	protected:
		void onInitialize();
		Status update();
		void onTerminate(Status);
	public:
		MovingBehaviour(AgentBehaviourContext* context);
		~MovingBehaviour();
		void addChild(Behaviour* child);

	};
}

