#include "pch.h"
#include "InputLayout.h"
#include "Common.h"


namespace Engine
{
	InputLayout::InputLayout(InputLayoutDesc* desc, ID3D11Device* device, ID3DBlob* vertexShaderBuffer)
	{
		m_description = desc;

		if (FAILED(device->CreateInputLayout(
			m_description->getLayout(),
			m_description->getLayoutElementsCount(),
			vertexShaderBuffer->GetBufferPointer(),
			vertexShaderBuffer->GetBufferSize(),
			&m_pInputLayout
		))) throw false;
	}

	InputLayout::~InputLayout()
	{
		delete m_description;
		SAFE_RELEASE(m_pInputLayout);
	}

	InputLayoutDesc* InputLayout::getDescription()
	{
		return m_description;
	}
	ID3D11InputLayout* InputLayout::getResource()
	{
		return m_pInputLayout;
	}
}