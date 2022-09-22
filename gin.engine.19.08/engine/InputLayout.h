#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "InputLayoutDesc.h"

namespace Engine
{
	class InputLayout
	{
		ID3D11InputLayout* m_pInputLayout;
		InputLayoutDesc* m_description;

	public:
		InputLayout(InputLayoutDesc* desc, ID3D11Device* device, ID3DBlob* vertexShaderBuffer);
		~InputLayout();

		InputLayoutDesc* getDescription();
		ID3D11InputLayout* getResource();
	};
}


