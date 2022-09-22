#include "pch.h"
#include "Graph.h"

namespace Engine
{
	namespace Navigation
	{
		Graph::Graph() 
		{
		};

		Graph::~Graph() 
		{
			for (auto& pair : m_nodes)
				delete pair.second;
		};

		bool Graph::addNode(int reference_id)
		{
			auto it = m_nodes.find(reference_id);

			if (it == m_nodes.end())
			{
				m_nodes[reference_id] = new GraphNode(reference_id);
				return true;
			}

			return false;
		}

		GraphNode* Graph::getNode(int reference_id)
		{
			auto it = m_nodes.find(reference_id);

			if (it == m_nodes.end())
			{
				return nullptr;
			}

			return it->second;
		}

		void Graph::clearCoasts()
		{
			for (auto it = m_nodes.begin(); it != m_nodes.end(); it++)
			{
				it->second->cost = 99999;
			}
		}

		void Graph::connect(int nodeId1, int nodeId2, float link_cost)
		{
			m_nodes[nodeId1]->addLink(m_nodes[nodeId2], link_cost);
			m_nodes[nodeId2]->addLink(m_nodes[nodeId1], link_cost);
		}

		std::map<int, GraphNode*>* Graph::getNodes()
		{
			return &m_nodes;
		}
	}
}




