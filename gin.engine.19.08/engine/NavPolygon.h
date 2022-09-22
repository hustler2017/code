#pragma once

namespace Engine
{
	namespace Navigation
	{
		struct NavPolygon
		{
			int index;
			int adjacent[3];
			unsigned int verticies[3];

			NavPolygon()
			{
				adjacent[0] = -1;
				adjacent[1] = -1;
				adjacent[2] = -1;
				verticies[0] = 0;
				verticies[1] = 0;
				verticies[2] = 0;
			}

			NavPolygon(unsigned int v0, unsigned int v1, unsigned int v2)
			{
				verticies[0] = v0;
				verticies[1] = v1;
				verticies[2] = v2;

				adjacent[0] = -1;
				adjacent[1] = -1;
				adjacent[2] = -1;
			}

			int getAdjacentEdge(int polygon_id)
			{
				for (int i = 0; i < 3; i++)
				{
					if (adjacent[i] == polygon_id)
						return i;
				}

				return -1;
			}

		};
	}
}

