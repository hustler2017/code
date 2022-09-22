#pragma once
#include "MouseController.h"


namespace Engine
{
	class CommonController : public MouseController
	{
	public:

		CommonController(std::map<std::string, MouseController*>* c, MouseController** current) 
			: MouseController(c,current)
		{
			name = "common";
			(*c)[name] = this;
		}

		void onMouseEnter(int x, int y);
		void onMouseLeave(int x, int y);
		void onMouseLDown(int x, int y);
		void onMouseRDown(int x, int y);
		void onMouseLUP(int x, int y);
		void onMouseRUP(int x, int y);
		void onMouseMove(int x, int y, int dx, int dy);
		
	};
}



