
#pragma once

#include"Unit.h"

class Power_Up_Homing_Missile:public Unit
{
public:
    Power_Up_Homing_Missile(LTexture* image, float x, float y); 
    Power_Up_Homing_Missile();
    ~Power_Up_Homing_Missile();
    void Move(int playerX, int PlayerY);
    void Render(long int& frame, SDL_Renderer* gRenderer);
};
