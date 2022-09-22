#pragma once
#include "Common.h"
#include "NavPolygon.h"
#include "IVertexData.h"
//#include "Direct3D.h"
#include <vector>
#include <sstream>

#ifndef UINT
#define UINT  unsigned int  
#endif // !UINT


namespace Engine
{
	namespace Navigation
	{
		class NavMesh
		{
		public:
			struct Edge
			{
				int polygon;
				int leftPoint;
				int rightPoint;
				int adjacent_edge;
			};

			struct Polygon
			{
				int verticies[3];
				int edges[3];
				Vector3 center;
				int adjacent[3];
			};


		private:

			UINT polygonCount;
			UINT pointCount;
			UINT edges_count;

			Polygon* polygons;
			Vector3* points;
			Edge* edges;

		public:

			NavMesh(IVertexData* vertexData);
			~NavMesh();
			int getPolygonsCount();
			Polygon* getPolygon(int index);
			int getAdjacentPolygon(int polygonIndex, int edge);
			Edge* getEdge(int index);
			float distance(int i, int k);
			bool insidePolygon(int polygon, float x, float y);
			int findPolygonByPoint(float x, float y);
			Vector3 center(UINT polygon);
			void getPortal(int& leftPoint, int& rightPoint, int& fromPolygon, int& toPolygon);
			Vector3* getControlPoints();
		};
	}
}
