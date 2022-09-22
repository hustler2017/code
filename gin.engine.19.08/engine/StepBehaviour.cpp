#include "pch.h"
#include "StepBehaviour.h"
#include "Helper.h"

namespace Engine
{
	StepBehaviour::StepBehaviour(AgentBehaviourContext* context)
		: m_context(context)
	{

	}

	StepBehaviour::~StepBehaviour()
	{

	}


	void StepBehaviour::onInitialize() 
	{
		m_context->agent->startAnimation("walk");

		Vector3 position = m_context->agent->getPosition()->position;
		Vector3 point(m_context->moveToPoint.x, m_context->moveToPoint.y, 0);

		float dist = Helper::distance(point, position);

		steps = dist / m_context->speed;
		step = 0;

		float dirX = m_context->moveToPoint.x - position.x;
		float dirY = m_context->moveToPoint.y - position.y;

		Helper::normalize(dirX, dirY);

		stepX = m_context->speed * dirX;
		stepY = m_context->speed * dirY;

		m_context->agent->setDirection(Vector3(dirX, dirY, 0));
	}
	
	void StepBehaviour::onTerminate(Status status) 
	{

	}

	
	Status StepBehaviour::update()
	{
		if (step++ < steps)
		{
			m_context->agent->getPosition()->position.x += stepX;
			m_context->agent->getPosition()->position.y += stepY;

			return Status::RUNNING;
		}

		return Status::SUCCESS;

	}
}