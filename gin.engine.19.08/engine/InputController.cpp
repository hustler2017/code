#include "pch.h"
#include "InputController.h"



InputController::InputController()
{
	memset(keyState, 0, sizeof(bool) * 256);
	memset(&mouseState, 0, sizeof(MouseStatus));
}

InputController::~InputController()
{
	for (auto cont : subControllers)
	{
		delete cont.second;
	}

}


void InputController::update()
{
	currentController->onIdle();
}

void InputController::addController(InputSubController* c)
{

	subControllers[c->getName()] = c;
	c->parent = this;
}

void InputController::setController(std::string name)
{
	currentController = subControllers[name];
}


void InputController::onKeyDown(int key) {
	keyState[key] = true;
	currentController->onKeyDown(key);
};

void InputController::onKeyUp(int key) {
	keyState[key] = false;
	currentController->onKeyUp(key);
}

void InputController::onMouseEnter(int x, int y)
{
	currentController->onMouseEnter(x, y);
}
void InputController::onMouseLeave(int x, int y)
{
	currentController->onMouseLeave(x, y);
}
void InputController::onMouseLDown(int x, int y)
{
	mouseState.LButton = true;
	currentController->onMouseLDown(x, y);
}
void InputController::onMouseRDown(int x, int y) {
	mouseState.RButton = true;
	currentController->onMouseRDown(x, y);
}
void InputController::onMouseLUP(int x, int y) {
	mouseState.LButton = false;
	currentController->onMouseLUP(x, y);
}
void InputController::onMouseRUP(int x, int y) {
	mouseState.RButton = false;
	currentController->onMouseRUP(x, y);
}
void InputController::onMouseMove(int x, int y) {

	mouseState.dx = x - mouseState.x;
	mouseState.dy = y - mouseState.y;
	mouseState.x = x;
	mouseState.y = y;

	currentController->onMouseMove(x, y, mouseState.dx, mouseState.dy);
}
void InputController::onIdle()
{
	currentController->onIdle();
}