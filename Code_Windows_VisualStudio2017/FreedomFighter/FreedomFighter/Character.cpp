#include "pch.h"
#include "Character.h"

#include <string.h>

using namespace std;

Character::Character()
{

}

void Character::SetChar(LTexture* image, float x, float y, char letter)
{
    spriteSheetTexture = image;

    // ASCII code of any alphabet (for A, it's 65) MINUS 65 = letterNum
    letterNum = int(letter) - 65;

    // cropping alphabets from its sprite sheet

    if(letterNum<11 && letterNum>=0)
    {
        spriteClip.x = 44*letterNum;
        spriteClip.y = 48*0;
    }
    else if(letterNum>10 && letterNum<22)
    {
        spriteClip.x = 44*(letterNum-11);
        spriteClip.y = 48*1;
    }
    else if(letterNum>=22 && letterNum<26)
    {
        spriteClip.x = 44*(letterNum-22);
        spriteClip.y = 48*2;
    }
    else if(letterNum == -33)
    {
        spriteClip.x = 44*5;
        spriteClip.y = 48*8;
    }
    else if(letterNum<0 && letterNum>-18)
    {
        letterNum = letterNum + 25;
        if (letterNum<11)
        {
            spriteClip.x = 44*(letterNum);
            spriteClip.y = 48*4;
        }
        else
        {
            spriteClip.x = 44*(letterNum-11);
            spriteClip.y = 48*5;
        }
    }

    spriteClip.w =  44; // width of alphabet frame
    spriteClip.h =  48; // height of alphabet frame

    this->x = x;
    this->y = y;

    this->width = spriteClip.w;
    this->height = spriteClip.h;
}


Character::~Character()
{
    // deallocation
    spriteSheetTexture = NULL;
}

void Character::Render(SDL_Renderer* gRenderer)
{
    // rendering alphabets on screen, centralized from  x and y axis
    spriteSheetTexture->Render( x, y - height/2, &spriteClip, 0.0, NULL, SDL_FLIP_NONE, gRenderer,1 );
}
