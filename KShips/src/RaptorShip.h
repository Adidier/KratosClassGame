#pragma once
# include "Image.h"

class RaptorShip
{

private:
	int positionx;
	int positiony;
	int radius;
	Image image;
	int harm; //el que te hacen a ti
	int energy;



public:
	RaptorShip();
	~RaptorShip();
	void Init(int x, int y, int r, int h, int eng = 100);
	void Destroy();
	void Move();
	void Shoot();
	void Update(int playerX, int playerY);
	void Draw();

};

