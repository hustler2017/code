#pragma once
#include "MeshGeometry.h"


namespace Engine
{
	class GridGeometry : public MeshGeometry
	{

		struct Vertex
		{
			float x;
			float y;
			float z;
			float r;
			float g;
			float b;
			float a;
		};

		Vertex* m_verticies;


	public:
		GridGeometry();
		~GridGeometry();

		int getStride() {
			return sizeof(Vertex);
		}
		void* getVerticies() {
			return m_verticies;
		}
		int getVertexDataSize() {
			return m_verticies_count * sizeof(Vertex);
		};
	};

}

