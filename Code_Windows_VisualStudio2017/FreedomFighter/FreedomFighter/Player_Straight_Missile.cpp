#include "pch.h"
#include "Player_Straight_Missile.h"

#include <math.h>
#include <cmath>

Player_Straight_Missile::Player_Straight_Missile()
{

}

Player_Straight_Missile::~Player_Straight_Missile()
{
    spriteSheetTexture = NULL;
    cout<<"Player_Straight_Missile Deallocated"<<endl;
}

Player_Straight_Missile::Player_Straight_Missile(LTexture* image, float x, float y):Unit(image, x, y)//position to be produced
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


    friction = 0.975f;
    speedy = -5;
    alive  = true;
    this->ID = 48;
    explode=false;
    target = NULL;
}


void Player_Straight_Missile::Move(int playerX,int playerY)//move straight upwards
{
    y = y + speedy*friction;

    if (y+height/2<-100)
    {
        alive = false;
    }
}

void Player_Straight_Missile::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[  0 ], 270, NULL, SDL_FLIP_NONE, gRenderer,0.5 );
}

