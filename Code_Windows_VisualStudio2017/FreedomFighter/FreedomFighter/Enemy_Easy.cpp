#include "pch.h"
#include"Enemy_Easy.h"

Enemy_Easy::Enemy_Easy()
{

}

Enemy_Easy::~Enemy_Easy()
{
    cout<<"Enemy_Easy Deallocated"<<endl;
}

Enemy_Easy::Enemy_Easy(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x =  509;
    spriteClips[ 0 ].y =   27;
    spriteClips[ 0 ].w =  150;
    spriteClips[ 0 ].h =  97;

    //Frame 1
	spriteClips[1].x = 509;
	spriteClips[1].y = 27;
	spriteClips[1].w = 150;
	spriteClips[1].h = 97;

    //Frame 2
	spriteClips[2].x = 509;
	spriteClips[2].y = 27;
	spriteClips[2].w = 150;
	spriteClips[2].h = 97;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 5;
    alive  = true;
    angle = 180;
    ID = 21;
    explode=false;
    health=100;
}


void Enemy_Easy::Move(int playerX, int PlayerY)
{

    x = x + speedx;
    y = y + speedy;

	if (y>1000)
	{
		this->alive = false;
	}

}

void Enemy_Easy::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], angle, NULL, SDL_FLIP_NONE, gRenderer,1 );
    SDL_Color color1={255, 0, 0, 0xFF};
    SDL_Color color2={255, 255, 0, 0xFF};
    this->RenderHPBar(x+width*0.25, y-height, -50, 3, health, color1, color2, gRenderer);
}
