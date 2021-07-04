#pragma once
#include "Image.h"
class PlayerShip
{

private:
	int positionX;
	int positionY;
	int energy; 
	int weapon;
	int currentWeapon;
	Image image;
	int radius;
	int coolDown;



public:
	PlayerShip();
	~PlayerShip();
	
	void Init(int x, int y, int r,int eng=100);
	void Dash();
	void Shoot();
	void Move();
	void Dead();
	void Draw();
	void Update();
	void SetCurrentWeapon(int weapon);

};


