#pragma once

#include "EnemyObject.h"

class PlayerBullet : public EnemyObject 
{
public:
	 PlayerBullet();
	 void Init(int x, int y, unsigned int r, int h, int eng = 100) override;
	 void Destroy() override;
	 void Move() override;
	 EnemyObject* Shoot() override;
	 void Update(int playerX, int playerY) override;
	 void Draw() override;
};

