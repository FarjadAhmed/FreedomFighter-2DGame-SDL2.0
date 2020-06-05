#pragma once

#include"Unit.h"

class Player_Bullet:public Unit
{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
public:
    Player_Bullet(LTexture* image, float x, float y);
    Player_Bullet();
    virtual ~Player_Bullet();
    virtual void Move(int playerX,int playerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
