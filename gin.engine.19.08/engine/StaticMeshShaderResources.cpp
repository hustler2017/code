#include "pch.h"
#include "StaticMeshShaderResources.h"
#include "ShaderHelper.h"


namespace Engine
{
    StaticMeshShaderResources::StaticMeshShaderResources(Graphics::Direct3D* d3d, Mesh* mesh) 
    {
        IVertexData* vertexData = mesh->getVertexData();
        unsigned int polygonCount = vertexData->getPolygonCount();
        m_vertexCount = 3 * polygonCount;

        Vertex* verticies = new Vertex[m_vertexCount];
        unsigned int j,l;
        for (unsigned int i = 0; i < polygonCount; i++)
        {
            for (unsigned int k = 0; k < 3; k++)
            {
                j = i * 3 + k;
                l = vertexData->getPolygonVertex(i, k);
                verticies[j].coordinates = vertexData->getCoordinates(l);
                verticies[j].normals = vertexData->getNormal(l);
                verticies[j].uv = vertexData->getUV(0, l);
            }
        }

        ShaderHelper::createVertexBuffer(d3d->pDevice, &m_pVertexBuffer, verticies, m_vertexCount * sizeof(Vertex));

        delete[] verticies;
    }

    StaticMeshShaderResources::~StaticMeshShaderResources()
    {
        Release();
    }

    void StaticMeshShaderResources::Release()
    {
        SAFE_RELEASE(m_pVertexBuffer);
    }

    ID3D11Buffer* StaticMeshShaderResources::getVertexBuffer()
    {
        return m_pVertexBuffer;
    }

    UINT StaticMeshShaderResources::getStride()
    {
        return sizeof(Vertex);
    }

    UINT StaticMeshShaderResources::getVertexCount()
    {
        return m_vertexCount;
    }

    void StaticMeshShaderResources::update()
    {

    }
}