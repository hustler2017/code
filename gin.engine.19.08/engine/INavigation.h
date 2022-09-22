#pragma once

#include "Common.h"
#include <list>

namespace Engine
{
	namespace Navigation
	{
		class INavigation
		{
		public:
			virtual bool FindPath(Vector2 from, Vector2 to, std::list<Vector2>& path) = 0;
			virtual ~INavigation() {}
		};
	}
}



