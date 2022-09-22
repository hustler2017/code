#pragma once

#include "GraphNodeLink.h"
#include <algorithm>
#include <map>

namespace Engine
{
	namespace Navigation
	{
		class GraphNodeLink;

		class GraphNode
		{
		public:
			int reference_id;
			float cost;
			std::map<int, GraphNodeLink*> m_links;
		public:
			GraphNode(int ref_id);
			~GraphNode();
			inline bool hasLink(int reference_id);
			void addLink(GraphNode* node, float cost);
			GraphNode* getLowestCostLinkNode();
		};
	}
}
