#include "pch.h"
#include "IdleBehaviour.h"

namespace Engine
{

	IdleBehaviour::IdleBehaviour(AgentBehaviourContext* context)
		: m_context(context)
	{
	}

	void IdleBehaviour::onInitialize() 
	{
		m_context->agent->startAnimation("walk");
	}

	Status IdleBehaviour::update()
	{
		return BT::Status::RUNNING;
	}

	void IdleBehaviour::onTerminate(Status) 
	{

	}



}