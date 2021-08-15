#pragma once
#include "SDL.h"
#include <string>
#include "SDL_image.h"
#include "Image.h"

class Scroll : public Image
{
private: 
	int winWidth; 
	int winHeight;
	float speed;
	int positionx;
	int positiony;

public:
	void Init(std::string path, float speed);
	void Move(float time);
	void Draw();
};

