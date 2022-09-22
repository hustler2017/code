#include "pch.h"
#include "SolidShaderResources.h"
#include "ShaderHelper.h"

namespace Engine
{
    SolidShaderResources::SolidShaderResources(Graphics::Direct3D* d3d, Mesh* mesh)
        : MeshShaderResources(d3d, mesh)
    {
        IVertexData* vertexData = mesh->getVertexData();
        unsigned int polygonCount = vertexData->getPolygonCount();
        m_vertexCount = 3 * polygonCount;

        Vertex* verticies = new Vertex[m_vertexCount];

        unsigned int j, l;
        for (unsigned int i = 0; i < polygonCount; i++)
        {
            for (unsigned int k = 0; k < 3; k++)
            {
                j = i * 3 + k;
                l = vertexData->getPolygonVertex(i, k);

                verticies[j].coordinates = vertexData->getCoordinates(l);
                verticies[j].color = vertexData->getColor(l);
            }
        }


        ShaderHelper::createVertexBuffer(d3d->pDevice, &m_pVertexBuffer, verticies, m_vertexCount * sizeof(Vertex));

        delete[] verticies;
    }

    SolidShaderResources::~SolidShaderResources()
    {
        Release();
    }

    void SolidShaderResources::Release()
    {
        SAFE_RELEASE(m_pVertexBuffer);
    }

    ID3D11Buffer* SolidShaderResources::getVertexBuffer()
    {
        return m_pVertexBuffer;
    }

    UINT SolidShaderResources::getStride()
    {
        return sizeof(Vertex);
    }
    UINT SolidShaderResources::getVertexCount()
    {
        return m_vertexCount;
    }

    void SolidShaderResources::update()
    {
        IVertexData* vertexData = m_mesh->getVertexData();
        unsigned int polygonCount = vertexData->getPolygonCount();
        m_vertexCount = 3 * polygonCount;

        Vertex* verticies = new Vertex[m_vertexCount];

        unsigned int j, l;
        for (unsigned int i = 0; i < polygonCount; i++)
        {
            for (unsigned int k = 0; k < 3; k++)
            {
                j = i * 3 + k;
                l = vertexData->getPolygonVertex(i, k);

                verticies[j].coordinates = vertexData->getCoordinates(l);
                verticies[j].color = vertexData->getColor(l);
            }
        }

        m_d3d->pContext->UpdateSubresource(m_pVertexBuffer, 0, 0, verticies, 0, 0);

        delete[] verticies;

    }
}