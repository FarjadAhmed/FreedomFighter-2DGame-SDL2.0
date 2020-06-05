#pragma once

#include"Unit.h"

class Boss_Weapon:public Unit
{
public:
    Boss_Weapon(LTexture* image, float x, float y, int angle);
    Boss_Weapon();
    virtual ~Boss_Weapon();
    virtual void Move(int playerX,int playerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
