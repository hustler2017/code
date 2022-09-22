#pragma once
#include "Behaviour.h"
#include "Command.h"

namespace Engine
{
	using namespace BT;

	class Task
	{
	protected:
		Behaviour* m_behaviour;
	public:
		Task() {};

		virtual ~Task() { delete m_behaviour; };
		virtual void setCommand(Command* command) {};
		virtual Status tick() = 0;
		virtual std::string getType() { return "none"; };
	};

}