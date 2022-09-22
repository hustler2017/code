#include "pch.h"
#include "AStar.h"
#include <algorithm>
#include <vector>

namespace Engine
{
	namespace Navigation
	{
		bool AStar::findPath(GraphNode* start, GraphNode* end, std::list<GraphNode*>& path)
		{
			std::list<GraphNode*> OpenList;
			start->cost = 0;
			OpenList.push_back(start);

			float cost, targetCost;
			GraphNode* current;
			while (OpenList.size())
			{
				current = OpenList.front();
				OpenList.pop_front();

				if (current == end)
				{
					buildPath(start, end, path);
					return true;
				}

				for (auto link : current->m_links)
				{
					cost = current->cost + link.second->cost;
					targetCost = link.second->node->cost;

					if (cost < targetCost) {
						link.second->node->cost = cost;
						OpenList.push_back(link.second->node);
					}
				}
			}

			return false;
		}


		void AStar::buildPath(GraphNode* start, GraphNode* end, std::list<GraphNode*>& path)
		{
			path.push_front(end);

			GraphNode* current = end;
			while (current != start)
			{
				current = current->getLowestCostLinkNode();
				path.push_front(current);
			}
		}





	}
}