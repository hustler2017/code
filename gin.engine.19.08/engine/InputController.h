#pragma once
#include "pch.h"
#include "InputSubController.h"
#include <map>
#include <string>
#include "Camera.h"
#include "Engine.h"


struct MouseStatus
{
	bool LButton;
	bool RButton;
	bool MButton;
	int x;
	int y;
	int dx;
	int dy;
};

class InputSubController;

class InputController
{
	std::map<std::string, InputSubController*> subControllers;
	InputSubController* currentController;
public:

	bool  keyState[256];
	MouseStatus  mouseState;

	InputController();
	~InputController();
	void update();
	void addController(InputSubController* c);
	void setController(std::string name);
	void onKeyDown(int key);
	void onKeyUp(int key);
	void onMouseEnter(int x, int y);
	void onMouseLeave(int x, int y);
	void onMouseLDown(int x, int y);
	void onMouseRDown(int x, int y);
	void onMouseLUP(int x, int y);
	void onMouseRUP(int x, int y);
	void onMouseMove(int x, int y);
	void onIdle();

};





