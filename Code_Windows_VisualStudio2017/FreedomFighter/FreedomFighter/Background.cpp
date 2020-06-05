#include "pch.h"
#include"Background.h"

Background::Background()
{

}

Background::~Background()
{
    spriteSheetTexture = NULL;
    cout<<"Background Deallocated"<<endl;
}

Background::Background(LTexture* image, float x, float y, int SCREEN_WIDTH):Unit(image, x, y)
{
	this->SCREEN_WIDTH = SCREEN_WIDTH;
    spriteSheetTexture = image;

    // setting frame's x, y coordinates and width, height
    spriteClips[ 0 ].x = 0;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w =2048;
    spriteClips[ 0 ].h = 1256;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 1.0f;
    speedx = 0;
    speedy = 1;
    alive  = true;
    this->ID = 0;
    explode=false;

    // scaling background screen
	scale = (float)SCREEN_WIDTH / (float)spriteClips[0].w;
}


void Background::Move(int playerX,int playerY)
{
    // enable vertical background screen movement
    y = y + speedy*friction;

    // continuous screen motion
    if (y>= spriteClips[0].h *scale*2)
    {
        y=-(spriteClips[0].h *scale);
    }


}

void Background::Render(long int& frame, SDL_Renderer* gRenderer)
{
    // renders background
	spriteSheetTexture->Render( x, y, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer, scale);
}
