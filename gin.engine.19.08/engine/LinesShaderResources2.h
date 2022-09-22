#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "Common.h"

namespace Engine {

    class LinesShaderResources2 
    {
    public:
        struct Vertex
        {
            Vector3 coordinates;
            Vector4 color;
        };
    public:
        ID3D11Buffer* m_pVertexBuffer;
        int m_vertexCount;

        LinesShaderResources2();
        ~LinesShaderResources2();

        void Release();
        ID3D11Buffer* getVertexBuffer();
        UINT getStride();
        UINT getVertexCount();
    };
}

