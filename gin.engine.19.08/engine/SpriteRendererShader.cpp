#include "pch.h"
#include "SpriteRendererShader.h"


namespace Engine
{

	SpriteRendererShader::SpriteRendererShader(Graphics::Direct3D* d3d) : Shader(d3d)
	{
		D3D11_INPUT_ELEMENT_DESC inputLayoutDesc[] = {
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "POSITION", 1, DXGI_FORMAT_R32G32B32_FLOAT, 1, 0, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
			{ "TEXID", 0, DXGI_FORMAT_R32G32B32_FLOAT, 1, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_INSTANCE_DATA, 1 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};

		load(m_d3d->pDevice, L"sprite_renderer_shader.fx", "vertexShader", "pixelShader", inputLayoutDesc, 4);
	}
	SpriteRendererShader::~SpriteRendererShader()
	{

	}

	void SpriteRendererShader::setup()
	{
		m_d3d->pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		m_d3d->pContext->IASetInputLayout(m_pInputLayout);
		m_d3d->pContext->VSSetShader(m_pVertexShader, 0, 0);
		m_d3d->pContext->PSSetShader(m_pPixelShader, 0, 0);
	}



}
