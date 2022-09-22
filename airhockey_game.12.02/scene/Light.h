#pragma once

#include "Scene3Dlib.h"
#include "Scene3D.h"

namespace Scene3D {

	struct Color {
		float r;
		float g;
		float b;
	};

	class Light : public ILight
	{
		Color color;
		float intensity = 1.0f;
		Position position;


	public:
		void setPosition(float x, float y, float z);
		void setIntensity(float i);
		void setColor(float r, float g, float b);
	};
}


