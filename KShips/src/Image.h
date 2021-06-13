#pragma once
#include "SDL.h"
#include <string>
#include "SDL_image.h"

class Image
{
private:
	SDL_Texture* image;
	std::string name;
public:
	void LoadImage(std::string name);
	SDL_Texture* GetTexture();
};

