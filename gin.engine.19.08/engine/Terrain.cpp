#include "pch.h"
#include "Terrain.h"


namespace Engine
{
	Terrain::Terrain() 
		: m_need_update(false)
	{
		m_tiling[0] = { 1.0f , 1.0f };
		m_tiling[1] = { 1.0f , 1.0f };
		m_tiling[2] = { 1.0f , 1.0f };
		m_tiling[3] = { 1.0f , 1.0f };
		m_tiling[4] = { 1.0f , 1.0f };
	}

	Terrain::~Terrain()
	{

	}

	void Terrain::init()
	{
		calculateSize();
		m_vertexData.setUVChannelCount(5);
		m_vertexData.setUVCount(m_vertexData.getCoordinatesCount());
	}


	Vector2 Terrain::getTiling(int channel)
	{
		if (channel < 5)
		{
			return m_tiling[channel];
			m_need_update = true;
		}

		return Vector2(1, 1);
	}

	void Terrain::setTiling(int channel, Vector2 tiling)
	{
		if (channel < 5)
		{
			m_tiling[channel] = tiling;
			updateUVChannel(channel);
			updateResources();
		}
	}

	

	void Terrain::calculateSize()
	{
		int vertexCount = m_vertexData.getCoordinatesCount();
		if (vertexCount == 0)
		{
			OutputDebugString(L"Terrain::calculateSize : нет вершин");
			return;
		}

		Vector3 coords = m_vertexData.getCoordinates(0);

		float min_x = coords.x;
		float max_x = coords.x;

		float min_y = coords.y;
		float max_y = coords.y;

		for (int i = 1; i < vertexCount; i++)
		{
			coords = m_vertexData.getCoordinates(i);
			if (coords.x < min_x) min_x = coords.x;
			if (coords.x > max_x) max_x = coords.x;
			if (coords.y < min_y) min_y = coords.y;
			if (coords.y > max_y) max_y = coords.y;
		}

		m_size = Vector2(max_x - min_x, max_y - min_y);
	}

	void Terrain::updateUVChannel(int channel)
	{
		int vertexCount = m_vertexData.getCoordinatesCount();

		float tileSizeX = m_size.x / m_tiling[channel].x;
		float tileSizeY = m_size.y / m_tiling[channel].y;

		Vector3 coords;
		for (int i = 0; i < vertexCount; i++)
		{
			coords = m_vertexData.getCoordinates(i);
			m_vertexData.setUV(channel, i, Vector2(
				coords.x / tileSizeX, 
				coords.y / tileSizeY
			));
		}
	}

}