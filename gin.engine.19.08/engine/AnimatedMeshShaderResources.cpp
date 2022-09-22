#include "pch.h"
#include "AnimatedMeshShaderResources.h"


namespace Engine
{
	AnimatedMeshShaderResources::AnimatedMeshShaderResources(Graphics::Direct3D* d3d, Mesh* mesh)
		: MeshShaderResources(d3d, mesh)
	{
		createData();

		ShaderHelper::createVertexBuffer(d3d->pDevice, &m_pVertexBuffer, data, m_vertexCount * sizeof(Vertex));

		delete[] data;
	}


	void AnimatedMeshShaderResources::createData()
	{
		IVertexData* vertexData = m_mesh->getVertexData();
		UINT num_polygons = vertexData->getPolygonCount();

		m_vertexCount = num_polygons * 3;

		data = new Vertex[m_vertexCount];

		int vertex_index = 0;
		for (int p = 0; p < num_polygons; p++)
		{
			for (int v = 0; v < 3; v++)
			{
				UINT index = vertexData->getPolygonVertex(p, v);
				data[vertex_index].position = vertexData->getCoordinates(index);
				data[vertex_index].normal = vertexData->getNormal(index);
				data[vertex_index].uv = vertexData->getUV(0, index);
				for (int k = 0; k < 4; k++)
				{
					data[vertex_index].bone_id[k] = vertexData->getBoneIndex(k, index);
					data[vertex_index].weight[k] = vertexData->getBoneWeight(k, index);
				}
				vertex_index++;
			}
		}
	}


	AnimatedMeshShaderResources::~AnimatedMeshShaderResources()
	{
		Release();
	}

	void AnimatedMeshShaderResources::Release()
	{
		SAFE_RELEASE(m_pVertexBuffer);
	}

	void AnimatedMeshShaderResources::UpdateSubresource()
	{
		m_d3d->pContext->UpdateSubresource(m_pVertexBuffer, 0, 0, data, 0, 0);
	}


	ID3D11Buffer* AnimatedMeshShaderResources::getVertexBuffer()
	{
		return m_pVertexBuffer;
	}

	UINT AnimatedMeshShaderResources::getStride()
	{
		return sizeof(Vertex);
	}

	UINT AnimatedMeshShaderResources::getVertexCount()
	{
		return m_vertexCount;
	}

	void AnimatedMeshShaderResources::update()
	{
		createData();
		UpdateSubresource();
		delete[] data;
	}
}