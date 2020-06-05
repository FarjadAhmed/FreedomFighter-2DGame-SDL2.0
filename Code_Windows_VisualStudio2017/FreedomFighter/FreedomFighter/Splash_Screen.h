#pragma once

#include"Unit.h"

class Splash_Screen :public Unit
{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
	float scale;
public:
	Splash_Screen(LTexture* image, float x, float y, int SCREEN_WIDTH);
	Splash_Screen();
    ~Splash_Screen();
    void Render(long int& frame, SDL_Renderer* gRenderer);
};
