#include "pch.h"
#include"Screens.h"

Screens::Screens()
{

}

Screens::~Screens()
{
    spriteSheetTexture = NULL;
    cout<<"Screens Deallocated"<<endl;
}

Screens::Screens(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;


    spriteClips[ 0 ].x =     0;
    spriteClips[ 0 ].y =     0;
    spriteClips[ 0 ].w =  1024;
    spriteClips[ 0 ].h =   768;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}


void Screens::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x, y, &spriteClips[0], 0, NULL, SDL_FLIP_NONE, gRenderer,0.3 );
}
