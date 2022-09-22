#include "pch.h"
#include "AnimatedMeshShader.h"
#include "AnimatedMeshShaderResources.h"
#include "IMeshShaderResources.h"


namespace Engine
{
	AnimatedMeshShader::AnimatedMeshShader(Graphics::Direct3D* d3d, IEngineSettings* settings)
		: Shader(d3d)
	{
		m_shaderFileName = settings->getPath(L"shaders") + std::wstring(L"animated_mesh_shader.fx");
		m_vertexShaderFuncName = "vertexShader";
		m_pixelShaderFuncName = "pixelShader";

		D3D11_INPUT_ELEMENT_DESC inputLayoutDesc[] = {
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "BONEID", 0, DXGI_FORMAT_R32G32B32A32_UINT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "BONEWEIGHT", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};

		m_layoutDesc = new InputLayoutDesc(inputLayoutDesc, 5);

		load();

		createConstantBuffer();
	}

	AnimatedMeshShader::~AnimatedMeshShader()
	{
		SAFE_RELEASE(m_pConstantBuffer);
	}

	void AnimatedMeshShader::createResources(Mesh* mesh)
	{
		mesh->setShaderResources(new AnimatedMeshShaderResources(m_d3d, mesh), getName());
	}

	void AnimatedMeshShader::createConstantBuffer()
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = MAX_MATRICES * sizeof(DirectX::XMMATRIX);
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		desc.MiscFlags = 0;
		desc.StructureByteStride = 0;

		if (FAILED(m_d3d->pDevice->CreateBuffer(&desc, 0, &m_pConstantBuffer)))
			throw false;
	}

	std::string getName()
	{
		return std::string("animesh_shader");
	}

	void AnimatedMeshShader::render(Mesh* mesh)
	{
		IMeshShaderResources* res = mesh->getShaderResources(getName());
		AnimatedMeshShaderResources* resources = dynamic_cast<AnimatedMeshShaderResources*>(res);
		MeshAnimation* animation = mesh->getCurrentAnimation();

		if (animation == nullptr) 
			return;

		UINT stride = resources->getStride();
		UINT offset = 0;

		ID3D11Buffer* buffer[] = { resources->getVertexBuffer() };

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
		m_d3d->pContext->VSSetConstantBuffers(2, 1, &m_pConstantBuffer);
		m_d3d->pContext->UpdateSubresource(m_pConstantBuffer, 0, 0, animation->getMatricesAtCurrentFrame(), 0, 0);
		m_d3d->pContext->IASetVertexBuffers(0, 1, buffer, &stride, &offset);
		m_d3d->pContext->Draw(resources->getVertexCount(), 0);
	}

	std::string AnimatedMeshShader::getName()
	{
		return "AnimatedMeshShader";
	}

}