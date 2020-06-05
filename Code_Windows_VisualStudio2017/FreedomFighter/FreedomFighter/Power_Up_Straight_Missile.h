#pragma once

#include"Unit.h"

class Power_Up_Straight_Missile:public Unit
{
public:
    Power_Up_Straight_Missile(LTexture* image, float x, float y); //position to be produced
    Power_Up_Straight_Missile();
    ~Power_Up_Straight_Missile();
    void Move(int playerX, int PlayerY);
    void Render(long int& frame, SDL_Renderer* gRenderer);
};
