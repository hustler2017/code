#pragma once

namespace AirhockeyGame {

	class Screen
	{
	public:
		virtual void start() = 0;
		virtual void update() = 0;
		virtual void end() = 0;
		virtual bool finished() = 0;

	};
}

