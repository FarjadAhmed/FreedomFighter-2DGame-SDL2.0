#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"

class Character
{
    float x;
    float y;
    int width;
    int height;
    int letterNum = 0;
    SDL_Rect spriteClip;
    LTexture* spriteSheetTexture;
public:
    Character();
    ~Character();
    void SetChar(LTexture* image, float x, float y, char letter);
    void Render(SDL_Renderer* gRenderer);
};
