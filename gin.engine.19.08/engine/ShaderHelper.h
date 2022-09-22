#pragma once
#include "Direct3D.h"
#include <string>
#include "InputLayout.h"

namespace Engine
{
	class ShaderHelper
	{
	public:
		static bool loadVertexShader(
			std::wstring filename,
			std::string funcname,
			ID3D11VertexShader* pVertexShader,
			ID3D11InputLayout* pInputLaypout,
			InputLayoutDesc* m_layoutDesc,
			ID3D11Device* device
		);

		static bool loadVertexShader(
			std::wstring filename,
			std::string funcname,
			ID3D11VertexShader** ppVertexShader,
			ID3D11Device* device
		);

		static bool loadPixelShader(
			std::wstring filename,
			std::string funcname,
			ID3D11PixelShader* pPixelShader,
			ID3D11Device* device
		);



		static void createIndexBuffer(ID3D11Device* device, ID3D11Buffer** ppIndexBuffer, void* indexData, int byteWidth);

		static void createVertexBuffer(ID3D11Device* device, ID3D11Buffer** ppVertexBuffer, void* vertexData, int byteWidth);
	};

}

