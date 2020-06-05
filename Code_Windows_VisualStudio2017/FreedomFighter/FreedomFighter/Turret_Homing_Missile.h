#pragma once

#include"Unit.h"

class Turret_Homing_Missile:public Unit
{
public:
    Turret_Homing_Missile(LTexture* image, float x, float y, float angle);
    Turret_Homing_Missile();
    virtual ~Turret_Homing_Missile();
    virtual void Move(int playerX,int playerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
