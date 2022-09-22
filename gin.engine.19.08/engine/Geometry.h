#pragma once

#include "IGeometry.h"
#include <vector>

namespace Engine
{
	class Geometry : public IGeometry
	{

	private:

		struct Vertex
		{
			Vector3 coordinates;
			Vector3 normal;
			Vector2 uv;
		};

		std::vector<Vertex> m_verticies;

	public:
		Geometry() {};
		~Geometry() {};

		void setVertexCount(int count);
		void setVertexNormal(int vertex, Vector3& normal);
		void setVertexBone(int vertex, int slot, int bone, float weight);
		void setVertexUV(int vertex, int slot, Vector2& uv);
		void setVertexCoords(int vertex, Vector3& coordinates);
		int getStride();
		void* getVertexBuffer();
		bool hasIndices();
		int getVertexCount();
		int getIndicesCount();
		unsigned int* getIndicesBuffer();
		int getVertexBufferSize();
		int getIndicesBufferSize();
		Vector3 getVertexCoordinates(int vertexIndex);
		Vector3 getVertexNormal(int vertexIndex);
		Vector2 getVertexUV(int vertexIndex, int channelIndex);
		Vector4 getVertexColor(int vertexIndex);
	};

}