#include "pch.h"
#include"Enemy_Bullet.h"

Enemy_Bullet::Enemy_Bullet()
{

}

Enemy_Bullet::~Enemy_Bullet()
{
    spriteSheetTexture = NULL;
    cout<<"Enemy_Bullet Deallocated"<<endl;
}

Enemy_Bullet::Enemy_Bullet(LTexture* image, float x, float y, float angle) :Unit(image, x, y)
{
    spriteSheetTexture = image;


    spriteClips[ 0 ].x = 111;
    spriteClips[ 0 ].y = 197;
    spriteClips[ 0 ].w =   6;
    spriteClips[ 0 ].h =  14;

    //Frame 1
    spriteClips[ 1 ].x = 143;
    spriteClips[ 1 ].y = 197;
    spriteClips[ 1 ].w =   6;
    spriteClips[ 1 ].h =  14;

    //Frame 2
    spriteClips[ 2 ].x = 175;
    spriteClips[ 2 ].y = 197;
    spriteClips[ 2 ].w =   6;
    spriteClips[ 2 ].h =  14;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 1.0f;
    speedx = 12;
    speedy = 12;
    alive  = true;
    this->ID = 42;
	this->angle = angle;
}

//moves the bullet at a given angle.
void Enemy_Bullet::Move(int playerX,int playerY)
{
	x = x + speedx*sin((PI / 180)*angle);
	y = y + speedy*cos((PI / 180)*angle);

	if (x < -10 || x>1034 || y < -10 || y>778)
	{
		alive = false;
	}
}

void Enemy_Bullet::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], angle, NULL, SDL_FLIP_NONE, gRenderer,1 );
}
