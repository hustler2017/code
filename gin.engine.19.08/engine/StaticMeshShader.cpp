#include "pch.h"
#include "StaticMeshShader.h"
#include "StaticMeshShaderResources.h"

namespace Engine
{
    StaticMeshShader::StaticMeshShader(Graphics::Direct3D* d3d, IEngineSettings* settings) : Shader(d3d)
    {
        m_shaderFileName = settings->getPath(L"shaders") + std::wstring(L"mesh_shader.fx"); 
        m_vertexShaderFuncName = "vertexShader";
        m_pixelShaderFuncName = "pixelShader";

        D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 }
        };

        m_layoutDesc = new InputLayoutDesc(layoutDesc, 3);

        load();
    }



    StaticMeshShader::~StaticMeshShader()
    {
        delete m_layoutDesc;
    }

    void StaticMeshShader::createResources(Mesh* mesh)
    {
        mesh->setShaderResources(new StaticMeshShaderResources(m_d3d, mesh), getName());
    }

    void StaticMeshShader::render(Mesh* mesh)
    {
        StaticMeshShaderResources* resources = dynamic_cast<StaticMeshShaderResources*>(mesh->getShaderResources(getName()));

        UINT offset = 0;
        UINT stride = resources->getStride();
        ID3D11Buffer* pVertexBuffer = resources->getVertexBuffer();

        std::vector<std::wstring>* textureFiles = mesh->getTextures();
        std::vector<ID3D11ShaderResourceView*> txs;

        for (int i = 0; i < textureFiles->size(); i++)
        {
            txs.push_back(m_d3d->createTexture(textureFiles->at(i)));
        }

        m_d3d->pContext->PSSetShaderResources(0, txs.size(), &txs[0]);
        m_d3d->pContext->IASetInputLayout(m_pInputLayout);
        m_d3d->pContext->VSSetShader(m_pVertexShader, 0, 0);
        m_d3d->pContext->PSSetShader(m_pPixelShader, 0, 0);
        m_d3d->pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        m_d3d->pContext->IASetVertexBuffers(0, 1, &pVertexBuffer, &stride, &offset);
        m_d3d->pContext->Draw(resources->getVertexCount(), 0);
    }

    std::string StaticMeshShader::getName()
    {
        return std::string("static_mesh");
    }

}