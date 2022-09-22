#pragma once
#include "Command.h"

namespace Engine
{
	struct CommandMove : public Command
	{
		float x;
		float y;

		const std::string getType() { return "walk"; }
		CommandMove(float _x, float _y) : x(_x), y(_y) {}
	};
}


