#pragma once
#include "Task.h"
#include "Command.h"
#include <map>

namespace Engine
{
	class Actor
	{
	protected:
		std::map<std::string, Task*> m_tasks;
		Task* m_current;
		virtual void update();
	public:	
		Actor() : m_current(nullptr) {};
		
		~Actor() 
		{
			for (auto& pair : m_tasks)
			{
				delete pair.second;
			}
		};
	};

}
