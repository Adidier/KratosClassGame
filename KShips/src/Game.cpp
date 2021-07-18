#include "Game.h"
#include <iostream>
#include <map>
#include "stdlib.h"
#include "time.h"
#include "Platform.h"

void Game::Init()
{
	for(int i=0;i<10;i++)
	{
		RaptorShip* thisShip = new RaptorShip();
		thisShip->Init(100+(i*30), -50, 10, 10);
		ships.push_back(thisShip);
	}
	
	player.Init(300, 300, 5);
}

void Game::Draw()
{
	for (auto ship : ships)
	{
		ship->Draw();
	}

	for (auto bullet : bulletsPool)
	{
		bullet->Draw();
	}

	player.Draw();
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
	for (auto ship : ships)
	{
		ship->Update(0,0);
	}

	for (auto ship : ships)
	{
		if (rand() % 100 > 97)
		{
			bulletsPool.push_back(ship->Shoot());
		}
	}

	for (auto bullet : bulletsPool)
	{
		bullet->Move();
	}

	player.Update(ships);
}

bool Game::Input(int key)
{
	player.Input(key);
	return false;
}
