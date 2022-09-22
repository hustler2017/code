#include "pch.h"
#include "NavMesh.h"

namespace Engine
{
	namespace Navigation
	{
		NavMesh::NavMesh(IVertexData* vertexData)
		{
			polygonCount = vertexData->getPolygonCount();
			pointCount = vertexData->getCoordinatesCount();

			points = new Vector3[pointCount];

			for (UINT i = 0; i < pointCount; i++)
			{
				points[i] = vertexData->getCoordinates(i);
			}

			edges_count = polygonCount * 3;
			edges = new Edge[edges_count];
			
			
			polygons = new Polygon[polygonCount];
			
			UINT pointIndex;
			int edge_i = 0;
			int h = 0;

			for (int i = 0; i < polygonCount; i++)
			{
				for (int g = 0; g < 3; g++)
				{
					pointIndex = vertexData->getPolygonVertex(i, 2-g);
					polygons[i].verticies[g] = pointIndex;
					edges[edge_i].adjacent_edge = -1;
					edges[edge_i].polygon = i;
					polygons[i].edges[g] = edge_i;
					edge_i++;
				}

				edges[h].leftPoint = polygons[i].verticies[0];
				edges[h++].rightPoint = polygons[i].verticies[1];

				edges[h].leftPoint = polygons[i].verticies[1];
				edges[h++].rightPoint = polygons[i].verticies[2];

				edges[h].leftPoint = polygons[i].verticies[2];
				edges[h++].rightPoint = polygons[i].verticies[0];

				polygons[i].center = center(i);
			}

			for (int i = 0; i < edges_count; i++)
			{
				for (int j = i + 1; j < edges_count; j++)
				{
					if (edges[i].leftPoint == edges[j].rightPoint)
					{
						if (edges[i].rightPoint == edges[j].leftPoint)
						{
							edges[i].adjacent_edge = j;
							edges[j].adjacent_edge = i;
							break;
						}
					}
				}
			}

			int edge_index;
			int polygon_edge_index;
			int adjacent_edge_index;
			int adjacent_polygon_index;
			

			for (int polygon_index = 0; polygon_index < polygonCount; polygon_index++)
			{
				for (int polygon_edge_num = 0; polygon_edge_num < 3; polygon_edge_num++)
				{
					edge_index = polygons[polygon_index].edges[polygon_edge_num];
					adjacent_edge_index = edges[edge_index].adjacent_edge;

					if (adjacent_edge_index != -1)
					{
						adjacent_polygon_index = edges[adjacent_edge_index].polygon;
						polygons[polygon_index].adjacent[polygon_edge_num] = adjacent_polygon_index;
					}
				}
			}


		}

		NavMesh::~NavMesh()
		{
			delete[] polygons;
			delete[] points;
			delete[] edges;
		}

		Vector3* NavMesh::getControlPoints()
		{
			return points;
		}

		void NavMesh::getPortal(int& leftPoint, int& rightPoint, int& fromPolygon, int& toPolygon)
		{
			Polygon* p = &polygons[fromPolygon];

			Edge* edge;
			int edge_id;
			for (int i = 0; i < 3; i++)
			{
				if (p->adjacent[i] == toPolygon)
				{
					edge_id = p->edges[i];
					leftPoint = edges[edge_id].leftPoint;
					rightPoint = edges[edge_id].rightPoint;
					return;
				}
			}
		}

		Vector3 NavMesh::center(UINT polygon)
		{
			Vector3 vec;
			for (int i = 0; i < 3; i++)
			{
				vec.x += points[polygons[polygon].verticies[i]].x;
				vec.y += points[polygons[polygon].verticies[i]].y;
				vec.z += points[polygons[polygon].verticies[i]].z;
			}

			vec.x /= 3;
			vec.y /= 3;
			vec.z /= 3;

			return vec;
		}

		
		int NavMesh::getPolygonsCount()
		{
			return polygonCount;
		}

		NavMesh::Edge* NavMesh::getEdge(int index)
		{
			return &edges[index];
		}

		int NavMesh::getAdjacentPolygon(int polygonIndex, int edge)
		{
			int i = polygons[polygonIndex].edges[edge];
			int adjacentEdge = edges[i].adjacent_edge;
			if (adjacentEdge == -1) {
				return -1;
			}
			return edges[adjacentEdge].polygon;

		}


		NavMesh::Polygon* NavMesh::getPolygon(int index)
		{
			return &polygons[index];
		}

		float NavMesh::distance(int i, int k)
		{
			Vector3 a = polygons[i].center;
			Vector3 b = polygons[k].center;
			float d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
			return d;
		}


		bool NavMesh::insidePolygon(int polygon, float x, float y)
		{
			float x1 = points[polygons[polygon].verticies[0]].x;
			float x2 = points[polygons[polygon].verticies[1]].x;
			float x3 = points[polygons[polygon].verticies[2]].x;
			float y1 = points[polygons[polygon].verticies[0]].y;
			float y2 = points[polygons[polygon].verticies[1]].y;
			float y3 = points[polygons[polygon].verticies[2]].y;

			float a = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
			float b = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
			float c = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);

			return (a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0);
		}


		int NavMesh::findPolygonByPoint(float x, float y)
		{
			for (int i = 0; i < polygonCount; i++)
			{
				if (insidePolygon(i, x, y))
					return i;
			}

			return -1;
		}
	}
}