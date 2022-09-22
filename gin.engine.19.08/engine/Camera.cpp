#include "pch.h"
#include "Camera.h"
#include <d3d11.h>


namespace Engine {

	Camera::Camera(Graphics::Direct3D* d3d)
		: m_d3d(d3d)
	{
		createResources();
		setDefaultSettings();
	}

	Camera::~Camera()
	{
		if (m_pConstantBuffer)
		{
			m_pConstantBuffer->Release();
			m_pConstantBuffer = nullptr;
		}
	}

	void Camera::setNearFarZ(float n, float f)
	{
		nearZ = n;
		farZ = f;
		buildProjectionMatrix();
	}

	void Camera::setAspectRatio(float asp)
	{
		aspectRatio = asp;
		buildProjectionMatrix();
	}

	void Camera::decomposite()
	{

	}

	Vector3 Camera::getRotation()
	{
		return rotation;
	}

	Vector3 Camera::getPosition()
	{
		return position;
	}

	void Camera::move(float x, float y, float z)
	{
		using namespace DirectX;

		XMVECTOR translation = XMVector4Transform(
			XMVectorSet(x, y, z, 1),
			XMMatrixInverse(nullptr, viewMatrix)
		);

		position.x = XMVectorGetX(translation);
		position.y = XMVectorGetY(translation);
		position.z = XMVectorGetZ(translation);

		buildViewMatrix();
	}

	void Camera::turn(float x, float y, float z)
	{
		rotation.x += x;
		rotation.y += y;
		rotation.z += z;

		buildViewMatrix();
	}

	void Camera::setBuffer()
	{
		                               // always 0!
		m_d3d->pContext->VSSetConstantBuffers(0, 1, &m_pConstantBuffer);
		m_d3d->pContext->PSSetConstantBuffers(0, 1, &m_pConstantBuffer);
	}

	void Camera::updateBuffer()
	{
		XMStoreFloat4x4(&m_constantBuffer.viewMatrix, XMMatrixTranspose(viewMatrix));
		XMStoreFloat4x4(&m_constantBuffer.projMatrix, XMMatrixTranspose(projMatrix));
		m_d3d->pContext->UpdateSubresource(m_pConstantBuffer, 0, 0, &m_constantBuffer, 0, 0);
	}

	DirectX::XMMATRIX Camera::getProjectionMatrix()
	{
		return projMatrix;
	}


	DirectX::XMMATRIX Camera::getViewMatrix()
	{
		return viewMatrix;
	}

	void Camera::lookAt(float x, float y, float z)
	{
		viewMatrix = DirectX::XMMatrixLookAtLH(
			DirectX::XMVectorSet(position.x, position.y, position.z, 1.0f),
			DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f),
			DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 1.0f)
		);
	}

	void Camera::setRotation(float x, float y, float z)
	{
		rotation.x = x;
		rotation.y = y;
		rotation.z = z;

		buildViewMatrix();
	}

	void Camera::setPosition(float x, float y, float z)
	{
		position.x = x;
		position.y = y;
		position.z = z;

		buildViewMatrix();
	}

	void Camera::buildProjectionMatrix()
	{
		using namespace DirectX;

		projMatrix = XMMatrixPerspectiveFovLH(fow, aspectRatio, nearZ, farZ);
	}

	void Camera::setFOW(float f)
	{
		fow = f;

		buildProjectionMatrix();

	}


	float Camera::getFOW()
	{
		return fow;
	}

	void Camera::setDefaultSettings()
	{
		using namespace DirectX;

		position.x = 0;
		position.y = 0;
		position.z = 100.0f;

		rotation.x = -XM_PI / 2;
		rotation.y = 0;
		rotation.z = 0;

		aspectRatio = (float)m_d3d->getClientWidth() / m_d3d->getClientHeight();
		fow = 0.50f * XM_PI;
		nearZ = 1.0f;
		farZ = 3000.f;

		buildViewMatrix();
		buildProjectionMatrix();
	}

	void Camera::createResources()
	{
		D3D11_BUFFER_DESC description;
		ZeroMemory(&description, sizeof(D3D11_BUFFER_DESC));
		description.ByteWidth = sizeof(ConstantBuffer);
		description.Usage = D3D11_USAGE_DEFAULT;
		description.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		description.MiscFlags = 0;
		description.StructureByteStride = 0;

		if (FAILED(m_d3d->pDevice->CreateBuffer(&description, 0, &m_pConstantBuffer)))
			throw false;
	}

	void Camera::buildViewMatrix()
	{
		using namespace DirectX;

		viewMatrix = XMMatrixIdentity();
		viewMatrix *= XMMatrixTranslation(-position.x, -position.y, -position.z);
		viewMatrix *= XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);
	}
}
