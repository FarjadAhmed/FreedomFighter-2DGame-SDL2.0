#pragma once

#include"Unit.h"

class Enemy_Hard:public Unit
{
public:
    Enemy_Hard(LTexture* image, float x, float y);
    Enemy_Hard();
    virtual ~Enemy_Hard();
    virtual void Move(int playerX, int PlayerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
