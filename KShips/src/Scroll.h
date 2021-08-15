#pragma once
#include "Image.h"

class Scroll : public Image
{
private:
	int positionx, positiony = 0;
	int w, h;
	float speed;
public:
	void Init(std::string path, float speed);
	void Update(float time);
	void Draw();
};

