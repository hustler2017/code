#include "pch.h"
#include "Light.h"

namespace Scene3D {

	void Light::setPosition(float x, float y, float z){
		position = {x, y, z};
	}
	void Light::setIntensity(float i){
		intensity = i;
	}
	void Light::setColor(float r, float g, float b){
		color = {r, g, b};
	}
}
