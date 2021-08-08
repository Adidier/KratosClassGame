#pragma once
#include "SDL.h"
#include <string>
#include "SDL_image.h"

class Image
{
private:
	SDL_Texture* image;
	std::string name;
	SDL_Point size;
public:
	void LoadImage(std::string name);
	SDL_Texture* GetTexture();
	int GetWidth();
	int GetHeight();
};

