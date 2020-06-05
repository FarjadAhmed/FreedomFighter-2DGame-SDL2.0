#pragma once

#include"Unit.h"

class Player:public Unit
{
public:
    Player(LTexture* image, float x, float y);
    Player();
    virtual ~Player();
    virtual void Move();
    virtual void Move(int direction);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
