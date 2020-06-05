#pragma once
#include "Include.h"
#include "Button.h"
#include "Character.h"



class Game_Menu
{
    private:

    public:
        Game_Menu();
        ~Game_Menu();
        static char* Start(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer);
        static char* Middle(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer);
        static char* Save(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer, Unit* plane, Queue*, int score);
        static char* Load(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer, SDL_Window* gWindow, Unit* plane, Queue*, int* score);

};

