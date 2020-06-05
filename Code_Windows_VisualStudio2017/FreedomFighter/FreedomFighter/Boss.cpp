#include "pch.h"
#include"Boss.h"

#include"math.h"


Boss::Boss()
{

}

Boss::~Boss()
{
    spriteSheetTexture = NULL;
    cout<<"Boss Deallocated"<<endl;
}

Boss::Boss(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;

    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i<2; i++)
    {
        for (j = 0; j<2; j++ )
        {
            spriteClips[ k ].x = j*528;
            spriteClips[ k ].y = i*358;
            spriteClips[ k ].w = 528;
            spriteClips[ k ].h = 358;
            k++;
        }
    }

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.975f;
    speedx = 1;
    speedy = 0;
    alive  = true;
    this->ID = 70;
    explode=false;
	health = 100;
}

//moves in just x-direction on the top of the screen
void Boss::Move(int playerX,int playerY)
{
    if (x-width/2<=0)
    {
        speedx = 1;
    }
    if (x+width/2>=1024)
    {
        speedx = -1;
    }
    x = x+speedx*friction;
}

void Boss::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % 4 ], 0, NULL, SDL_FLIP_NONE, gRenderer, 1 );
    SDL_Color color1={255, 0, 0, 0xFF};
    SDL_Color color2={255, 255, 0, 0xFF};
    this->RenderHPBar(x, y- height/2, -75, 5, health, color1, color2, gRenderer);
}
