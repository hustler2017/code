#include "pch.h"
#include "TerrainShader.h"

namespace Engine
{
	TerrainShader::TerrainShader(Graphics::Direct3D* d3d, IEngineSettings* settings) : Shader(d3d)
	{
			m_shaderFileName = settings->getPath(L"shaders") + std::wstring(L"terrain_shader.fx");
			m_vertexShaderFuncName = "vertexShader";
			m_pixelShaderFuncName = "pixelShader";

		D3D11_INPUT_ELEMENT_DESC inputLayoutDesc[] = {
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 1, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 2, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 3, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 4, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 5, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		};

		m_layoutDesc = new InputLayoutDesc(inputLayoutDesc, 7);

		load();
	}

	void TerrainShader::createResources(Mesh* mesh)
	{
		mesh->setShaderResources(new TerrainShaderResources(m_d3d, mesh), getName());
	}

	void TerrainShader::render(Mesh* terrain)
	{
		TerrainShaderResources* resources = dynamic_cast<TerrainShaderResources*>(terrain->getShaderResources(getName()));
		if (resources == nullptr) return;

		UINT offset = 0;
		UINT stride = resources->getStride();
		ID3D11Buffer* pVertexBuffer = resources->getVertexBuffer();
		ID3D11Buffer* pIndexBuffer = resources->getIndexBuffer();
		UINT indicesCount = resources->getIndicesCount();

		std::vector<std::wstring>* textureFiles = terrain->getTextures();
		ID3D11ShaderResourceView* textures[5];
		for (int i = 0; i < 5; i++)
		{
			textures[i] = m_d3d->createTexture(textureFiles->at(i));
		}

		m_d3d->pContext->IASetInputLayout(m_pInputLayout);
		m_d3d->pContext->VSSetShader(m_pVertexShader, 0, 0);
		m_d3d->pContext->PSSetShader(m_pPixelShader, 0, 0);
		m_d3d->pContext->PSSetShaderResources(0, 5, textures);
		m_d3d->pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		m_d3d->pContext->IASetVertexBuffers(0, 1, &pVertexBuffer, &stride, &offset);
		m_d3d->pContext->IASetIndexBuffer(pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
		m_d3d->pContext->DrawIndexed(indicesCount, 0, 0);
	}

	
	TerrainShader::~TerrainShader() {}


	std::string TerrainShader::getName()
	{
		return "terrain_shader";
	}
}

