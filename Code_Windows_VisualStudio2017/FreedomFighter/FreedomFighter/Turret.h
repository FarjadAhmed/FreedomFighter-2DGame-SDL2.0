#pragma once

#include"Unit.h"

class Turret:public Unit
{
public:
    Turret(LTexture* image, float x, float y);
    Turret();
    virtual ~Turret();
    virtual void Move(int playerX,int playerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
