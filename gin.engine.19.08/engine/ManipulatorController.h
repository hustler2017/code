#pragma once
#include "pch.h"
#include "InputSubController.h"
#include "Engine.h"


extern int manipulator_axe;
extern Engine::Object* maniObj;

class ManipulatorController : public InputSubController
{
	Engine::Engine* engine;

public:
	ManipulatorController(Engine::Engine* e)
	{
		engine = e;
	}

	void onMouseLUP(int x, int y) {
		OutputDebugString(L"свободный режим");
		parent->setController("free");
		manipulator_axe = 0;
	}
	void onMouseMove(int x, int y, int dx, int dy) 
	{
		float addition = dx;

		if (manipulator_axe == 1)
		{
			maniObj->getPosition()->position.x += addition;
		}

		if (manipulator_axe == 2)
		{
			maniObj->getPosition()->position.y += addition;
		}

		if (manipulator_axe == 3)
		{
			maniObj->getPosition()->position.z += addition;
		}
	}

	std::string getName()
	{
		return std::string("manipulator");
	}
};


