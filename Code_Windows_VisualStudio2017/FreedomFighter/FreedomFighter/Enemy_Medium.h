#pragma once

#include"Unit.h"

class Enemy_Medium:public Unit
{
public:
    Enemy_Medium(LTexture* image, float x, float y);
    Enemy_Medium();
    virtual ~Enemy_Medium();
    virtual void Move(int playerX, int PlayerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
