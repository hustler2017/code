#include "pch.h"
#include "GameTimer.h"
#include <string>

using namespace std;

GameTimer::GameTimer()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTicks);
	desiredDelta = frequency / desiredFPS;
}

bool GameTimer::checkDelta()
{
	
	QueryPerformanceCounter((LARGE_INTEGER*)&ticks);
	_delta = ticks - lastTicks;

	return desiredDelta < _delta;
}

void GameTimer::checkFPS()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&ticks);
	if ((ticks - fpsCheckStart) > frequency)
	{
		fpsCheckStart = ticks;
		fps = fpsCounter;
		fpsCounter = 0;
		OutputDebugStringA(std::to_string(fps).c_str());
		OutputDebugStringA(" ");
	}
	else
	{
		fpsCounter++;
	}
}

void GameTimer::tick()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&ticks);
	_delta = ticks - lastTicks;
	lastTicks = ticks;
}
