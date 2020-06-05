#include "pch.h"
#include"Health_Up.h"

Health_Up::Health_Up()
{

}

Health_Up::~Health_Up()
{
    cout<<"Health_Up Deallocated"<<endl;
}

Health_Up::Health_Up(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 2;
    spriteClips[ 0 ].y = 131;
    spriteClips[ 0 ].w = 52;
    spriteClips[ 0 ].h =  44;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 5;
    alive  = true;
    angle = 180;
    ID = 52;
    explode=false;
}


void Health_Up::Move(int playerX, int PlayerY)
{

    x = x + speedx;
    y = y + speedy;

    if (y>800)
    {
        this->alive=false;
    }

}

void Health_Up::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 0, NULL, SDL_FLIP_NONE, gRenderer,1 );
}
