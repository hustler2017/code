#pragma once
#include "Screen.h"

namespace AirhockeyGame {
	class SettingsScreen :
		public Screen
	{
	public:
		void start();
		void update();
		void end();
		bool finished();
	};
}




