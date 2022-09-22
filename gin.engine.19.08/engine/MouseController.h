#pragma once

#include <map>
#include <string>

namespace Engine
{
	class MouseController
	{
	protected:
		std::map<std::string, MouseController*>* controllers;
		MouseController** currentController;
		std::string name;
	public:
		MouseController(std::map<std::string, MouseController*>* c, MouseController** current)
		{
			controllers = c;
			currentController = current;
		}

		void setController(std::string name)
		{
			*currentController = (*controllers)[name];
		}

		virtual void onMouseEnter(int x, int y) {};
		virtual void onMouseLeave(int x, int y) {};
		virtual void onMouseLDown(int x, int y) {};
		virtual void onMouseRDown(int x, int y) {};
		virtual void onMouseLUP(int x, int y) {};
		virtual void onMouseRUP(int x, int y) {};
		virtual void onMouseMove(int x, int y, int dx, int dy) {};
	};
}

