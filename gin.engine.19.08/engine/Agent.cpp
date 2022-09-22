#include "pch.h"
#include "Agent.h"
#include "AgentHelper.h"


namespace Engine
{
	Agent::Agent()	{
		visible = true;
	};
	Agent::~Agent() {};


	void Agent::update() 
	{
		if (m_current == nullptr)
		{
			m_current = getTask(m_defaultTask);
			if (m_current == nullptr)
			{
				OutputDebugString(L"У агента нет задачи по умолчанию\n");
				return;
			}
		}

		if (m_current->tick() != BT::Status::RUNNING)
		{
			m_current = getTask(m_defaultTask);
			if (m_current == nullptr)
			{
				OutputDebugString(L"У агента нет задачи по умолчанию\n");
				return;
			}
		}
	}

	Task* Agent::getTask(std::string key)
	{
		auto it = m_tasks.find(key);
		if (it != m_tasks.end())
		{
			return it->second;
		}

		return nullptr;
	}


	void Agent::addTask(Task* task)
	{
		m_tasks[task->getType()] = task;
	}

	void Agent::setCommand(Command* command)
	{
		auto it = m_tasks.find(command->getType());
		if (it != m_tasks.end())
		{
			it->second->setCommand(command);
			m_current = it->second;
		}

		delete command;
	}

	void Agent::setDefaultTask(std::string task)
	{
		m_defaultTask = task;
	}

	void Agent::startAnimation(std::string key)
	{
		m_pModel->startAnimation(key);
	}

	Vector3 Agent::getDirection()
	{
		return m_direction;
	}

	void Agent::setDirection(Vector3 direction)
	{
		m_direction = direction;
		m_position.rotation = AgentHelper::rotationFromDirection(direction, m_position.position, Vector3(0, 0, 1));
		m_position.rotation.x = 0;
		m_position.rotation.y = 0;
	}
}