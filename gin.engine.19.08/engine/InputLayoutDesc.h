#pragma once
#include "pch.h"
#include "Direct3D.h"
#include <vector>



namespace Engine
{
	class InputLayoutDesc
	{
		std::vector<D3D11_INPUT_ELEMENT_DESC> m_layout;
	public:

		InputLayoutDesc(D3D11_INPUT_ELEMENT_DESC*  desc, int count)
		{
			for (int i = 0; i < count; i++)
			{
				m_layout.push_back(desc[i]);
			}
		}

		bool operator==(const InputLayoutDesc& other)
		{
			if (m_layout.size() != other.m_layout.size())
				return false;

			for (int i = 0; i < other.m_layout.size(); i++)
			{

				if (m_layout[i].AlignedByteOffset != other.m_layout[i].AlignedByteOffset ||
					m_layout[i].Format != other.m_layout[i].Format ||
					m_layout[i].InputSlot != other.m_layout[i].InputSlot ||
					m_layout[i].InputSlotClass != other.m_layout[i].InputSlotClass ||
					m_layout[i].InstanceDataStepRate != other.m_layout[i].InstanceDataStepRate ||
					m_layout[i].SemanticIndex != other.m_layout[i].SemanticIndex ||
					std::string(m_layout[i].SemanticName) != std::string(other.m_layout[i].SemanticName))

					return false;
			}

			return true;
		}

		void operator=(const InputLayoutDesc& other)
		{
			m_layout.clear();

			for (int i = 0; i < other.m_layout.size(); i++)
			{
				D3D11_INPUT_ELEMENT_DESC desc;

				desc.AlignedByteOffset    =	other.m_layout[i].AlignedByteOffset;
				desc.Format               =	other.m_layout[i].Format;
				desc.InputSlot            =	other.m_layout[i].InputSlot;
				desc.InputSlotClass       = other.m_layout[i].InputSlotClass;
				desc.InstanceDataStepRate =	other.m_layout[i].InstanceDataStepRate;
				desc.SemanticIndex        =	other.m_layout[i].SemanticIndex;
				desc.SemanticName         = other.m_layout[i].SemanticName;

				m_layout.push_back(desc);
			}
		}

		D3D11_INPUT_ELEMENT_DESC* getLayout()
		{
			return &m_layout[0];
		}

		int getLayoutElementsCount()
		{
			return static_cast<int>(m_layout.size());
		}

	};
}
