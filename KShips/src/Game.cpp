#include "Game.h"
#include <iostream>
#include <map>
#include "stdlib.h"
#include "time.h"
#include "Platform.h"
#include "Utils.h"

void Game::Init()
{
	for(int i=0; i < 10; ++i)
	{
		RaptorShip* thisShip = new RaptorShip();
		thisShip->Init(100 + (i*30), -50, 10, 10);
		enemyList.push_back(thisShip);
	}
	player.Init(300, 300, 5, &playersBullets);
	scroll.Init("./assets/background.png", 1);
}

void Game::Draw()
{
	scroll.Draw();
	for (auto bullet : enemyList)
	{
		bullet->Draw();
	}

	for (auto playerBullet : playersBullets)
	{
		playerBullet->Draw();
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
	for (auto ship : enemyList)
	{
		RaptorShip* enemy = dynamic_cast<RaptorShip*>(ship);
		if (enemy && (rand() % 1000) > 990)
		{
			enemyList.push_back(enemy->Shoot());
		}
	}

	for (auto bullet : enemyList)
	{
		bullet->Move();
	}

	RemoveEnemys();

	for (auto playerBullet : playersBullets)
	{
		playerBullet->Move();
	}
	
	
	std::vector<PlayerBullet*> junkBullets;

	for (auto playerBullet : playersBullets)
	{
		if (playerBullet->GetPositionY() < 0)
		{
			junkBullets.push_back(playerBullet);
		}
	}	

	for (auto bullet : junkBullets)
	{
		playersBullets.remove(bullet);
	}

	player.Update(enemyList);
	scroll.Move(1);
}

void Game::RemoveEnemys()
{
	std::vector<EnemyObject*> junkEnemy;
	for (auto bullet : enemyList)
	{
		RaptorShip* enemy = dynamic_cast<RaptorShip*>(bullet);
		if (enemy != nullptr)
		{
			for (auto playerBullet : playersBullets)
			{
				if (Utils::CheckCollision(bullet->GetPositionX(), bullet->GetPositionY(), bullet->GetRadius(),
					playerBullet->GetPositionX(), playerBullet->GetPositionY(), playerBullet->GetRadius()))
				{
					enemy->Destroy();
					junkEnemy.push_back(enemy);
				}
			}
		}
	}

	for (auto enemy : junkEnemy)
	{
		enemyList.remove(enemy);
	}
}

bool Game::Input(const Uint8 *keys)
{
	player.Input(keys);
	return false;
}
