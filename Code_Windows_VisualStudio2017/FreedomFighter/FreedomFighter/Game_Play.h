#pragma once

#include "Include.h"

class Game_Play
{
    private:

    public:
        Game_Play();
        ~Game_Play();
        static void Run(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], Mix_Chunk *gSounds[], SDL_Renderer* gRenderer, SDL_Window* gWindow);
};
