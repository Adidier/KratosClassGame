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
	std::vector<RaptorShip*> ships;
	PlayerShip player;
	std::list<EnemyObject*> bulletsPool;
	
public:
	Game() {};
	void Init() override;
	void Draw() override;
	void Update() override;
	bool Input(int key) override;
	void Close() override;
	bool Impact(int x, int y, int w, int h, int x1, int y1, int w1, int h1);
};

