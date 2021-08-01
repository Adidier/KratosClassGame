#include "PlayerShip.h"
#include "Platform.h"
#include "Utils.h"

PlayerShip::PlayerShip()
{

}

PlayerShip::~PlayerShip()
{

}

void PlayerShip::Init(int x, int y,unsigned int r, int eng, int _speed)
{
	radius = r;
	positionX = x;
	positionY = y;
	speed = _speed;
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
	if (energy > 0)
	{
		Platform* ptr = Platform::GetPtr();
		ptr->RenderTexture(&image, positionX, positionY);
	}
}

void PlayerShip::Update(std::list<EnemyObject*> &ships)
{
	for (auto ship : ships)
	{
		if (Utils::CheckCollision(positionX, positionY, radius, ship->GetPositionX(), ship->GetPositionY(), ship->GetRadius()))
		{
			energy = 0;
		}
	}
}

void PlayerShip::SetCurrentWeapon(int weapon)
{

}

void PlayerShip::Input(const unsigned char* keys)
{
	if (keys[SDL_SCANCODE_W]) {
		positionY -= speed;
	}
	else if (keys[SDL_SCANCODE_S]) {
		positionY += speed;
	}
	if (keys[SDL_SCANCODE_A]){
		positionX -= speed;
	}
	else if (keys[SDL_SCANCODE_D]) {
		positionX += speed;
	}

	if (keys[SDL_SCANCODE_SPACE]) {
		Shoot();
	}
}