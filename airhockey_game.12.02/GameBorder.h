#pragma once
#include "GameObject.h"

class GameBorder : public GameObject
{
	float x1;
	float y1;
	float x2;
	float y2;
public:
	GameBorder(float x1, float y1, float x2, float y2);
	void draw();
	void update();
};

