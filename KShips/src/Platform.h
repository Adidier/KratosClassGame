#ifndef PLATFORM_H
#define PLATFORM_H

#include "SDL.h"
#include "Image.h"
#include "GameState.h"
#include <string>

class Platform
{
private:
	int width;
	int height;
	std::string name;
	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;
	const Uint8* keyboard_state_array;
	static Platform* ptr;
private:
	Platform();
public:	
	static Platform* GetPtr();
	int GetHeight();
	int GetWidth();
	bool Init(int width, int heigth);
	void Close();
	void RenderClear();
	void RenderPresent();
	void Input(GameState* obj, bool (GameState::* f)(const Uint8*));
	SDL_Renderer* GetRenderer();
	void RenderTexture(Image* tex, int x, int y);
	
};

#endif