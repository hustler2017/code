#pragma once
#include "GameObject.h"

class GamePuck : public GameObject
{
	float x;
	float y;
	float radius = 20.;
	GamePosition position;
public:
	GamePuck(float x, float y, float radius);
	void update();
	void draw();
};


