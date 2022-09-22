#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "Mesh.h"
#include "MeshShaderResources.h"

namespace Engine {
    
    class LinesShaderResources : public MeshShaderResources
    {
    protected:

        struct Vertex
        {
            Vector3 coordinates;
            Vector4 color;
        };

        ID3D11Buffer* m_pVertexBuffer;
        int m_vertexCount;

    public:
        LinesShaderResources(Graphics::Direct3D* d3d, Mesh* mesh);
        ~LinesShaderResources();

        void Release();

        void update();
        ID3D11Buffer* getVertexBuffer();
        UINT getStride();
        UINT getVertexCount();

        IMeshShader* getShader() { return nullptr; }
    };
}

