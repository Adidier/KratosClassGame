#pragma once
#include "Image.h"

class EnemyObject
{
protected:
	const float speed = 10;

	int positionx;
	int positiony;
	unsigned int radius;
	Image image;
	int harm;
	int energy;


public:
	virtual void Init(int x, int y, unsigned int r, int h, int eng = 100) = 0;
	virtual void Destroy() = 0;
	virtual void Move() = 0;
	virtual EnemyObject* Shoot() = 0;
	virtual void Update(int playerX, int playerY) = 0;
	virtual void Draw() = 0;
	int GetPositionX();
	int GetPositionY();
	unsigned int GetRadius();
};
