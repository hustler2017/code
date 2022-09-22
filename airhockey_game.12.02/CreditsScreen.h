#pragma once
#include "Screen.h"

namespace AirhockeyGame {
	class CreditsScreen :
		public Screen
	{
	public:
		void start();
		void update();
		void end();
		bool finished();
	};
}


