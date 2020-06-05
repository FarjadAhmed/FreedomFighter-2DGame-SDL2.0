#include "pch.h"
#include "Game_Splash_Screen.h"


Game_Splash_Screen::Game_Splash_Screen()
{

}

Game_Splash_Screen::~Game_Splash_Screen()
{

}

void Game_Splash_Screen::Start(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer, SDL_Window* gWindow)
{
	long delay = 250; // splash screen runs for 250 frames
	Unit* splash_screen = new Splash_Screen(&gSheetTexture[15], 0, 0, SCREEN_WIDTH);
	// Unit pointer splash_screen created by passing image, x y coordinates, screen width

	Word* loading = new Word(&gSheetTexture[5], SCREEN_WIDTH, SCREEN_HEIGHT, 675, "Loading");
    //
	int alpha = 0;
	while (delay > 0)
	{
		if (alpha < 101)
		{
			alpha++;
		}
		splash_screen->SetAlpha(alpha);
		splash_screen->Render(delay, gRenderer); // passing frames as arg, rendering the splash screen on screen
		delay = delay - 1; // reducing frames' count
		if (delay < 150)
		{
			splash_screen->Set_Health(splash_screen->Get_Health() + 1);
			// increasing loading bar (similar to health bar) per frame

			loading->Render(gRenderer); // rendering loading text on screen
		}
		SDL_RenderPresent(gRenderer);
	}
	delete splash_screen;
	delete loading;
}

void Game_Splash_Screen::End(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer, SDL_Window* gWindow)
{
	Word* line_1;
	Word* line_2;
	for (int i = SCREEN_HEIGHT; i>-100 ; i = i - 3 )
	{
        // ending credits to a fallen comrade
		line_1 = new Word(&gSheetTexture[5], SCREEN_WIDTH, SCREEN_HEIGHT, i, "Dedicated to");
		line_2 = new Word(&gSheetTexture[5], SCREEN_WIDTH, SCREEN_HEIGHT, i+50, "a fallen comrade");
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF); // fills screen with black color
		SDL_RenderClear(gRenderer); //Clear screen
		line_1->Render(gRenderer); // renders the first line on screen
		line_2->Render(gRenderer); // renders the second line on screen
		SDL_RenderPresent(gRenderer); // displays on screen
		delete line_1;
		delete line_2;
	}
}

