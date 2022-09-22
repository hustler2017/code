#include "pch.h"
#include "ShaderHelper.h"
#include "Direct3D.h"

namespace Engine
{
	bool ShaderHelper::loadPixelShader(
		std::wstring filename,
		std::string funcname,
		ID3D11PixelShader* pPixelShader,
		ID3D11Device* device
	)
	{
		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
		ID3DBlob* errorBuffer = nullptr;
		ID3DBlob* psBuffer = nullptr;

		try
		{
			if (FAILED(D3DX11CompileFromFile(
				filename.c_str(),
				0,
				0,
				funcname.c_str(),
				"vs_4_0",
				shaderFlags,
				0,
				0,
				&psBuffer,
				&errorBuffer,
				0
			)))
				throw false;

			if (FAILED(device->CreatePixelShader(
				psBuffer->GetBufferPointer(),
				psBuffer->GetBufferSize(),
				0,
				&pPixelShader
			))) throw false;

			SAFE_RELEASE(errorBuffer);
			SAFE_RELEASE(psBuffer);

		}
		catch (bool)
		{
			SAFE_RELEASE(psBuffer);
			SAFE_RELEASE(pPixelShader);

			if (errorBuffer) {
				OutputDebugStringA((char*)errorBuffer->GetBufferPointer());
				SAFE_RELEASE(errorBuffer);
			}

			return false;
		}

		return true;
	}

	bool ShaderHelper::loadVertexShader(
		std::wstring filename,
		std::string funcname,
		ID3D11VertexShader* pVertexShader,
		ID3D11InputLayout* pInputLayout,
		InputLayoutDesc* m_layoutDesc,
		ID3D11Device* device
	)
	{
		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
		ID3DBlob* errorBuffer = nullptr;
		ID3DBlob* vsBuffer = nullptr;

		try
		{
			if (FAILED(D3DX11CompileFromFile(
				filename.c_str(),
				0,
				0,
				funcname.c_str(),
				"vs_4_0",
				shaderFlags,
				0,
				0,
				&vsBuffer,
				&errorBuffer,
				0
			)))
				throw false;

			if (FAILED(device->CreateVertexShader(
				vsBuffer->GetBufferPointer(),
				vsBuffer->GetBufferSize(),
				0,
				&pVertexShader
			))) throw false;

			if (FAILED(device->CreateInputLayout(
				m_layoutDesc->getLayout(),
				m_layoutDesc->getLayoutElementsCount(),
				vsBuffer->GetBufferPointer(),
				vsBuffer->GetBufferSize(),
				&pInputLayout
			))) throw false;

			SAFE_RELEASE(errorBuffer);
			SAFE_RELEASE(vsBuffer);

		}
		catch (bool)
		{
			SAFE_RELEASE(vsBuffer);
			SAFE_RELEASE(pVertexShader);

			if (errorBuffer) {
				OutputDebugStringA((char*)errorBuffer->GetBufferPointer());
				SAFE_RELEASE(errorBuffer);
			}

			return false;
		}

		return true;

	}




	bool ShaderHelper::loadVertexShader(
		std::wstring filename,
		std::string funcname,
		ID3D11VertexShader** ppVertexShader,
		ID3D11Device* device
	)
	{
		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
		ID3DBlob* errorBuffer = nullptr;
		ID3DBlob* vsBuffer = nullptr;

		try
		{
			if (FAILED(D3DX11CompileFromFile(
				filename.c_str(),
				0,
				0,
				funcname.c_str(),
				"vs_4_0",
				shaderFlags,
				0,
				0,
				&vsBuffer,
				&errorBuffer,
				0
			)))
				throw false;

			if (FAILED(device->CreateVertexShader(
				vsBuffer->GetBufferPointer(),
				vsBuffer->GetBufferSize(),
				0,
				ppVertexShader
			))) throw false;

			SAFE_RELEASE(errorBuffer);
			SAFE_RELEASE(vsBuffer);
		}
		catch (bool)
		{
			SAFE_RELEASE(vsBuffer);
			SAFE_RELEASE((*ppVertexShader));

			if (errorBuffer) {
				OutputDebugStringA((char*)errorBuffer->GetBufferPointer());
				SAFE_RELEASE(errorBuffer);
			}

			return false;
		}

		return true;
	}


	void ShaderHelper::createIndexBuffer(ID3D11Device* device, ID3D11Buffer** ppIndexBuffer, void* indexData, int byteWidth)
	{
		D3D11_BUFFER_DESC bufferDesc;
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = byteWidth;
		bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;

		if (indexData != nullptr)
		{
			D3D11_SUBRESOURCE_DATA data;
			data.SysMemPitch = 0;
			data.SysMemSlicePitch = 0;
			data.pSysMem = indexData;

			device->CreateBuffer(&bufferDesc, &data, ppIndexBuffer);
			return;
		}

		device->CreateBuffer(&bufferDesc, 0, ppIndexBuffer);
	}

	void ShaderHelper::createVertexBuffer(ID3D11Device* device, ID3D11Buffer** ppVertexBuffer, void* vertexData, int byteWidth)
	{
		D3D11_BUFFER_DESC bufferDesc;
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = byteWidth;
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;

		if (vertexData != nullptr)
		{
			D3D11_SUBRESOURCE_DATA data;
			data.SysMemPitch = 0;
			data.SysMemSlicePitch = 0;
			data.pSysMem = vertexData;

			device->CreateBuffer(&bufferDesc, &data, ppVertexBuffer);
			return;
		}

		device->CreateBuffer(&bufferDesc, 0, ppVertexBuffer);
	}
}