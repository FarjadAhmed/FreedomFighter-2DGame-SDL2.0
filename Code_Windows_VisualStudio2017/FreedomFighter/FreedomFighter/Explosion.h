#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Unit.h"

using namespace std;


class Explosion:public Unit
{
    private:
        int check = 0;

    public:
        Explosion(LTexture* image, float x, float y);
        Explosion();
        ~Explosion();
        void Render(long int& frame, SDL_Renderer* gRenderer);

};



