#pragma once
#include "Screen.h"

namespace AirhockeyGame {
	class ScreenManager
	{
		Screen* 
		bool changingScreen;
		Screen* pNextScreen;
		Screen* pCurrentScreen;
	public:
		void changeScreen(Screen* pScreen);
		void updateScreen();
	};

}

