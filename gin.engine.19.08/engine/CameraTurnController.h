#pragma once
#include "pch.h"
#include "InputSubController.h"
#include "Camera.h"


class CameraTurnController : public InputSubController
{

	Engine::Camera* m_camera;
public:
	CameraTurnController(Engine::Camera* camera)
	{
		m_camera = camera;
	}


	void onMouseEnter(int x, int y) {}
	void onMouseLeave(int x, int y) {}
	void onMouseLDown(int x, int y) {}

	void onMouseLUP(int x, int y) {}
	void onMouseRUP(int x, int y) {
		OutputDebugString(L"режим свободный");
		parent->setController("free");
	}
	void onMouseMove(int x, int y, int dx, int dy) {

		float mouseSpeed = 0.1f;
		float coefficient = 0.01f;

		float angle = 0;

		if (dy) {
			angle = mouseSpeed * coefficient * dy;
			m_camera->turn(-angle, 0, 0);
		}
		if (dx) {
			angle = mouseSpeed * coefficient * dx;
			m_camera->turn(0, 0, -angle);
		}
	}

	void onMouseRDown(int x, int y) {}

	void onIdle()
	{
		float moveSpeed = 7.5f;

		if (parent->keyState['W'])
			m_camera->move(0, 0, moveSpeed);
		if (parent->keyState['A'])
			m_camera->move(-moveSpeed, 0, 0);
		if (parent->keyState['S'])
			m_camera->move(0, 0, -moveSpeed);
		if (parent->keyState['D'])
			m_camera->move(moveSpeed, 0, 0);
	}

	std::string getName()
	{
		return std::string("cameraturn");
	}
};



