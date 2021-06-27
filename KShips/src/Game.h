#pragma once
#include "GameState.h"

class Game : public GameState
{
private:
public:
	Game() {};
	void Init() override;
	void Draw() override;
	void Update() override;
	bool Input(int key) override;
	void Close() override;
	bool Impact(int x, int y, int w, int h, int x1, int y1, int w1, int h1);
};

