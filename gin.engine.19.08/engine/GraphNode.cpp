#include "pch.h"
#include "GraphNode.h"

namespace Engine
{
	namespace Navigation
	{
		GraphNode::GraphNode(int ref_id) 
			: reference_id(ref_id), cost(99999) 
		{};

		GraphNode::~GraphNode() 
		{
			for (auto& link : m_links)
			{
				delete link.second;
			}
		};

		inline bool GraphNode::hasLink(int reference_id)
		{
			auto it = m_links.find(reference_id);
			if (it != m_links.end())
			{
				return true;
			}

			return false;
		}

		void GraphNode::addLink(GraphNode* node, float cost)
		{
			auto it = m_links.find(node->reference_id);
			if (it != m_links.end())
			{
				it->second->cost = cost;
			}
			else
			{
				m_links[node->reference_id] = new GraphNodeLink(node, cost);
			}
		}

		GraphNode* GraphNode::getLowestCostLinkNode()
		{
			auto it = std::min_element(m_links.begin(), m_links.end(),
				[](const auto& a, const auto& b)
				{
					return a.second->node->cost < b.second->node->cost;
				}
			);


			if (it != m_links.end())
			{
				return (*it).second->node;
			}


			return nullptr;
		}
	}
}