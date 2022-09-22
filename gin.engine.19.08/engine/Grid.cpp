#include "pch.h"
#include "Grid.h"
#include "VertexDataHelper.h"

namespace Engine
{
	Grid::Grid()
	{
		Mesh* mesh = new Mesh();

		IVertexData* vertexData = mesh->getVertexData();

		size = 40.0f;
		density = 20;

		float color = 0.2f;

		UINT num_verticies = (density + 1) * 4;
		vertexData->setCoordinatesCount(num_verticies);
		vertexData->setColorCount(num_verticies);

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

			vertexData->setCoordinates(index++, Vector3(x, start_y, 0));
			vertexData->setCoordinates(index++, Vector3(x, end_y, 0));
			vertexData->setCoordinates(index++, Vector3(start_x, y, 0));
			vertexData->setCoordinates(index++, Vector3(end_x, y, 0));
		}

		VertexDataHelper::FillColor(vertexData, Vector4(color, color, color, 1));

		m_pModel = new Model();
		m_pModel->m_meshes.push_back(mesh);
	}

	Grid::~Grid() 
	{
		delete m_pModel;
	}


	void Grid::setDensity(float d)
	{
		density = d;
	}

	void Grid::setSize(float s)
	{
		size = s;
	}

	float Grid::getDensity()
	{
		return density;
	}

	float Grid::getSize()
	{
		return size;
	}

}
