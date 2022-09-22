#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "IMeshShaderResources.h"
#include "Mesh.h"

namespace Engine {

    class StaticMeshShaderResources : public IMeshShaderResources
    {
        struct Vertex
        {
            Vector3 coordinates;
            Vector3 normals;
            Vector2 uv;
        };

        ID3D11Buffer* m_pVertexBuffer;

        UINT m_vertexCount;

    public:

        StaticMeshShaderResources(Graphics::Direct3D* d3d, Mesh* mesh);
        ~StaticMeshShaderResources();

        void Release();

        ID3D11Buffer* getVertexBuffer();
        UINT getStride();
        UINT getVertexCount();
        void update();
    };
}
