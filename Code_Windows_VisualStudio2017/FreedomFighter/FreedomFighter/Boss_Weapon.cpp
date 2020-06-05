#include "pch.h"
#include"Boss_Weapon.h"

#include"math.h"


Boss_Weapon::Boss_Weapon()
{

}

Boss_Weapon::~Boss_Weapon()
{
    spriteSheetTexture = NULL;
    cout<<"Boss_Weapon Deallocated"<<endl;
}

Boss_Weapon::Boss_Weapon(LTexture* image, float x, float y, int angle):Unit(image, x, y)
{
    spriteSheetTexture = image;

    spriteClips[ 0 ].x = 181;
    spriteClips[ 0 ].y =  24;
    spriteClips[ 0 ].w =  68;
    spriteClips[ 0 ].h =  72;

    spriteClips[ 1 ].x = 264;
    spriteClips[ 1 ].y =  24;
    spriteClips[ 1 ].w =  72;
    spriteClips[ 1 ].h =  72;

    spriteClips[ 2 ].x = 352;
    spriteClips[ 2 ].y =  21;
    spriteClips[ 2 ].w =  68;
    spriteClips[ 2 ].h =  75;

    spriteClips[ 3 ].x = 436;
    spriteClips[ 3 ].y =  24;
    spriteClips[ 3 ].w =  68;
    spriteClips[ 3 ].h =  72;

    spriteClips[ 4 ].x = 520;
    spriteClips[ 4 ].y =  24;
    spriteClips[ 4 ].w =  72;
    spriteClips[ 4 ].h =  72;

    spriteClips[ 5 ].x = 180;
    spriteClips[ 5 ].y = 118;
    spriteClips[ 5 ].w =  68;
    spriteClips[ 5 ].h =  74;

    spriteClips[ 6 ].x = 264;
    spriteClips[ 6 ].y = 120;
    spriteClips[ 6 ].w =  72;
    spriteClips[ 6 ].h =  72;

    spriteClips[ 7 ].x = 352;
    spriteClips[ 7 ].y = 120;
    spriteClips[ 7 ].w =  72;
    spriteClips[ 7 ].h =  72;

    spriteClips[ 8 ].x = 432;
    spriteClips[ 8 ].y = 120;
    spriteClips[ 8 ].w =  72;
    spriteClips[ 8 ].h =  72;

    spriteClips[ 9 ].x = 520;
    spriteClips[ 9 ].y = 120;
    spriteClips[ 9 ].w =  72;
    spriteClips[ 9 ].h =  72;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    friction = 1.0f;

    alive  = true;
    this->ID = 71;
    speedx =  5;
    speedy = 5;
    explode=false;
	this->angle = (PI / 180)*angle;

}

//shoots at a given angle
void Boss_Weapon::Move(int playerX,int playerY)
{
    x = x + speedx*sin(angle);
    y = y + speedy*cos(angle);

	if (x < -10 || x>1034 || y < -10 || y>778)
	{
		alive = false;
	}
}

void Boss_Weapon::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % 10 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer, 1 );
}
