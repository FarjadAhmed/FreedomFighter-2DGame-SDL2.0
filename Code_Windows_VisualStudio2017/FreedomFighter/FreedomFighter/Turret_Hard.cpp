#include "pch.h"
#include"Turret_Hard.h"
#include <math.h>
#include <cmath>
using namespace std;

//const float PI = 3.14159265;

Turret_Hard::Turret_Hard()
{

}

Turret_Hard::~Turret_Hard()
{
    spriteSheetTexture = NULL;
    cout<<"Turret_Hard Deallocated"<<endl;
}

Turret_Hard::Turret_Hard(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;

    spriteClips[ 0 ].x = 1;
    spriteClips[ 0 ].y = 1;
    spriteClips[ 0 ].w = 84;
    spriteClips[ 0 ].h = 128;

    spriteClips[ 1 ].x = 87;
    spriteClips[ 1 ].y = 1;
    spriteClips[ 1 ].w = 45;
    spriteClips[ 1 ].h = 250;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.975f;
    speedx = 0;
    speedy = +4;
    alive  = true;
    this->ID = 33;
    explode=false;
    health = 150;
}

// Tank's turret follows Player
void Turret_Hard::Move(int playerX,int playerY)
{
    x = x + speedx*friction;
    y = y + speedy*friction;

	if (y>1000)
	{
		this->alive = false;
	}

    angle = atan2(playerX - x, playerY - y);
    angle = angle * 180 / 3.14159265;
}

void Turret_Hard::Render(long int& frame, SDL_Renderer* gRenderer)
{
	//body
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 180, NULL, SDL_FLIP_NONE, gRenderer, 1 );
    //turret
	spriteSheetTexture->Render( x - width/4, y - 2.25*height/2, &spriteClips[ 1 ], 180-angle, NULL, SDL_FLIP_NONE, gRenderer, 1 );
    SDL_Color color1={255, 0, 0, 0xFF};
    SDL_Color color2={255, 255, 0, 0xFF};
    this->RenderHPBar(x+width*0.25, y-height, -50, 3, health, color1, color2, gRenderer);
}
