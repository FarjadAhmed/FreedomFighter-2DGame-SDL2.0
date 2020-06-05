#include "pch.h"
#include"Splash_Screen.h"

Splash_Screen::Splash_Screen()
{

}

Splash_Screen::~Splash_Screen()
{
    spriteSheetTexture = NULL;
    cout<<"Splash_Screen Deallocated"<<endl;
}

Splash_Screen::Splash_Screen(LTexture* image, float x, float y, int SCREEN_WIDTH):Unit(image, x, y)
{
	this->SCREEN_WIDTH = SCREEN_WIDTH;
    spriteSheetTexture = image;

    // setting frame's x, y coordinates and width, height
    spriteClips[ 0 ].x = 0;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w =1024;
    spriteClips[ 0 ].h = 768;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

	this->alpha = 0;

    this->ID = 0; // ID of splash screen is 0

    // scaling image by screen width
	scale = (float)SCREEN_WIDTH / (float)spriteClips[0].w;

}


void Splash_Screen::Render(long int& frame, SDL_Renderer* gRenderer)
{
	spriteSheetTexture->SetAlpha(this->alpha);
	SDL_Color color1 = { 0, 255, 0, 0xFF }; // green color for loading animation
	SDL_Color color2 = { 255, 255, 255, 0xFF }; // white color on base for loading animation
	spriteSheetTexture->Render( x, y, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer, scale);
	if (frame < 150)
	{
		this->RenderHPBar((SCREEN_WIDTH/2)+250, 650, -500, 40, health, color1, color2, gRenderer);
	}
}
