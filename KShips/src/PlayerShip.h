#pragma once
#include "Image.h"
#include "RaptorShip.h"
#include <vector>

class PlayerShip
{
private:
	int positionX;
	int positionY;
	int energy; 
	int weapon;
	int currentWeapon;
	Image image;
	unsigned int radius;
	int coolDown;


public:
	PlayerShip();
	~PlayerShip();
	
	void Init(int x, int y,unsigned int r,int eng=100);
	void Dash();
	void Shoot();
	void Move();
	void Dead();
	void Draw();
	void Update(std::vector<RaptorShip*> &ship);
	void SetCurrentWeapon(int weapon);	
};


