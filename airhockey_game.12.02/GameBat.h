#pragma once
#include "GameObject.h"

class GameBat : public GameObject
{
	float x;
	float y;
	float r1;
	float r2;
	FieldSector sector;
public:
	GameBat(float x, float y, float r1, float r2);
	void draw();
	void update();
};
