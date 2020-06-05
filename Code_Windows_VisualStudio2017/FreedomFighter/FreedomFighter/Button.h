#pragma once
#include "Word.h"
#include "Character.h"

class Button
{
    float x;
    float y;
    int width;
    int height;
    SDL_Rect buttonLeft;
    SDL_Rect* buttonCenter;
    SDL_Rect buttonRight;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    LTexture* spriteSheetTexture1;
    LTexture* spriteSheetTexture2;
    int letters;
    Word* myWord = NULL;
    int yPosition;

public:
    Button();
    ~Button();
    Button(LTexture* image1, LTexture* image2, int SCREEN_WIDTH, int SCREEN_HEIGHT, int yPosition, char* word);
    void Render(SDL_Renderer* gRenderer);
};
