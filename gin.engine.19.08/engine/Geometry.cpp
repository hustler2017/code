#include "pch.h"
#include "Geometry.h"

namespace Engine
{
	void Geometry::setVertexCount(int count)
	{
		m_verticies.clear();
		m_verticies.reserve(count);
	}

	void Geometry::setVertexNormal(int vertex, Vector3& normal)
	{
		m_verticies[vertex].normal = normal;
	}

	void Geometry::setVertexBone(int vertex, int slot, int bone, float weight){}

	void Geometry::setVertexUV(int vertex, int slot, Vector2& uv)
	{
		m_verticies[vertex].uv = uv;
	}

	void Geometry::setVertexCoords(int vertex, Vector3& coordinates)
	{
		m_verticies[vertex].coordinates = coordinates;
	}

	int Geometry::getStride()
	{
		return sizeof(Vertex);
	}

	void* Geometry::getVertexBuffer()
	{
		return &m_verticies[0];
	}

	bool Geometry::hasIndices()
	{
		return false;
	}

	int Geometry::getVertexCount()
	{
		return m_verticies.size();
	}

	int Geometry::getIndicesCount()
	{
		return 0;
	}

	unsigned int* Geometry::getIndicesBuffer()
	{
		return nullptr;
	}

	int Geometry::getVertexBufferSize()
	{
		return m_verticies.size() * sizeof(Vertex);
	}

	int Geometry::getIndicesBufferSize()
	{
		return 0;
	}

	Vector3 Geometry::getVertexCoordinates(int vertexIndex)
	{
		return m_verticies[vertexIndex].coordinates;
	}

	Vector3 Geometry::getVertexNormal(int vertexIndex)
	{
		return m_verticies[vertexIndex].normal;
	}

	Vector2 Geometry::getVertexUV(int vertexIndex, int channelIndex)
	{
		return m_verticies[vertexIndex].uv;
	}

	Vector4 Geometry::getVertexColor(int vertexIndex)
	{
		return Vector4(0, 0, 0, 0);
	}
}