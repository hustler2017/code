#pragma once
#include "pch.h"
#include "Common.h"
#include "Direct3D.h"

namespace Engine
{
	class Light
	{
		struct ConstantBuffer {
			Vector3 color;
			float intensity;
			Vector3 dir;
			float d;
		};

		ConstantBuffer bufferData;
		ID3D11Buffer* m_pConstantBuffer;
		Graphics::Direct3D* m_d3d;
	public:
		Light(Graphics::Direct3D* d3d);
		~Light();

		void setup();

		Vector3 getColor();
		void setColor(Vector3 color);
		Vector3 getDirection();
		Vector3 getPosition();
		void setPosition(Vector3 pos);
		void setDirection(Vector3 direction);

		float getIntensity();
		void setIntensity(float direction);

	};
}



