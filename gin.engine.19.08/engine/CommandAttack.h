#pragma once
#include "Command.h"
#include "Agent.h"

namespace Engine
{
	struct CommandAttack : public Command
	{
		Agent* target;
		const std::string getType() { return "attack"; }
		CommandAttack(Agent* _target) : target(_target) {}
	};
}