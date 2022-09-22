#include "pch.h"
#include "LinesShaderResources2.h"
#include "IVertexData.h"
#include "ShaderHelper.h"

namespace Engine
{
    LinesShaderResources2::LinesShaderResources2()
        : m_pVertexBuffer(nullptr), m_vertexCount(0)
    {
    }

    LinesShaderResources2::~LinesShaderResources2()
    {
        Release();
    }

    ID3D11Buffer* LinesShaderResources2::getVertexBuffer()
    {
        return m_pVertexBuffer;
    }

    UINT LinesShaderResources2::getStride()
    {
        return sizeof(Vertex);
    }

    UINT LinesShaderResources2::getVertexCount()
    {
        return m_vertexCount;
    }

    void LinesShaderResources2::Release()
    {
        SAFE_RELEASE(m_pVertexBuffer);
    }

}
