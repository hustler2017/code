#include "GridGeometry.h"
#include <memory.h>


namespace Engine
{

	GridGeometry::GridGeometry()
	{
		float color = 0.2f;
		float size = 100.0f;
		int density = 100;

		m_verticies_count = (density + 1) * 4;
		m_verticies = new Vertex[m_verticies_count];
		memset(m_verticies, 0, m_verticies_count * sizeof(Vertex));

		float start_x = -size / 2;
		float start_y = -size / 2;
		float end_x = size / 2;
		float end_y = size / 2;

		float distance_between_lines = size / density;

		float x, y;
		int index = 0;
		for (int i = 0; i <= density; i++)
		{
			x = start_x + i * distance_between_lines;
			y = start_y + i * distance_between_lines;

			// vertical
			m_verticies[index].r = color;
			m_verticies[index].g = color;
			m_verticies[index].b = color;
			m_verticies[index].a = 1.0f;

			m_verticies[index].x = x;
			m_verticies[index++].y = start_y;

			m_verticies[index].r = color;
			m_verticies[index].g = color;
			m_verticies[index].b = color;
			m_verticies[index].a = 1.0f;

			m_verticies[index].x = x;
			m_verticies[index++].y = end_y;

			// horizontal
			m_verticies[index].r = color;
			m_verticies[index].g = color;
			m_verticies[index].b = color;
			m_verticies[index].a = 1.0f;

			m_verticies[index].x = start_x;
			m_verticies[index++].y = y;

			m_verticies[index].r = color;
			m_verticies[index].g = color;
			m_verticies[index].b = color;
			m_verticies[index].a = 1.0f;

			m_verticies[index].x = end_x;
			m_verticies[index++].y = y;
		}
	}
	GridGeometry::~GridGeometry()
	{
		delete m_verticies;
	}
}
