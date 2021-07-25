#pragma once
#include "Image.h"
#include "EnemyBullet.h"
#include "EnemyObject.h"

class RaptorShip : public EnemyObject
{
public:
	RaptorShip();
	~RaptorShip();
	void Init(int x, int y, unsigned int r, int h, int eng = 100) override;
	void Destroy() override;
	void Move() override;
	EnemyObject* Shoot() override;
	void Update(int playerX, int playerY) override;
	void Draw() override;
	int GetPositionX();
	int GetPositionY();
	unsigned int GetRadius();
	void test()
	{}
};
