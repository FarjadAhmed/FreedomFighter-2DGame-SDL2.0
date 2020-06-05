#pragma once
#include"Unit.h"

class Player_Homing_Missile:public Unit
{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    Unit* target;
public:
    Player_Homing_Missile(LTexture* image, float x, float y);
    Player_Homing_Missile();
    ~Player_Homing_Missile();
    void Move(int playerX,int playerY);
    void Render(long int& frame, SDL_Renderer* gRenderer);
    Unit* GetTarget();
    void SetTarget(Unit*);
};
