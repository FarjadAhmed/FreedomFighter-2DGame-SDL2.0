#pragma once

#include"Unit.h"

class Health_Up:public Unit
{
public:
    Health_Up(LTexture* image, float x, float y);
    Health_Up();
    virtual ~Health_Up();
    virtual void Move(int playerX, int PlayerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
