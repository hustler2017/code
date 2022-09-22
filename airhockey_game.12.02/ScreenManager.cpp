#include "ScreenManager.h"


namespace AirhockeyGame {

    void ScreenManager::changeScreen(Screen* pScreen)
    {
        if (pCurrentScreen == nullptr)
        {
            pCurrentScreen = pScreen;
            pCurrentScreen->start();
            return;
        }

        if (pNextScreen) return;

        pCurrentScreen->end();
        pNextScreen = pScreen;
    }
    
    void ScreenManager::updateScreen()
    {
        if (pCurrentScreen->finished())
        {
            pCurrentScreen = pNextScreen;
            pNextScreen = nullptr;
            pCurrentScreen->start();
        }

        pCurrentScreen->update();
    }

}

