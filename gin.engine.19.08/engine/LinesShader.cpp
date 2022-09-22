#include "pch.h"
#include "LinesShader.h"
#include "LinesShaderResources.h"


namespace Engine
{
    LinesShader::LinesShader(Graphics::Direct3D* d3d, IEngineSettings* settings) : Shader(d3d)
    {
        m_shaderFileName = settings->getPath(L"shaders") +  std::wstring(L"lines_shader.fx");
        m_vertexShaderFuncName = "vertexShader";
        m_pixelShaderFuncName = "pixelShader";

        D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };

        m_layoutDesc = new InputLayoutDesc(layoutDesc, 2);

        load();
    }

    LinesShader::~LinesShader()
    {
        delete m_layoutDesc;
    }

    void LinesShader::createResources(Mesh* mesh)
    {
        LinesShaderResources* ress = new LinesShaderResources(m_d3d, mesh);
        mesh->setShaderResources(ress, getName());
    }

    std::string LinesShader::getName()
    {
        return std::string("lines_shader");
    }

    void LinesShader::render(Mesh* mesh)
    {
        LinesShaderResources* resources = dynamic_cast<LinesShaderResources*>(mesh->getShaderResources(getName()));

        UINT offset = 0;
        UINT stride = resources->getStride();
        ID3D11Buffer* pVertexBuffer = resources->getVertexBuffer();

        m_d3d->pContext->IASetInputLayout(m_pInputLayout);
        m_d3d->pContext->VSSetShader(m_pVertexShader, 0, 0);
        m_d3d->pContext->PSSetShader(m_pPixelShader, 0, 0);
        m_d3d->pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
        m_d3d->pContext->IASetVertexBuffers(0, 1, &pVertexBuffer, &stride, &offset);
        m_d3d->pContext->Draw(resources->getVertexCount(), 0);
    }

    void LinesShader::render(LinesShaderResources2* resources)
    {
        UINT offset = 0;
        UINT stride = resources->getStride();
        ID3D11Buffer* pVertexBuffer = resources->getVertexBuffer();

        m_d3d->pContext->IASetInputLayout(m_pInputLayout);
        m_d3d->pContext->VSSetShader(m_pVertexShader, 0, 0);
        m_d3d->pContext->PSSetShader(m_pPixelShader, 0, 0);
        m_d3d->pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
        m_d3d->pContext->IASetVertexBuffers(0, 1, &pVertexBuffer, &stride, &offset);
        m_d3d->pContext->Draw(resources->getVertexCount(), 0);
    }
}