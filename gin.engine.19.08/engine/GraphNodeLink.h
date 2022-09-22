#pragma once

#include "GraphNode.h"

namespace Engine
{
	namespace Navigation
	{
		class GraphNode;

		class GraphNodeLink
		{
		public:
			float cost;
			GraphNode* node;

			GraphNodeLink(GraphNode* _node, float _cost)
				:cost(_cost), node(_node) {}
		};
	}
}

