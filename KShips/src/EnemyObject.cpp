#include "EnemyObject.h"

int EnemyObject::GetPositionX()
{
	return positionx;
}

int EnemyObject::GetPositionY() 
{
	return positiony;
}

unsigned int EnemyObject::GetRadius()
{
	return radius;
}

int EnemyObject::GetWidth()
{
	return image.GetWidth();
}

int EnemyObject::GetHeight()
{
	return image.GetHeight();
}