#pragma once
#include <windows.h>
#include <vector>
#include "GameField.h"

enum GameState {
	STARTING,
	RUNNING,
	ENDING
};

class Game
{
	GameField field;
	GameState state = RUNNING;
	int startCounter;

	bool initGame();
	void running(); 
	void starting();
	void ending();
public:
	Game();
	~Game();
	bool init(HWND hwnd);
	void shutdown();
	void update();
	void render();
	void updateState(int dx, int dy);
};

