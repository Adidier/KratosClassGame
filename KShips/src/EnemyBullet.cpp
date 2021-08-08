#include "EnemyBullet.h"
#include "Platform.h"

void EnemyBullet::Init(int x, int y, unsigned int r, int h, int eng)
{
	harm = h;
	radius = r;
	positionx = x;
	positiony = y;
	energy = eng;
	image.LoadImage("assets/bulletEnemy.png");
}

void EnemyBullet::Destroy()
{
}

void EnemyBullet::Move()
{
	positiony += 2;
}

EnemyObject* EnemyBullet::Shoot()
{
	return nullptr;
}

void EnemyBullet::Update(int playerX, int playerY) 
{
}

void EnemyBullet::Draw()
{
	auto p = Platform::GetPtr();
	p->RenderTexture(&image, positionx, positiony);
}