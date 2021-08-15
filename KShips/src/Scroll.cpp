#include "Scroll.h"
#include "Platform.h"


void Scroll::Init(std::string path,float speed)
{
	LoadImage(path);
	positionx = 0;
	auto p = Platform::GetPtr();
	this->w = p->GetWidth();
	this->h = p->GetHeight();
	positiony = h - GetHeight();
	this->speed = speed;
}

void Scroll::Update(float time)
{
	
	positiony += speed;
}

void Scroll::Draw()
{
	auto p = Platform::GetPtr();
	p->RenderTexture(this, positionx, positiony,w,h);
}