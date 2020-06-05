#pragma once

#include"Unit.h"

class Boss:public Unit
{
public:
    Boss(LTexture* image, float x, float y);
    Boss();
    virtual ~Boss();
    void Move(int playerX,int playerY);
    void Render(long int& frame, SDL_Renderer* gRenderer);
};
