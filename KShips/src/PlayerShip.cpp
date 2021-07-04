#include "PlayerShip.h"
#include "Platform.h"

PlayerShip::PlayerShip()
{

}
PlayerShip::~PlayerShip()
{

}

void PlayerShip::Init(int x, int y, int r, int eng)
{

	radius = r;
	positionX = x;
	positionY = y;
	
	energy = eng;
	image.LoadImage("assets/playerShip.png");
}

void PlayerShip::Dash()
{

}

void PlayerShip::Shoot()
{

}

void PlayerShip::Move()
{

}

void PlayerShip::Dead()
{

}

void PlayerShip::Draw()
{
	Platform* ptr=Platform::GetPtr();
	ptr->RenderTexture(&image,positionX,positionY);
}

void PlayerShip::Update()
{

}

void PlayerShip::SetCurrentWeapon(int weapon)
{

}