#pragma once

#include "Types.h"

namespace Scene3D
{
	class Camera
	{
		void updateMatrix();
	public:
		Position position;
		Position target;
		float fow;
		XMMATRIX mx;
		float aspectRatio;

		void setPosition(float x, float y, float z);
		void setTarget(float x, float y, float z);

		Camera();


	};





}

