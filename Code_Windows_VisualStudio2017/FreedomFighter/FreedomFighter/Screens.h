#pragma once

#include"Unit.h"

class Screens:public Unit
{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
public:
    Screens(LTexture* image, float x, float y);
    Screens();
    virtual ~Screens();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
