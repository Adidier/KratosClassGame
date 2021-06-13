#pragma once
#include "GameState.h"
#include "Platform.h"
#include<stack>

class GameStateManager
{
	private:
		std::stack <GameState*> gamestates;
		Platform* plat;
	public:
		GameStateManager();
		~GameStateManager();
		void SetState(GameState* state);
		void ReleaseState();
		void GameLoop();
};

