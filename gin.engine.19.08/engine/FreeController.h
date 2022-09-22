#pragma once
#include "pch.h"
#include "InputSubController.h"
#include "Engine.h"


extern int manipulator_axe;
extern Engine::Object* maniObj;

class FreeController : public InputSubController
{
	Engine::Engine* engine;

public:
	FreeController(Engine::Engine* e)
	{
		engine = e;
	}

	void onMouseEnter(int x, int y) {}
	void onMouseLeave(int x, int y) {}
	void onMouseLDown(int x, int y)
	{
		int res = engine->checkManipulatorPick(x, y);
		if (res)
		{
			OutputDebugString(L"выбор оси");

			manipulator_axe = res;
			maniObj = engine->getManipulatorObject();
			parent->setController("manipulator");
			return;
		}
		
		engine->pick(x, y);
	}

	void onMouseLUP(int x, int y) {}
	void onMouseRUP(int x, int y) {}
	void onMouseMove(int x, int y, int dx, int dy) {}
	void onIdle()
	{

	}
	void onMouseRDown(int x, int y)
	{
		OutputDebugString(L"режим камеры");
		parent->setController("cameraturn");
	}

	std::string getName()
	{
		return std::string("free");
	}
};


