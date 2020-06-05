#include "pch.h"
#include"Player_Bullet.h"

Player_Bullet::Player_Bullet()
{

}

Player_Bullet::~Player_Bullet()
{
    spriteSheetTexture = NULL;
    cout<<"Player_Bullet Deallocated"<<endl;
}

Player_Bullet::Player_Bullet(LTexture* image, float x, float y):Unit(image, x, y) //giving in the image and x,,y of the plane
{
    spriteSheetTexture = image;


    spriteClips[ 0 ].x =  11;
    spriteClips[ 0 ].y = 197;
    spriteClips[ 0 ].w =  14;
    spriteClips[ 0 ].h =  15;

    //Frame 1
    spriteClips[ 1 ].x =  43;
    spriteClips[ 1 ].y = 197;
    spriteClips[ 1 ].w =  14;
    spriteClips[ 1 ].h =  15;

    //Frame 2
    spriteClips[ 2 ].x =  75;
    spriteClips[ 2 ].y = 197;
    spriteClips[ 2 ].w =  14;
    spriteClips[ 2 ].h =  15;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 1.0f;
    speedx = 0;
    speedy = -12;
    alive  = true;
    this->ID = 41;
}


void Player_Bullet::Move(int playerX,int playerY) //movement for bullet
{
    x = x + speedx*friction;  
    y = y + speedy*friction;

    if (y+height/2<-100)
    {
        alive = false;
    }


}

void Player_Bullet::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer,1 );
}
