#include "RaptorShip.h"
#include "Platform.h"



RaptorShip::RaptorShip()
{
	
}

RaptorShip::~RaptorShip()
{
}

void RaptorShip::Init(int x, int y, unsigned int r, int h, int eng)
{
	harm = h;
	radius = r;
	positionx=x;
	positiony=y;
	energy=eng;
	image.LoadImage("assets/raptorShip.png");
}

void RaptorShip::Destroy()
{

}

void RaptorShip::Move()
{
	positiony++;
	auto p = Platform::GetPtr();
	if (positiony >= (p->GetHeight() / 2))
	{
		positionx++;
	}
}
void RaptorShip::Shoot()
{

}

void RaptorShip::Update(int playerX, int playerY)
{
	Move();
}

void RaptorShip::Draw()
{
	auto p = Platform::GetPtr();
	p->RenderTexture(&image, positionx, positiony);

}

int RaptorShip::GetPositionX() 
{
	return positionx;
}

int RaptorShip::GetPositionY() 
{
	return positionx;
}

unsigned int RaptorShip::GetRadius() 
{
	return radius;
}