#pragma once
#include "SDL.h"
#include "Image.h"
#include "GameState.h"
#include <string>

class Platform
{
private:
	int width;
	int heigth;
	std::string name;
	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;

	static Platform* ptr;
private:
	Platform();
public:	
	static Platform* GetPtr();
	bool Init(int width, int heigth);
	void Close();
	void RenderClear();
	void RenderPresent();
	void Input(GameState* obj, bool (GameState::* f)(int));
	SDL_Renderer* GetRenderer();
	void RenderTexture(Image* tex, int x, int y);
	
};

