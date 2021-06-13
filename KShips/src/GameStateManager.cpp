#include "GameStateManager.h"
#include "Platform.h"

void GameStateManager::SetState(GameState* state)
{
	state->Init();
	gamestates.push(state);
}

void GameStateManager::ReleaseState()
{
	gamestates.pop();
}

void GameStateManager::GameLoop()
{
	bool closeApp = false;
	while (!closeApp)
	{
		if (gamestates.size() == 0)
		{
			break;
		}
		plat->Input(gamestates.top(), &GameState::Input);
		gamestates.top()->Update();
		plat->RenderClear();
		gamestates.top()->Draw();
		plat->RenderPresent();
		SDL_Delay(10);
	}
}

GameStateManager::GameStateManager()
{
	plat = Platform::GetPtr();
	plat->Init(512,384);
}

GameStateManager::~GameStateManager()
{
	plat->Close();
}