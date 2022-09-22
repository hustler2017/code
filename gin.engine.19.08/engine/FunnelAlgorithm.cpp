#include "pch.h"
#include "FunnelAlgorithm.h"

namespace Engine
{
	namespace Navigation
	{

		//  если ab левее ac - > 0
		inline float triarea2(const float* a, const float* b, const float* c)
		{
			const float ax = b[0] - a[0];
			const float ay = b[1] - a[1];
			const float bx = c[0] - a[0];
			const float by = c[1] - a[1];
			return bx * ay - ax * by;
		}


		void FunnelAlgorithm::Search(float* start, float* end, float* points, int* portals, int num_portals, float* path, int& path_size)
		{


			int portalLeftID;
			int portalRightID;

			float* portalLeft = nullptr;
			float* portalRight = nullptr;

			int pathIndex = 0;


			int leftId = portals[0];
			int rightId = portals[1];

			int currentID = -1;

			float* left = &points[leftId * 3];
			float* right = &points[rightId * 3];

			float* current = start;


			path[pathIndex++] = start[0];
			path[pathIndex++] = start[1];

			for (int portal = 1; portal < num_portals; portal++)
			{

				portalLeftID = portals[portal * 2];
				portalRightID = portals[portal * 2 + 1];

				portalLeft = &points[portalLeftID * 3];
				portalRight = &points[portalRightID * 3];

				// left
				if (portals[portal * 2] != leftId)
				{

					if (triarea2(current, portalLeft, left) < 0)
					{
						// новая грань правее левой стороны
						if (triarea2(current, portalLeft, right) >= 0)
						{
							// новое ребро не пересекает и левее правой стороны
							leftId = portals[portal * 2];
							left = &points[leftId * 3];
						}
						else
						{
							// новое левое ребро пересекает правую сторону

							current = right;
							currentID = rightId;
							path[pathIndex++] = current[0];
							path[pathIndex++] = current[1];
							left = &points[portals[portal * 2] * 3];
							right = &points[portals[portal * 2 + 1] * 3];

							continue;
						}
					}
				}

				// right
				if (portals[portal * 2 + 1] != rightId)
				{

					if (triarea2(current, portalRight, right) > 0)
					{
						// новая грань левее правой стороны

						
						if (triarea2(current, portalRight, left) <= 0)
						{
							// новое ребро не пересекает и правее левой стороны
							rightId = portals[portal * 2 + 1];
							right = &points[rightId * 3];
						}
						else
						{
							// новое левое ребро пересекает правую сторону
							current = left;
							currentID = leftId;
							path[pathIndex++] = current[0];
							path[pathIndex++] = current[1];
							left = &points[portals[portal * 2] * 3];
							right = &points[portals[portal * 2 + 1] * 3];
							continue;
						}
					}
				}
			}


			// left
			portalLeft = end;
			if (triarea2(current, portalLeft, left) < 0)
			{
				// новая грань правее левой стороны
				if (triarea2(current, portalLeft, right) >= 0)
				{
					// новое ребро не пересекает и левее правой стороны
					left = end;

				}
				else
				{
					// новое левое ребро пересекает правую сторону
					current = right;
					path[pathIndex++] = current[0];
					path[pathIndex++] = current[1];
				}
			}

			portalRight = end;
			if (triarea2(current, portalRight, right) > 0)
			{
				// новая грань левее правой стороны
				if (triarea2(current, portalRight, left) <= 0)
				{
					right = end;
				}
				else
				{
					// новое левое ребро пересекает правую сторону
					current = left;
					path[pathIndex++] = current[0];
					path[pathIndex++] = current[1];
				}
			}

			path[pathIndex++] = end[0];
			path[pathIndex++] = end[1];

			path_size = pathIndex;
		}

	}
}
