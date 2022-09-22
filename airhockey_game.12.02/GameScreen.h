#pragma once
#include "Screen.h"

namespace AirhockeyGame {

	class GameScreen :
		public Screen
	{
	public:
		void start();
		void update();
		void end();
		void finished();
	};

}

