#pragma once

#include"Unit.h"

class Enemy_Bullet:public Unit
{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
public:
	Enemy_Bullet(LTexture* image, float x, float y, float angle);
    Enemy_Bullet();
    virtual ~Enemy_Bullet();
    virtual void Move(int playerX,int playerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
