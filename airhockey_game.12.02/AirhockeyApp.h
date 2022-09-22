#pragma once

#include "ScreenManager.h";

namespace AirhockeyGame
{

	class AirhockeyApp
	{
		ScreenManager screenManager;
	public:
		AirhockeyApp();
		~AirhockeyApp();
		void update();

	};

}

