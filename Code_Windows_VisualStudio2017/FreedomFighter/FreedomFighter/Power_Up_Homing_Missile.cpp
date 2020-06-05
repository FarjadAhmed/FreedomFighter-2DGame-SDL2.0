#include "pch.h"
#include"Power_Up_Homing_Missile.h"

Power_Up_Homing_Missile::Power_Up_Homing_Missile()
{

}

Power_Up_Homing_Missile::~Power_Up_Homing_Missile()
{
    cout<<"Power_Up_Homing_Missile Deallocated"<<endl;
}

Power_Up_Homing_Missile::Power_Up_Homing_Missile(LTexture* image, float x, float y):Unit(image, x, y)//taking in position to be produced
{
    spriteSheetTexture = image; 

    spriteClips[ 0 ].x = 10;
    spriteClips[ 0 ].y =   5;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 34;


    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    speedy = 5;
    alive  = true;
    angle = 180;
    ID = 50;
    explode=false;
}


void Power_Up_Homing_Missile::Move(int playerX, int PlayerY) // movement of homing missile power up
{  
    y = y + speedy;

    if (y>800)
    {
        this->alive=false;
    }

}

void Power_Up_Homing_Missile::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], frame*6 , NULL, SDL_FLIP_NONE, gRenderer,0.5 );
}
