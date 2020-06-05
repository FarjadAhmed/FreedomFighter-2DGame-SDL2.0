#pragma once

#include"Unit.h"

class Turret_Straight_Missile :public Unit
{
public:
	Turret_Straight_Missile(LTexture* image, float x, float y, float angle);
	Turret_Straight_Missile();
    virtual ~Turret_Straight_Missile();
    virtual void Move(int playerX,int playerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
