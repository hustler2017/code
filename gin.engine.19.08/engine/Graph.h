#pragma once

#include "GraphNode.h"
#include <map>

namespace Engine
{
	namespace Navigation
	{
		class Graph
		{
			std::map<int, GraphNode*> m_nodes;

		public:
			Graph();
			~Graph();
			bool addNode(int reference_id);
			GraphNode* getNode(int reference_id);
			void clearCoasts();
			void connect(int i, int k, float link_cost);
			std::map<int, GraphNode*>* getNodes();
		};
	}
}


