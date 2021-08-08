#include "PlayerBullet.h"
#include "Platform.h"

PlayerBullet::PlayerBullet()
{
	image.LoadImage("assets/bullet.png");
}

void PlayerBullet::Init(int x, int y, unsigned int r, int h, int eng)
{
	harm = h;
	radius = r;
	positionx = x;
	positiony = y;
	energy = eng;	
}

void PlayerBullet::Destroy() 
{

}

void PlayerBullet::Move()
{
	positiony-=4;
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
	auto p = Platform::GetPtr();
	p->RenderTexture(&image, positionx, positiony);
}