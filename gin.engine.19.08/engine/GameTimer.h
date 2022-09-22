#pragma once
#include "pch.h"
#include <Windows.h>

class GameTimer
{
private:
    __int64 ticks = 0;
    __int64 frequency = 0;
    __int64 _delta = 0;
    __int64 desiredDelta = 0;
    __int64 lastTicks = 0;
    __int64 fpsCheckStart = 0;
    int fpsCounter = 0;
    int fps = 0;

    int desiredFPS = 30;
public:
    GameTimer();
    void tick();
    bool checkDelta();
    void checkFPS();
};

