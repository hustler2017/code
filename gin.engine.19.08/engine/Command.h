#pragma once

#include <string>

namespace Engine
{
	struct Command
	{
		virtual const std::string getType() { return "none"; }
	};	
}