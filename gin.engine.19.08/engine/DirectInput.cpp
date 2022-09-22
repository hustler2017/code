#include "pch.h"
#include "DirectInput.h"

bool DirectInput::Initialize(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight)
{
	HRESULT result;


	// Store the screen size which will be used for positioning the mouse cursor.
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;

	// Initialize the location of the mouse on the screen.
	m_mouseX = 0;
	m_mouseY = 0;


	// Initialize the main direct input interface.
	result = DirectInput8Create(hinstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_directInput, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Initialize the direct input interface for the keyboard.
	result = m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Set the data format.  In this case since it is a keyboard we can use the predefined data format.
	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
	{
		return false;
	}


	// Установите уровень взаимодействия клавиатуры, чтобы он не использовался совместно с другими программами. 
	result = m_keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);//DISCL_EXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}

	// Теперь приобретите клавиатуру. 
	result = m_keyboard->Acquire();
	if (FAILED(result))
	{
		return false;
	}

	// Инициализируем интерфейс прямого ввода для мыши. 
	result = m_directInput->CreateDevice(GUID_SysMouse, &m_mouse, NULL);
	if (FAILED(result))
	{
		return false;
	}

	// Установите формат данных для мыши, используя предопределенный формат данных мыши. 
	result = m_mouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(result))
	{
		return false;
	}

	// Установите уровень взаимодействия мыши, чтобы поделиться с другими программами. 
	result = m_mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(result))
	{
		return false;
	}

	// Получить мышь. 
	result = m_mouse->Acquire();
	if (FAILED(result))
	{
		OutputDebugStringW(L"m_mouse->Acquire()  failed");
		return false;
	}

	return true;
}




bool DirectInput::ReadMouse()
{
	HRESULT result;

	if (m_mouse == nullptr)
	{
		return false;
	}

	// Read the mouse device.
	result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);
	if (FAILED(result))
	{

		// If the mouse lost focus or was not acquired then try to get control back.
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{

			if (FAILED(m_mouse->Acquire()))
			{
				OutputDebugStringW(L"m_mouse->Acquire()  failed");
			}
		}
		else
		{
			return false;
		}
	}

	return true;
}

int DirectInput::getMouseX()
{
	return m_mouseX;
}


int DirectInput::getMouseY()
{
	return m_mouseY;
}


void DirectInput::ProcessInput()
{
	// Update the location of the mouse cursor based on the change of the mouse location during the frame.
	m_mouseX += m_mouseState.lX;
	m_mouseY += m_mouseState.lY;

	// Ensure the mouse location doesn't exceed the screen width or height.
	if (m_mouseX < 0) { m_mouseX = 0; }
	if (m_mouseY < 0) { m_mouseY = 0; }

	if (m_mouseX > m_screenWidth) { m_mouseX = m_screenWidth; }
	if (m_mouseY > m_screenHeight) { m_mouseY = m_screenHeight; }

	return;
}

bool DirectInput::isKeyPressed(int code)
{
	return m_keyboardState[code] & 0x80;
}

bool DirectInput::isKeyWPressed()
{
	return m_keyboardState[DIK_W] & 0x80;
}
bool DirectInput::isKeyAPressed()
{
	return m_keyboardState[DIK_A] & 0x80;
}
bool DirectInput::isKeySPressed()
{
	return m_keyboardState[DIK_S] & 0x80;
}
bool DirectInput::isKeyDPressed()
{
	return m_keyboardState[DIK_D] & 0x80;
}

int DirectInput::getMouseDeltaX()
{
	return m_mouseState.lX;
}


int DirectInput::getMouseDeltaY()
{
	return m_mouseState.lY;
}

bool DirectInput::IsEscapePressed()
{
	// Do a bitwise and on the keyboard state to check if the escape key is currently being pressed.
	if (m_keyboardState[DIK_ESCAPE] & 0x80)
	{
		return true;
	}

	return false;
}

bool DirectInput::isMouseLeftUp()
{
	return (!isMouseLeftPressed()) && lastMouseLeftState;
}

bool DirectInput::isMouseLeftDown()
{
	return isMouseLeftPressed() && !lastMouseLeftState;
}

bool DirectInput::isMouseRightDown()
{
	return isMouseRightPressed() && !lastMouseRightState;
}

bool DirectInput::isMouseRightUp()
{
	return (!isMouseRightPressed()) && lastMouseRightState;
}


bool DirectInput::isMouseLeftPressed()
{
	if (m_mouseState.rgbButtons[0] & 0x80)
	{
		return true;
	}

	return false;
}

bool DirectInput::isMouseRightPressed()
{
	if (m_mouseState.rgbButtons[1] & 0x80)
	{
		return true;
	}

	return false;
}

bool DirectInput::ReadKeyboard()
{
	HRESULT result;


	// Read the keyboard device.
	result = m_keyboard->GetDeviceState(sizeof(m_keyboardState), (LPVOID)&m_keyboardState);
	if (FAILED(result))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			m_keyboard->Acquire();
		}
		else
		{
			return false;
		}
	}

	return true;
}

void DirectInput::saveOldStates()
{
	lastMouseLeftState = m_mouseState.rgbButtons[0] & 0x80;
	lastMouseRightState = m_mouseState.rgbButtons[1] & 0x80;
}

bool DirectInput::update()
{
	bool result;

	saveOldStates();

	// Read the current state of the keyboard.
	result = ReadKeyboard();
	if (!result)
	{
		return false;
	}



	// Read the current state of the mouse.
	result = ReadMouse();
	if (!result)
	{
		return false;
	}

	// Process the changes in the mouse and keyboard.
	ProcessInput();

	return true;
}

void DirectInput::Shutdown()
{
	// Release the mouse.
	if (m_mouse)
	{
		m_mouse->Unacquire();
		m_mouse->Release();
		m_mouse = 0;
	}

	// Release the keyboard.
	if (m_keyboard)
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = 0;
	}

	// Release the main interface to direct input.
	if (m_directInput)
	{
		m_directInput->Release();
		m_directInput = 0;
	}

	return;
}


DirectInput::DirectInput()
{

}

DirectInput::~DirectInput()
{
	Shutdown();

}