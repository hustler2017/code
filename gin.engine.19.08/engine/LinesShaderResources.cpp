#include "pch.h"
#include "LinesShaderResources.h"
#include "IVertexData.h"
#include "ShaderHelper.h"

namespace Engine
{
	LinesShaderResources::LinesShaderResources(Graphics::Direct3D* d3d, Mesh* mesh) : MeshShaderResources(d3d, mesh)
	{
        IVertexData* vertexData = mesh->getVertexData();
        UINT num_polygons = vertexData->getPolygonCount();
        Vertex* verticies = nullptr;


        if (num_polygons)
        {
            m_vertexCount = num_polygons * 3 * 2;
            verticies = new Vertex[m_vertexCount];

            int vertex_i = 0;
            for (int i = 0; i < num_polygons; i++)
            {
                for (int k = 0, q = 1; k < 3; k++)
                {

                    UINT v1 = vertexData->getPolygonVertex(i, k);
                    UINT v2 = vertexData->getPolygonVertex(i, q);
                    
                    verticies[vertex_i].coordinates = vertexData->getCoordinates(v1);
                    verticies[vertex_i++].color = vertexData->getColor(v1);

                    verticies[vertex_i].coordinates = vertexData->getCoordinates(v2);
                    verticies[vertex_i++].color = vertexData->getColor(v2);

                    if (++q > 2) q = 0;
                }
            }
        }
        else
        {
            UINT pointCount = vertexData->getCoordinatesCount();
            m_vertexCount = pointCount;

            verticies = new Vertex[pointCount];

            for (unsigned int i = 0; i < pointCount; i++)
            {
                verticies[i].coordinates = vertexData->getCoordinates(i);
                verticies[i].color = vertexData->getColor(i);
            }
        }

        ShaderHelper::createVertexBuffer(d3d->pDevice, &m_pVertexBuffer, verticies, m_vertexCount * sizeof(Vertex));

        delete[] verticies;
	}

    LinesShaderResources::~LinesShaderResources()
    {
        Release();
    }

    ID3D11Buffer* LinesShaderResources::getVertexBuffer()
    {
        return m_pVertexBuffer;
    }

    UINT LinesShaderResources::getStride()
    {
        return sizeof(Vertex);
    }

    UINT LinesShaderResources::getVertexCount()
    {
        return m_vertexCount;
    }

    void LinesShaderResources::Release()
    {
        SAFE_RELEASE(m_pVertexBuffer);
    }

    void LinesShaderResources::update()
    {
        IVertexData* vertexData = m_mesh->getVertexData();
        UINT pointCount = vertexData->getCoordinatesCount();
        m_vertexCount = pointCount;

        bool hasColor = vertexData->getColorCount() > 0;

        Vertex* verticies = new Vertex[pointCount];

        for (unsigned int i = 0; i < pointCount; i++)
        {
            verticies[i].coordinates = vertexData->getCoordinates(i);
            verticies[i].color = hasColor ? vertexData->getColor(i) : Vector4(1.0f, 1.0f, 1.0f, 1.0f);
        }

        m_d3d->pContext->UpdateSubresource(m_pVertexBuffer, 0, 0, verticies, 0 ,0);

        delete[] verticies;
    }
	
}
