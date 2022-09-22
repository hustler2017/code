#include "AirhockeyApp.h"
#include "LogoScreen.h"


namespace AirhockeyGame
{
	AirhockeyApp::AirhockeyApp()
	{
		LogoScreen* pLogoScreen = new LogoScreen;

		screenManager.changeScreen(pLogoScreen);
	}

	AirhockeyApp::~AirhockeyApp()
	{

	}

	void AirhockeyApp::update()
	{
		screenManager.updateScreen();
	}
}
