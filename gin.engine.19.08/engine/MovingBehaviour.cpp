#include "pch.h"
#include "MovingBehaviour.h"


namespace Engine
{
	MovingBehaviour::MovingBehaviour(AgentBehaviourContext* context)
		: m_context(context), m_child(nullptr)
	{

	}

	MovingBehaviour::~MovingBehaviour()
	{
		delete m_child;
	}

	void MovingBehaviour::addChild(Behaviour* child)
	{
		m_child = child;
	}

	void MovingBehaviour::onInitialize()
	{
		Vector2 from { 
			m_context->agent->getPosition()->position.x,
			m_context->agent->getPosition()->position.y
		};

		Vector2 to{
			m_context->target_x, 
			m_context->target_y
		};

		m_context->navigation->FindPath(from, to, path);
		if (path.size())
		{
			path.pop_front();
			m_context->moveToPoint = path.front();
			path.pop_front();
		}

	}

	Status MovingBehaviour::update()
	{
		
		if (path.size() > 1)
		{
			auto it1 = path.begin();
			auto it2 = path.begin()++;
			for (; it2 != path.end(); it1++, it2++)
			{
				Vector3 from((*it1).x, (*it1).y, 6);
				Vector3 to((*it2).x, (*it2).y, 6);

				m_context->pLiner->addLine("path", from, to);
			}
		}
		
		if (m_child->tick() == BT::Status::RUNNING)
		{
			return BT::Status::RUNNING;
		}
		else
		{
			if (path.size())
			{
				m_context->moveToPoint = path.front();
				path.pop_front();
				return BT::Status::RUNNING;
			}

			return BT::Status::SUCCESS;
		}
	}

	void MovingBehaviour::onTerminate(Status)
	{
		path.clear();
	}
}