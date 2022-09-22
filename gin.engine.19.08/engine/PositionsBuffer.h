#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "Common.h"
#include <vector>

namespace Engine
{
	class PositionsBuffer
	{
		Graphics::Direct3D* m_d3d;
		int m_num_positions;

		

		std::vector<DirectX::XMMATRIX> m_positions;

		ID3D11Buffer* m_pConstantBuffer;
		void createConstantBuffer();

	public:
		PositionsBuffer(Graphics::Direct3D* d3d, int max_positions);
		~PositionsBuffer();

		void clear();
		void addPosition(Position& p);
		void setPosition(Position& p);
		void updateBuffer();
		void setBuffer();

	};
}

