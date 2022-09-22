#include "pch.h"
#include "ColorShader.h"
#include "SolidShaderResources.h"

namespace Engine 
{
    ColorShader::ColorShader(Graphics::Direct3D* d3d, IEngineSettings* settings) : Shader(d3d)
    {
        m_shaderFileName = settings->getPath(L"shaders") + std::wstring(L"utr.fx");
        m_vertexShaderFuncName = "vertexShader";
        m_pixelShaderFuncName = "pixelShader";

        D3D11_INPUT_ELEMENT_DESC layoutDesc[] = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };

        m_layoutDesc = new InputLayoutDesc(layoutDesc, 2);

        load();
    }

    std::string ColorShader::getName()
    {
        return std::string("color_shader");
    }

    ColorShader::~ColorShader()
    {
        delete m_layoutDesc;
    }

    void ColorShader::createResources(Mesh* mesh)
    {
        mesh->setShaderResources(new SolidShaderResources(m_d3d, mesh), getName());
    }

    void ColorShader::render(Mesh* mesh)
    {
        IMeshShaderResources* res = mesh->getShaderResources(getName());
        if (res == nullptr) return;


        SolidShaderResources* resources = dynamic_cast<SolidShaderResources*>(res);

        UINT offset = 0;
        UINT stride = resources->getStride();
        ID3D11Buffer* pVertexBuffer = resources->getVertexBuffer();

        m_d3d->pContext->IASetInputLayout(m_pInputLayout);
        m_d3d->pContext->VSSetShader(m_pVertexShader, 0, 0);
        m_d3d->pContext->PSSetShader(m_pPixelShader, 0, 0);
        m_d3d->pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        m_d3d->pContext->IASetVertexBuffers(0, 1, &pVertexBuffer, &stride, &offset);
        m_d3d->pContext->Draw(resources->getVertexCount(), 0);
    }
}