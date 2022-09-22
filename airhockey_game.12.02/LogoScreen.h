#pragma once
#include "Screen.h"

namespace AirhockeyGame {

    class LogoScreen :
        public Screen
    {
        bool finished;
    public:
        void start();
        void update();
        void end();
        bool finished();
    };

}



