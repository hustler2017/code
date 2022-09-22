#pragma once
#include "Object.h"

namespace Engine
{
	class Axis : public Object
	{
	public:
		Axis();
		~Axis();

		void setVisible(bool status);
		bool getVisible();
	};
}

