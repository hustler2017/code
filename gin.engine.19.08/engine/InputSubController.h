#pragma once
#include "pch.h"
#include "InputController.h"
#include <string>

class InputController;

class InputSubController
{
public:

	InputController* parent;

	virtual void onKeyDown(int key) {}
	virtual void onKeyUp(int key) {}
	virtual void onMouseEnter(int x, int y) {};
	virtual void onMouseLeave(int x, int y) {};
	virtual void onMouseLDown(int x, int y) {};
	virtual void onMouseRDown(int x, int y) {};
	virtual void onMouseLUP(int x, int y) {};
	virtual void onMouseRUP(int x, int y) {};
	virtual void onMouseMove(int x, int y, int dx, int dy) {};
	virtual void onIdle() {};
	virtual std::string getName() = 0;
};

