#include "pch.h"
#include "Turret_Straight_Missile.h"
#include <math.h>
#include <cmath>


Turret_Straight_Missile::Turret_Straight_Missile()
{

}

Turret_Straight_Missile::~Turret_Straight_Missile()
{
    spriteSheetTexture = NULL;
    cout<<"Turret_Homing_Missile Deallocated"<<endl;
}

Turret_Straight_Missile::Turret_Straight_Missile(LTexture* image, float x, float y, float angle):Unit(image, x, y)
{
    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   3;
    spriteClips[ 0 ].y = 270;
    spriteClips[ 0 ].w =  32;
    spriteClips[ 0 ].h =  92;

    spriteClips[ 1 ].x =  33;
    spriteClips[ 1 ].y = 270;
    spriteClips[ 1 ].w =  32;
    spriteClips[ 1 ].h =  92;

    spriteClips[ 2 ].x =  63;
    spriteClips[ 2 ].y = 270;
    spriteClips[ 2 ].w =  32;
    spriteClips[ 2 ].h =  92;

    spriteClips[ 3 ].x =  93;
    spriteClips[ 3 ].y = 270;
    spriteClips[ 3 ].w =  32;
    spriteClips[ 3 ].h =  92;

    spriteClips[ 4 ].x = 126;
    spriteClips[ 4 ].y = 270;
    spriteClips[ 4 ].w =  32;
    spriteClips[ 4 ].h =  92;

    spriteClips[ 5 ].x = 161;
    spriteClips[ 5 ].y = 270;
    spriteClips[ 5 ].w =  32;
    spriteClips[ 5 ].h =  92;

    spriteClips[ 6 ].x = 197;
    spriteClips[ 6 ].y = 270;
    spriteClips[ 6 ].w =  32;
    spriteClips[ 6 ].h =  92;

    spriteClips[ 7 ].x = 231;
    spriteClips[ 7 ].y = 270;
    spriteClips[ 7 ].w =  32;
    spriteClips[ 7 ].h =  92;

    spriteClips[ 8 ].x = 262;
    spriteClips[ 8 ].y = 270;
    spriteClips[ 8 ].w =  32;
    spriteClips[ 8 ].h =  92;

    spriteClips[ 9 ].x = 292;
    spriteClips[ 9 ].y = 270;
    spriteClips[ 9 ].w =  32;
    spriteClips[ 9 ].h =  92;

    spriteClips[ 10 ].x = 321;
    spriteClips[ 10 ].y = 270;
    spriteClips[ 10 ].w =  32;
    spriteClips[ 10 ].h =  92;

    spriteClips[ 11 ].x = 350;
    spriteClips[ 11 ].y = 270;
    spriteClips[ 11 ].w =  32;
    spriteClips[ 11 ].h =  92;

    spriteClips[ 12 ].x = 378;
    spriteClips[ 12 ].y = 270;
    spriteClips[ 12 ].w =  32;
    spriteClips[ 12 ].h =  92;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 1.0f;
    speedx = 5;
    speedy = 5;
    alive  = true;
    this->ID = 43;
    explode=false;
	this->angle = angle;
	health = 100;
}

// moves in the direction at which it was shot.
void Turret_Straight_Missile::Move(int playerX,int playerY)
{

	x = x + speedx*sin((PI / 180)*angle);
	y = y + speedy*cos((PI / 180)*angle);

	if (x < -10 || x>1034 || y < -10 || y>778)
	{
		alive = false;
	}
}

void Turret_Straight_Missile::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % 13 ], 180-angle, NULL, SDL_FLIP_NONE, gRenderer, 1 );
}