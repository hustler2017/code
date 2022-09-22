#pragma once



namespace Engine
{

	class MeshGeometry
	{
	protected:

		int m_verticies_count;
		int m_indices_count;
		bool has_indices;
		bool has_bone_ids;

		unsigned int* m_indices;

	public:
		MeshGeometry() : m_indices(nullptr), m_indices_count(0), m_verticies_count(0) {}
		virtual ~MeshGeometry() {};

		bool hasIndices() { return has_indices; }

		int getVerticiesCount() { return m_verticies_count; }
		int getIndicesCount() { return m_indices_count; }
		unsigned int* getIndices() { return m_indices; }

		virtual void setBufferSize(int vertexCount) {}
		virtual void setVertexCoords(int vertex, float x, float y, float z) {}
		virtual void setVertexNormal(int vertex, float x, float y, float z) {}
		virtual void setVertexBone(int vertex, int slot, int bone, float weight) {}
		virtual void setVertexUV(int vertex, int slot, float u, float v) {}
		virtual int getStride() { return 0; }
		virtual void* getVerticies() { return nullptr; }

		virtual int getVertexDataSize() { return 0; };


	};


}

