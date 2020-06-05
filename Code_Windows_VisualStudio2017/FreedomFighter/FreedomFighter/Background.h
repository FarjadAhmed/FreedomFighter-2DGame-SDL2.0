#pragma once

#include"Unit.h"

class Background:public Unit
{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
	float scale;
public:
    Background(LTexture* image, float x, float y, int SCREEN_WIDTH);
    Background();
    virtual ~Background();
    virtual void Move(int playerX,int playerY);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
