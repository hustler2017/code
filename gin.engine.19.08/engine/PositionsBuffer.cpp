#include "pch.h"
#include "PositionsBuffer.h"


namespace Engine
{
	PositionsBuffer::PositionsBuffer(Graphics::Direct3D* d3d, int num_positions)
		:m_d3d(d3d)
	{
		m_num_positions = num_positions;
		m_positions.reserve(num_positions);
		createConstantBuffer();
	}

	PositionsBuffer::~PositionsBuffer()
	{
		SAFE_RELEASE(m_pConstantBuffer);
	}
	
	void PositionsBuffer::clear()
	{
		m_positions.clear();
	}

	void PositionsBuffer::setBuffer()
	{
		m_d3d->pContext->VSSetConstantBuffers(3, 1, &m_pConstantBuffer);
	}

	void PositionsBuffer::updateBuffer()
	{
		m_d3d->pContext->UpdateSubresource(m_pConstantBuffer, 0,0, &m_positions[0], 0, 0);
	}

	void PositionsBuffer::addPosition(Position& p)
	{
		if (m_positions.size() < m_num_positions)
		{
			DirectX::XMMATRIX M = DirectX::XMMatrixIdentity() *
				DirectX::XMMatrixScaling(p.scale.x, p.scale.y, p.scale.z) *
				DirectX::XMMatrixRotationRollPitchYaw(p.rotation.x, p.rotation.y, p.rotation.z) *
				DirectX::XMMatrixTranslation(p.position.x, p.position.y, p.position.z);

			M = DirectX::XMMatrixTranspose(M);

			m_positions.push_back(M);
		}
	}

	void PositionsBuffer::setPosition(Position& p)
	{
		clear();
		addPosition(p);
		updateBuffer();
	}

	void PositionsBuffer::createConstantBuffer()
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = m_num_positions * sizeof(DirectX::XMMATRIX);
		desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.MiscFlags = 0;
		desc.StructureByteStride = 0;

		if(FAILED(m_d3d->pDevice->CreateBuffer(&desc, nullptr, &m_pConstantBuffer)))
			throw false;
	}
}
