#pragma once

#include"Unit.h"

class Enemy_Easy:public Unit
{
public:
    Enemy_Easy(LTexture* image, float x, float y);
    Enemy_Easy();
    virtual ~Enemy_Easy();
    virtual void Move(int playerX, int PlayerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
