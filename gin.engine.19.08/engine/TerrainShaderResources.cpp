#include "pch.h"
#include "TerrainShaderResources.h"
#include "ShaderHelper.h"

namespace Engine
{
	TerrainShaderResources::TerrainShaderResources(Graphics::Direct3D* d3d, Mesh* mesh) 
		: MeshShaderResources(d3d, mesh),
		m_pVertexBuffer(nullptr),
		m_pIndexBuffer(nullptr)
	{
		Vertex* vertexData;
		UINT* indexData;

		createBuffersData(
			&vertexData, 
			&m_vertex_count,
			&indexData, 
			&m_indices_count, 
			m_mesh
		);

		ShaderHelper::createVertexBuffer(m_d3d->pDevice, &m_pVertexBuffer, vertexData, m_vertex_count * sizeof(Vertex));
		ShaderHelper::createIndexBuffer(m_d3d->pDevice , &m_pIndexBuffer, indexData, m_indices_count * sizeof(UINT));

		delete[] vertexData;
		delete[] indexData;
	}

	void TerrainShaderResources::createBuffersData(Vertex** vBuff, UINT* vertex_count,  UINT** indBuff, UINT* indices_count, Mesh* mesh)
	{
		IVertexData* vertexData = mesh->getVertexData();
		UINT num_polygons = vertexData->getPolygonCount();
		UINT num_verticies = num_polygons * 3;
		Vertex* verticies = new Vertex[num_verticies];
		UINT* index_data = new UINT[num_verticies];
		
		int i = 0;
		int v;
		for (int p = 0; p < num_polygons; p++)
		{
			for (int l = 0; l < 3; l++)
			{
				v = vertexData->getPolygonVertex(p, l);
				verticies[i].position = vertexData->getCoordinates(v);
				verticies[i].normal = vertexData->getNormal(v);
				verticies[i].tex_uv[0] = vertexData->getUV(0, v);
				verticies[i].tex_uv[1] = vertexData->getUV(1, v);
				verticies[i].tex_uv[2] = vertexData->getUV(2, v);
				verticies[i].tex_uv[3] = vertexData->getUV(3, v);
				verticies[i].mask_uv = vertexData->getUV(4, v);
				index_data[i] = i++;
			}
		}

		*indices_count = i;
		*vertex_count = num_verticies;

		*vBuff = verticies;
		*indBuff = index_data;
	}

	TerrainShaderResources::~TerrainShaderResources()
	{
		Release();
	}

	ID3D11Buffer* TerrainShaderResources::getVertexBuffer()
	{
		return m_pVertexBuffer;
	}
	
	ID3D11Buffer* TerrainShaderResources::getIndexBuffer()
	{
		return m_pIndexBuffer;
	}

	UINT TerrainShaderResources::getStride()
	{
		return sizeof(Vertex);
	}

	UINT TerrainShaderResources::getVertexCount()
	{
		return m_vertex_count;
	}
	UINT TerrainShaderResources::getIndicesCount()
	{
		return m_indices_count;
	}

	void TerrainShaderResources::Release()
	{
		SAFE_RELEASE(m_pVertexBuffer);
		SAFE_RELEASE(m_pIndexBuffer);
	}

	void TerrainShaderResources::update()
	{
		Vertex* vertexData;
		UINT* indexData;

		createBuffersData(
			&vertexData,
			&m_vertex_count,
			&indexData,
			&m_indices_count,
			m_mesh
		);

		m_d3d->pContext->UpdateSubresource(m_pVertexBuffer, 0, 0, vertexData, 0, 0);
		m_d3d->pContext->UpdateSubresource(m_pIndexBuffer, 0, 0, indexData, 0, 0);

		delete[] vertexData;
		delete[] indexData;
	}


}
