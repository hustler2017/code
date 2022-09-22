#pragma once

#include "Graph.h"
#include <list>

namespace Engine
{
	namespace Navigation
	{
		class AStar
		{
			static void buildPath(GraphNode* start, GraphNode* end, std::list<GraphNode*>& path);
		public:
			static bool findPath(GraphNode* start, GraphNode* end, std::list<GraphNode*>& path);
		};
	}
}
