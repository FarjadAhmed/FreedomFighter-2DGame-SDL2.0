#include "pch.h"
#include"Enemy_Hard.h"

Enemy_Hard::Enemy_Hard()
{

}

Enemy_Hard::~Enemy_Hard()
{
    cout<<"Enemy_Hard Deallocated"<<endl;
}

Enemy_Hard::Enemy_Hard(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 1013;
    spriteClips[ 0 ].y =   45;
    spriteClips[ 0 ].w =  155;
    spriteClips[ 0 ].h =  80;

    //Frame 1
	spriteClips[1].x = 1182;
	spriteClips[1].y = 45;
	spriteClips[1].w = 155;
	spriteClips[1].h = 80;

    //Frame 2
	spriteClips[2].x = 1349;
	spriteClips[2].y = 45;
	spriteClips[2].w = 155;
	spriteClips[2].h = 80;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 2;
    speedy = 2;
    alive  = true;
    angle = 180;
    ID = 23;
    explode=false;
    health=100;
}

//follows Player
void Enemy_Hard::Move(int playerX, int playerY)
{
    angle = atan2(playerX - x, playerY - y);
    x = x + sin((angle))*speedx;
    y = y + cos((angle))*speedy;
    angle = angle * 180 / PI;
}

void Enemy_Hard ::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 180-angle, NULL, SDL_FLIP_NONE, gRenderer,1 );
    SDL_Color color1={255, 0, 0, 0xFF};
    SDL_Color color2={255, 255, 0, 0xFF};
    this->RenderHPBar(x+width*0.25, y-height, -50, 3, health, color1, color2, gRenderer);
}
