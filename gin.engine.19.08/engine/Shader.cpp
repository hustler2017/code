#include "pch.h"
#include "Shader.h"
#include <d3d11.h>   
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <DxErr.h>

namespace Engine
{
	Shader::Shader(Graphics::Direct3D* d3d) : 
		m_d3d(d3d), 
		m_pVertexShader(nullptr), 
		m_pPixelShader(nullptr), 
		m_pInputLayout(nullptr),
		m_layoutDesc(nullptr) 
	{}

	Shader::~Shader() {
	
		SAFE_RELEASE(m_pVertexShader);
		SAFE_RELEASE(m_pPixelShader);
		SAFE_RELEASE(m_pInputLayout);
	}

	ID3D11VertexShader* Shader::getVertexShader()
	{
		return m_pVertexShader;
	}

	ID3D11PixelShader* Shader::getPixelShader()
	{
		return m_pPixelShader;
	}

	void Shader::load()
	{
		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
		ID3DBlob* errorBuffer = nullptr;
		ID3DBlob* vsBuffer = nullptr;
		ID3DBlob* psBuffer = nullptr;

		try
		{
			if (FAILED(D3DX11CompileFromFile(
				m_shaderFileName.c_str(),
				0,
				0,
				m_vertexShaderFuncName.c_str(),
				"vs_4_0",
				shaderFlags,
				0,
				0,
				&vsBuffer,
				&errorBuffer,
				0
			))) throw false;

			if (FAILED(m_d3d->pDevice->CreateVertexShader(
				vsBuffer->GetBufferPointer(),
				vsBuffer->GetBufferSize(),
				0,
				&m_pVertexShader
			))) throw false;


			if (FAILED(D3DX11CompileFromFile(
				m_shaderFileName.c_str(),
				0,
				0,
				m_pixelShaderFuncName.c_str(),
				"ps_4_0",
				shaderFlags,
				0,
				0,
				&psBuffer,
				&errorBuffer,
				0
			))) throw false;

			if (FAILED(m_d3d->pDevice->CreatePixelShader(
				psBuffer->GetBufferPointer(),
				psBuffer->GetBufferSize(),
				0,
				&m_pPixelShader
			))) throw false;

			if (FAILED(m_d3d->pDevice->CreateInputLayout(
				m_layoutDesc->getLayout(),
				m_layoutDesc->getLayoutElementsCount(),
				vsBuffer->GetBufferPointer(),
				vsBuffer->GetBufferSize(),
				&m_pInputLayout
			))) throw false;


			SAFE_RELEASE(errorBuffer);
			SAFE_RELEASE(psBuffer);
			SAFE_RELEASE(vsBuffer);
		}
		catch (bool)
		{
			SAFE_RELEASE(vsBuffer);
			SAFE_RELEASE(psBuffer);
			SAFE_RELEASE(m_pVertexShader);
			SAFE_RELEASE(m_pPixelShader);
			

			if (errorBuffer) {
				OutputDebugStringA((char*)errorBuffer->GetBufferPointer());
				SAFE_RELEASE(errorBuffer);
			}
			throw 0;
		}
	}
}

