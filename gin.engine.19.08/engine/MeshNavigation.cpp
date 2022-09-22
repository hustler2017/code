#include "pch.h"
#include "MeshNavigation.h"
#include "AStar.h"
#include "FunnelAlgorithm.h"

namespace Engine
{
	namespace Navigation
	{

		MeshNavigation::MeshNavigation(IVertexData* vd, Liner* liner)
		{
			m_navmesh = new NavMesh(vd);
			m_graph = new Graph;
			pLiner = liner;

			int polygonsCount = m_navmesh->getPolygonsCount();
			for (int i = 0; i < polygonsCount; i++)
			{
				m_graph->addNode(i);
			}

			for (int i = 0; i < polygonsCount; i++)
			{
				for (int k = 0; k < 3; k++)
				{
					int polygon = m_navmesh->getAdjacentPolygon(i, k);
					if (polygon == -1) 
						continue;
					
					m_graph->connect(i, polygon, m_navmesh->distance(i,k));
				}
			}
		}

		MeshNavigation::~MeshNavigation()
		{
			delete m_graph;
			delete m_navmesh;
		}

		void MeshNavigation::fillNodeLinks(std::vector<Vector3>* vec)
		{
			std::map<int, GraphNode*>* nodes = m_graph->getNodes();

			for (auto it = nodes->begin(); it != nodes->end(); it++)
			{
				GraphNode* node = (*it).second;
				GraphNode* linkNode;
				for (auto& link : (*it).second->m_links)
				{
					linkNode = link.second->node;

					auto p1 = m_navmesh->getPolygon(node->reference_id);
					auto p2 = m_navmesh->getPolygon(linkNode->reference_id);

					vec->push_back(p1->center);
					vec->push_back(p2->center);


				}
				
			}

		}

		bool MeshNavigation::FindPath(Vector2 from, Vector2 to, std::list<Vector2>& path)
		{
			pLiner->clearLines("nodepath");
		

			int startPolygonID = m_navmesh->findPolygonByPoint(from.x, from.y);
			if (startPolygonID == -1) {
				//OutputDebugString(L"точка не принадлежит ни одному полигону");
				return false;

			}

			int endPolygonID = m_navmesh->findPolygonByPoint(to.x, to.y);
			if (endPolygonID == -1) {
				//OutputDebugString(L"точка не принадлежит ни одному полигону");
				return false;
			}

			if (startPolygonID == endPolygonID)
			{
				path.push_back(from);
				path.push_back(to);
				return true;
			}

			GraphNode* startNode = m_graph->getNode(startPolygonID);
			if (startNode == nullptr)
			{
				//OutputDebugString(L"не найден узел");
				return false;
			}

			GraphNode* endNode = m_graph->getNode(endPolygonID);
			if (endNode == nullptr)
			{
				//OutputDebugString(L"не найден узел");
				return false;
			}

			m_graph->clearCoasts();

			std::list<GraphNode*> nodePath;
			bool result = AStar::findPath(startNode, endNode, nodePath);

			if (result == false)
			{
				//OutputDebugString(L" путь не найден");
				return false;
			}
			
			
			if (nodePath.size() == 1)
			{
				auto h = m_navmesh->getPolygon(nodePath.front()->reference_id);

				pLiner->addLine( "nodepath", Vector3(from.x, from.y, 5), h->center, Vector4(1, 0, 1, 1) );
				pLiner->addLine( "nodepath", h->center, Vector3(to.x, to.y, 5), Vector4(1, 0, 1, 1) );
			}
			
			if (nodePath.size() > 1)
			{
				auto it = nodePath.begin();
				auto itnext = nodePath.begin();
				itnext++;

				for (; itnext != nodePath.end(); it++, itnext++)
				{
					Vector3 c1 = m_navmesh->getPolygon((*it)->reference_id)->center;
					Vector3 c2 = m_navmesh->getPolygon((*itnext)->reference_id)->center;
					c1.z = 5;
					c2.z = 5;
					pLiner->addLine("nodepath", c1, c2, Vector4(0, 0, 0, 3));
				}
			}

			

			FunnelSearch( from, to, nodePath, path );

			return true;
		}

		
		void MeshNavigation::FunnelSearch2(Vector2& from, Vector2& to, std::list<GraphNode*>& nodePath, std::list<Vector2>& path)
		{
		/*	struct Portal
			{
				int left;
				int right;
			};

			std::list<Portal> portals;

			auto it_first = nodePath.begin()++;
			auto it_last = nodePath.begin();

			while (it_last != nodePath.end())
			{
				NavMesh::Polygon* p = m_navmesh->getPolygon((*it_last)->reference_id);



				portals.push_back()

			}

			*/
		}

		void MeshNavigation::FunnelSearch(
			Vector2& from, 
			Vector2& to, 
			std::list<GraphNode*>& nodePath, 
			std::list<Vector2>& path
		)
		{
			int portals_count = nodePath.size() - 1;
			int portals_point = portals_count * 2;
			int* portals = new int[portals_point];

			GraphNode* prev = nullptr;
			GraphNode* current = nullptr;

			int portals_offset = 0;

			//std::stringstream ss;

			for (auto it = nodePath.begin(); it != nodePath.end(); it++)
			{
				current = (*it);
				if (prev)
				{
					m_navmesh->getPortal(portals[portals_offset], portals[portals_offset + 1], prev->reference_id, current->reference_id);
					portals_offset += 2;
				}
				prev = current;
			}

			//OutputDebugStringA(ss.str().c_str());

			Vector3* points = m_navmesh->getControlPoints();
			
			for (int j = 0; j < portals_count; j++)
			{
				Vector3 left = points[portals[j * 2]];
				Vector3 right = points[portals[j * 2 + 1]];

				left.z = 2;
				right.z = 2;

				pLiner->addLine("portals", 
					left,
					right,
					Vector4(1, 0, 0, 1)
				);
			}
			
			int max_path_size = (nodePath.size() + 1) * 2;
			float* rawpath = new float[max_path_size];
			int path_size = 0;

			FunnelAlgorithm::Search(
				reinterpret_cast<float*>(&from),
				reinterpret_cast<float*>(&to),
				reinterpret_cast<float*>(points),
				portals,
				portals_count,
				rawpath,
				path_size
			);

			for (int i = 0; i < path_size; i += 2)
			{
				Vector2 p = { rawpath[i], rawpath[i + 1] };
				path.push_back(p);
			}

			delete[] rawpath;
			delete[] portals;
		}

	}
}