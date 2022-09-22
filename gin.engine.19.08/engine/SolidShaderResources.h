#pragma once
#include "pch.h"
#include "MeshShaderResources.h"
#include "Mesh.h"

namespace Engine {

    class SolidShaderResources : public MeshShaderResources
    {
        struct Vertex
        {
            Vector3 coordinates;
            Vector4 color;
        };

        ID3D11Buffer* m_pVertexBuffer;
        ID3D11Buffer* m_pInstanceBuffer;
        int m_vertexCount;

    public:
        
        SolidShaderResources(Graphics::Direct3D* d3d, Mesh* mesh);
        ~SolidShaderResources();

        void Release();

        ID3D11Buffer* getVertexBuffer();
        UINT getStride();
        UINT getVertexCount();

        void update();


    };
}


    

    