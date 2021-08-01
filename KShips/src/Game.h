#pragma once
#include "GameState.h"
#include "RaptorShip.h"
#include "PlayerShip.h"
#include "EnemyObject.h"

#include <vector>
#include <list>

class Game : public GameState
{
private:
	PlayerShip player;
	std::list<EnemyObject*> enemyList;
	
public:
	Game() {};
	void Init() override;
	void Draw() override;
	void Update() override;
	bool Input(const Uint8 *keys) override;
	void Close() override;
	bool Impact(int x, int y, int w, int h, int x1, int y1, int w1, int h1);
};

