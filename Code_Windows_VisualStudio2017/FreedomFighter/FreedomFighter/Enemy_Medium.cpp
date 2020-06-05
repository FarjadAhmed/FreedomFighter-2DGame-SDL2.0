#include "pch.h"
#include"Enemy_Medium.h"

Enemy_Medium::Enemy_Medium()
{

}

Enemy_Medium::~Enemy_Medium()
{
    cout<<"Enemy_Medium Deallocated"<<endl;
}

Enemy_Medium::Enemy_Medium(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;


    //Frame 0

    spriteClips[ 0 ].x =    6;
    spriteClips[ 0 ].y =   40;
    spriteClips[ 0 ].w =  147;
    spriteClips[ 0 ].h =   77;

    //Frame 1
	spriteClips[1].x = 173;
	spriteClips[1].y = 40;
	spriteClips[1].w = 147;
	spriteClips[1].h = 77;

    //Frame 2
	spriteClips[2].x = 341;
	spriteClips[2].y = 40;
	spriteClips[2].w = 147;
	spriteClips[2].h = 77;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 3;
    alive  = true;
    angle = 180;
    ID = 22;
    explode=false;
    health=100;
}

//follows player in just x-direction
void Enemy_Medium::Move(int playerX, int playerY)
{
    angle = atan2(playerX - x, playerY - y);
    x = x + sin((angle))*3;
    y = y + speedy;

    if (y>1000)
    {
        this->alive=false;
    }
    angle = 0;
}

void Enemy_Medium::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 180-angle, NULL, SDL_FLIP_NONE, gRenderer,1 );
    SDL_Color color1={255, 0, 0, 0xFF};
    SDL_Color color2={255, 255, 0, 0xFF};
    this->RenderHPBar(x+width*0.25, y-height, -50, 3, health, color1, color2, gRenderer);
}
