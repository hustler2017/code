#pragma once
#include "pch.h"
#include "Direct3D.h"
#include "Common.h"
#include <DirectXMath.h>

namespace Engine
{
	class Camera
	{
		

	private:

		struct ConstantBuffer {
			DirectX::XMFLOAT4X4 viewMatrix;
			DirectX::XMFLOAT4X4 projMatrix;
		};

		float aspectRatio;
		float fow;
		float nearZ;
		float farZ;

		DirectX::XMMATRIX viewMatrix;
		DirectX::XMMATRIX projMatrix;

		ConstantBuffer m_constantBuffer;

		Graphics::Direct3D* m_d3d;
		ID3D11Buffer* m_pConstantBuffer;


		void buildProjectionMatrix();
		void decomposite();
		void createResources();

		void setDefaultSettings();

		Vector3 rotation;
		Vector3 position;
	public:
		void buildViewMatrix();
		Camera(Graphics::Direct3D* d3d);
		~Camera();

		Vector3 getRotation();
		Vector3 getPosition();

		void setAspectRatio(float aspect);
		void setRotation(float x, float y, float z);
		void setPosition(float x, float y, float z);
		void setFOW(float f);
		float getFOW();
		void setNearFarZ(float, float);

		void setBuffer();
		void move(float x, float y, float z);
		void turn(float x, float y, float z);
		void updateBuffer();
		void lookAt(float x, float y, float z);

		DirectX::XMMATRIX getProjectionMatrix();
		DirectX::XMMATRIX getViewMatrix();
	};
}
