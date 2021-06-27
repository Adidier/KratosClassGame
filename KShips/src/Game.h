#pragma once
#include "GameState.h"
#include "RaptorShip.h"
class Game : public GameState
{
private:
	RaptorShip ship;
public:
	Game() {};
	void Init() override;
	void Draw() override;
	void Update() override;
	bool Input(int key) override;
	void Close() override;
	bool Impact(int x, int y, int w, int h, int x1, int y1, int w1, int h1);
};

