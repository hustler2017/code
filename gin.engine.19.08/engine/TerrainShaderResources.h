#pragma once
#include "pch.h"
#include "MeshShaderResources.h"
#include "Mesh.h"
#include "TerrainShader.h"
#include "Terrain.h"


namespace Engine
{
	class TerrainShaderResources : public MeshShaderResources
	{
		struct Vertex
		{
			Vector3 position;
			Vector3 normal;
			Vector2 tex_uv[4];
			Vector2 mask_uv;
		};

		ID3D11Buffer* m_pVertexBuffer;
		ID3D11Buffer* m_pIndexBuffer;

		UINT m_vertex_count;
		UINT m_indices_count;

		void createBuffersData(Vertex** vbuff, UINT* vertex_count, UINT** indBuff, UINT* indices_count, Mesh* mesh);
	public:
		ID3D11Buffer* getVertexBuffer();
		ID3D11Buffer* getIndexBuffer();
		UINT getStride();
		UINT getVertexCount();
		UINT getIndicesCount();
	public:
		TerrainShaderResources(Graphics::Direct3D* d3d, Mesh* terrain);
		~TerrainShaderResources();
		void Release();
		void update();
	};

}

