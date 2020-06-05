#pragma once

#include"Unit.h"

class Turret_Hard:public Unit
{
public:
    Turret_Hard(LTexture* image, float x, float y);
    Turret_Hard();
    virtual ~Turret_Hard();
    virtual void Move(int playerX,int playerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
