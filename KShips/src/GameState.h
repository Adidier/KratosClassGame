#pragma once
class GameState
{
public:
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual bool Input(const unsigned char*) = 0;
	virtual void Close() = 0;
};

