#pragma once
#include "pch.h"
#include "Object.h"
#include "Actor.h"
#include "Command.h"

namespace Engine
{
	struct Command;
	class Task;
	class Actor;
	class Object;

	class Agent : public Actor, public Object
	{
	private:
		Vector3 m_direction;
	protected:
		std::string m_defaultTask;
		
	public:
		void update();
		Agent();
		~Agent();
		Task* getTask(std::string key);
		void addTask(Task* task);
		virtual void setCommand(Command* command);
		virtual void setDefaultTask(std::string task);
		virtual void startAnimation(std::string animKey);
		Vector3 getDirection();
		void setDirection(Vector3 direction);

	};

}

