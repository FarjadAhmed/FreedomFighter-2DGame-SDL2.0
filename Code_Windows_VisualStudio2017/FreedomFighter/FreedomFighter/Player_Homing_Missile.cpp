#include "pch.h"
#include "Player_Homing_Missile.h"

#include <math.h>
#include <cmath>

Player_Homing_Missile::Player_Homing_Missile()
{

}

Player_Homing_Missile::~Player_Homing_Missile()
{
    spriteSheetTexture = NULL;
    cout<<"Player_Homing_Missile Deallocated"<<endl;
}

Player_Homing_Missile::Player_Homing_Missile(LTexture* image, float x, float y):Unit(image, x, y)//position of the homing missile to be produceed
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
    speedx = 0;
    speedy = -5;
    alive  = true;
    this->ID = 49;
    explode=false;
    target = NULL; //target is null initially
}


void Player_Homing_Missile::Move(int playerX,int playerY)
{



    if(target!=NULL)  
    {
        playerX = target->GetX();
        playerY = target->GetY();


    }

    angle = atan2(playerX - x, playerY - y); //archtan2 so that it gives zero at infinity
    x = x + sin((angle))*11;
    y = y + cos((angle))*11;
    angle = angle * 180 / PI; //angle to degrees

	if (x < -10 || x>1034 || y < -10 || y>778)
	{
		alive = false;
	}
}

Unit* Player_Homing_Missile::GetTarget() //get the pointer
{
    return target;
}

void Player_Homing_Missile::SetTarget(Unit* target)   //function to set target for the missile
{
    this->target = target; 
}

void Player_Homing_Missile::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[  0 ], 90-angle, NULL, SDL_FLIP_NONE, gRenderer,0.5 );
}

