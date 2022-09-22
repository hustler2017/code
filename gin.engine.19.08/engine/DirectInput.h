#pragma once
#include "pch.h"
#include <dinput.h>

class DirectInput 
{

private:

	void Shutdown();
	bool ReadKeyboard();
	bool ReadMouse();
	void ProcessInput();
	void saveOldStates();

	IDirectInput8* m_directInput = nullptr;
	IDirectInputDevice8* m_keyboard = nullptr;
	IDirectInputDevice8* m_mouse = nullptr;

	unsigned char m_keyboardState[256];
	DIMOUSESTATE m_mouseState;

	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY;

	bool lastMouseLeftState = false;
	bool lastMouseRightState = false;



public:
	bool update();
	DirectInput();
	~DirectInput();
	bool Initialize(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight);

	bool isKeyPressed(int code);
	bool isKeyWPressed();
	bool isKeyAPressed();
	bool isKeySPressed();
	bool isKeyDPressed();

	int getMouseDeltaX();
	int getMouseDeltaY();
	bool IsEscapePressed();

	bool isMouseLeftPressed();
	bool isMouseRightPressed();
	bool isMouseLeftUp();
	bool isMouseLeftDown();
	bool isMouseRightUp();
	bool isMouseRightDown();
	int getMouseX();
	int getMouseY();



};