#include "Image.h"
#include "Platform.h"

void Image::LoadImage(std::string name)
{
	this->name = name;
	SDL_Surface* loadSurface = IMG_Load(name.c_str());
	image = SDL_CreateTextureFromSurface(Platform::GetPtr()->GetRenderer(), loadSurface);
}

SDL_Texture* Image::GetTexture()
{
	return image;
}