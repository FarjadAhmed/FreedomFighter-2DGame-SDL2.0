#pragma once
#include "Character.h"
#include <string.h>


class Word
{
    Character* chars;
    int letters;
public:
    Word(LTexture* image, int SCREEN_WIDTH, int SCREEN_HEIGHT, int yPosition, char* word);
    Word();
    ~Word();
    void Render(SDL_Renderer* gRenderer);
};
