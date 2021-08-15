#include "Scroll.h"
#include "Platform.h"

void Scroll::Init(std::string path, float speed)
{
	auto p = Platform::GetPtr();
	LoadImage(path);
	winHeight = p->GetHeight();
	winWidth = p->GetWidth(); 
	this->speed = speed;
	positionx = 0;
	positiony = GetHeight() - winHeight;
}

void Scroll::Move(float time)
{
	if (positiony-speed < winHeight)
	{
		positiony = GetHeight() - winHeight;
		return;
	}
	positiony -= speed;
}

void Scroll::Draw()
{
	auto p = Platform::GetPtr();
	p->RenderTexture(this, positionx, positiony, winWidth, winHeight);
}
