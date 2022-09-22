#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "InputLayout.h"
#include <string>

namespace Engine
{
	class Shader
	{
	protected:
		Graphics::Direct3D* m_d3d;

		std::string m_vertexShaderFuncName;
		std::string m_pixelShaderFuncName;
		std::wstring m_shaderFileName;

		ID3D11VertexShader* m_pVertexShader;
		ID3D11PixelShader* m_pPixelShader;
		ID3D11InputLayout* m_pInputLayout;

		InputLayoutDesc* m_layoutDesc;

	protected:
		void load();
	public:
		Shader(Graphics::Direct3D* d3d);
		~Shader();

		ID3D11VertexShader* getVertexShader();
		ID3D11PixelShader* getPixelShader();
	};
}
