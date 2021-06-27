#include "Game.h"
#include <iostream>
#include <map>
#include "stdlib.h"
#include "time.h"
#include "Platform.h"
void Game::Init()
{
	ship.Init(100, -50, 10, 10);
}

void Game::Draw()
{
	ship.Draw();
}

void Game::Close()
{

}

bool Game::Impact(int x,int y, int w,int h, int x1, int y1, int w1, int h1)
{

		return false;
}

void Game::Update()
{
	ship.Update(0,0);
}

bool Game::Input(int key)
{

	return false;
}
