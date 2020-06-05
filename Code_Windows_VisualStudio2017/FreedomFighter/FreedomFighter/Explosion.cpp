#include "pch.h"
#include "Explosion.h"

using namespace std;
Explosion::Explosion()
{

}

Explosion::Explosion(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteSheetTexture = image;
    int i = 0;
    int j = 0;
    int k = 0;
//49 clips, in 7*7 grid
for (i = 0; i<7; i++)
{
    for (j = 0; j<7; j++ )
    {
        spriteClips[ k ].x = j*128;
        spriteClips[ k ].y = i*128;
        spriteClips[ k ].w = 128;
        spriteClips[ k ].h = 128;
        k++;
    }
}


    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    explode=false;
    alive=true;
}


Explosion::~Explosion()
{
    spriteSheetTexture = NULL;
    cout<<"Explosion Deallocated"<<endl;
}

void Explosion::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[check], 0.0, NULL, SDL_FLIP_NONE, gRenderer,1 );
    check++;
    if (check == 48)
    {
        alive = false;
    }
}
