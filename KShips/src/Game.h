#pragma once
#include "GameState.h"
#include "RaptorShip.h"
#include "PlayerShip.h"
#include "EnemyObject.h"
#include "Scroll.h"
#include <vector>
#include <list>

class Game : public GameState
{
private:
	PlayerShip player;
	std::list<EnemyObject*> enemyList;
	std::list<PlayerBullet*> playersBullets;
	Scroll scroll;
public:
	Game() {};
	void Init() override;
	void Draw() override;
	void Update() override;
	void RemoveEnemys();
	bool Input(const Uint8 *keys) override;
	void Close() override;
	bool Impact(int x, int y, int w, int h, int x1, int y1, int w1, int h1);
};

