#include "pch.h"
#include "Light.h"

namespace Engine
{

	Light::Light(Graphics::Direct3D* d3d)
		:m_d3d(d3d)
	{

		bufferData.color.x = 1.0f;
		bufferData.color.y = 1.0f;
		bufferData.color.z = 1.0f;

		bufferData.intensity = 0.7f;
		bufferData.dir.x = -0.5f;
		bufferData.dir.y = -0.5f;
		bufferData.dir.z = -0.5f;



		D3D11_BUFFER_DESC description;
		ZeroMemory(&description, sizeof(D3D11_BUFFER_DESC));
		description.ByteWidth = sizeof(ConstantBuffer);
		description.Usage = D3D11_USAGE_DEFAULT;
		description.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		description.MiscFlags = 0;
		description.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA data;
		data.SysMemPitch = 0;
		data.SysMemSlicePitch = 0;
		data.pSysMem = &bufferData;

		if (FAILED(m_d3d->pDevice->CreateBuffer(&description, &data, &m_pConstantBuffer)))
			throw false;




	}

	Light::~Light()
	{
		if (m_pConstantBuffer)
		{
			m_pConstantBuffer->Release();
		}
	}


	void Light::setup()
	{
		m_d3d->pContext->VSSetConstantBuffers(1, 1, &m_pConstantBuffer);
		m_d3d->pContext->PSSetConstantBuffers(1, 1, &m_pConstantBuffer);
	}


	Vector3 Light::getColor()
	{
		return bufferData.color;
	}

	void Light::setColor(Vector3 color)
	{
		bufferData.color = color;
	}

	Vector3 Light::getDirection()
	{
		return bufferData.dir;
	}
	void Light::setDirection(Vector3  direction)
	{
		bufferData.dir = direction;
	}

	Vector3 Light::getPosition()
	{
		return Vector3(0, 0, 0);
	}

	void Light::setPosition(Vector3 pos) {}

	float Light::getIntensity()
	{
		return bufferData.intensity;
	}

	void Light::setIntensity(float intensity)
	{
		bufferData.intensity = intensity;
	}
}
