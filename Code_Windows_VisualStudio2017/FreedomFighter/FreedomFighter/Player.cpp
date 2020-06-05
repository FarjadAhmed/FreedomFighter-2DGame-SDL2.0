#include "pch.h"
#include"Player.h"

//SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

Player::Player()
{

}

Player::~Player()
{
    spriteSheetTexture=NULL;
    cout<<"Player Deallocated"<<endl;
}


Player::Player(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 1527;
    spriteClips[ 0 ].y =   28;
    spriteClips[ 0 ].w =  109;
    spriteClips[ 0 ].h =  94;

    //Frame 1
	spriteClips[1].x = 1695;
	spriteClips[1].y = 28;
	spriteClips[1].w = 109;
	spriteClips[1].h = 94;

    //Frame 2
	spriteClips[2].x = 1862;
	spriteClips[2].y = 28;
	spriteClips[2].w = 109;
	spriteClips[2].h = 94;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
    angle = 0;
    ID = 10;
    explode=false;
    health=100;
}

void Player::Move(int direction)
{

    if(direction==LEFT)
    {
        speedx = -5;
        x+=speedx;
    }

    if(direction==RIGHT)
    {
        speedx = 5;
        x+=speedx;
    }

    if(direction==UP)
    {
        speedy = -5;
        y+=speedy;
    }

    if(direction==DOWN)
    {
        speedy = 5;
        y+=speedy;
    }

}

void Player::Move()
{
     speedx = speedx * friction;
     speedy = speedy * friction;

     x = x + speedx;
     y = y + speedy;
}

void Player::Render(long int& frame, SDL_Renderer* gRenderer)
{
    SDL_Color color1={255, 0, 0, 0xFF};
    SDL_Color color2={255, 255, 0, 0xFF};
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], angle, NULL, SDL_FLIP_NONE, gRenderer,1 );
    this->RenderHPBar(550, 50, -500, 30, health, color1, color2, gRenderer);
}
