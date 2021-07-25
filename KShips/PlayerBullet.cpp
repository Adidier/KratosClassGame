#include "PlayerBullet.h"

void PlayerBullet::Init(int x, int y, unsigned int r, int h, int eng)
{
	harm = h;
	radius = r;
	positionx = x;
	positiony = y;
	energy = eng;
	image.LoadImage("assets/raptorShip.png");
}

void PlayerBullet::Destroy() 
{

}

void PlayerBullet::Move()
{

}
EnemyObject* PlayerBullet::Shoot()
{
	return nullptr;
}
void PlayerBullet::Update(int playerX, int playerY)
{

}
void PlayerBullet::Draw()
{

}