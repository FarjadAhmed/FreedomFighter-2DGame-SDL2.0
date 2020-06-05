#pragma once

#include "Include.h"

class Game_Splash_Screen
{
public:
	Game_Splash_Screen();
	~Game_Splash_Screen();
	static void Start(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer, SDL_Window* gWindow);
	static void End(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer, SDL_Window* gWindow);

};
