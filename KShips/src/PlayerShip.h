#pragma once
#include "Image.h"
#include "RaptorShip.h"
#include <list>
#include "PlayerBullet.h"

class PlayerShip
{
private:
	enum State
	{
		alive,
		dead, 
		invincible,
		shoot
	};

private:
	int positionX;
	int positionY;
	int energy; 
	int weapon;
	int currentWeapon;
	Image image;
	unsigned int radius;
	int coolDown;
	int speed;
	std::list<PlayerBullet*> bullets;

public:
	PlayerShip();
	~PlayerShip();
	
	void Init(int x, int y,unsigned int r,int eng=100, int speed=10);
	void Dash();
	void Shoot();
	void Move();
	void Dead();
	void Draw();
	void Update(std::list<EnemyObject*> &ship);
	void SetCurrentWeapon(int weapon);	
	void Input(const unsigned char*);
};


