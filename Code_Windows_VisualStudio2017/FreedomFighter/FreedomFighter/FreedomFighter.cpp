// FreedomFighter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Include.h"

//Pre defined screen width and height
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gSheetTexture[17];

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gSounds[4] = { NULL,NULL,NULL,NULL };
/*for (int i=0; i>3; i++)
{
	gSounds[i]=NULL;
}*/


bool init();
bool loadMedia();
void close();
SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		gSheetTexture[5].LoadFromFile("Images/fontSprite.png", gRenderer);
		gSheetTexture[15].LoadFromFile("Images/splash.png", gRenderer);
		Game_Splash_Screen::Start(SCREEN_WIDTH, SCREEN_HEIGHT, gSheetTexture, gRenderer, gWindow);
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Mix_PlayMusic(gMusic, -1); //background music, runs contineously
			Mix_PauseMusic();
			Game_Play::Run(SCREEN_WIDTH, SCREEN_HEIGHT, gSheetTexture, gSounds, gRenderer, gWindow);
			Game_Splash_Screen::End(SCREEN_WIDTH, SCREEN_HEIGHT, gSheetTexture, gRenderer, gWindow);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError());
					success = false;
				}
				//Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!gSheetTexture[0].LoadFromFile("Images/1948.png", gRenderer))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	if (!gSheetTexture[1].LoadFromFile("Images/explosion.png", gRenderer))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	if (!gSheetTexture[2].LoadFromFile("Images/background.png", gRenderer))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	if (!gSheetTexture[3].LoadFromFile("Images/tank.png", gRenderer))
	{
		printf("Failed to load sprite sheet Turret!\n");
		success = false;
	}
	if (!gSheetTexture[4].LoadFromFile("Images/missile.png", gRenderer))
	{
		printf("Failed to load sprite sheet Missile!\n");
		success = false;
	}
	if (!gSheetTexture[5].LoadFromFile("Images/fontSprite.png", gRenderer))
	{
		printf("Failed to load font sheet texture!\n");
		success = false;
	}
	if (!gSheetTexture[6].LoadFromFile("Images/button.png", gRenderer))
	{
		printf("Failed to load button sheet!\n");
		success = false;
	}
	if (!gSheetTexture[7].LoadFromFile("Files/State 1.bmp", gRenderer))
	{
		printf("Failed to load button sheet!\n");
		success = false;
	}
	if (!gSheetTexture[8].LoadFromFile("Files/State 2.bmp", gRenderer))
	{
		printf("Failed to load button sheet!\n");
		success = false;
	}
	if (!gSheetTexture[9].LoadFromFile("Files/State 3.bmp", gRenderer))
	{
		printf("Failed to load button sheet!\n");
		success = false;
	}
	if (!gSheetTexture[10].LoadFromFile("Files/State 4.bmp", gRenderer))
	{
		printf("Failed to load button sheet!\n");
		success = false;
	}
	if (!gSheetTexture[11].LoadFromFile("Images/Power_Ups.png", gRenderer))
	{
		printf("Failed to load button sheet!\n");
		success = false;
	}
	if (!gSheetTexture[12].LoadFromFile("Images/user_missile.png", gRenderer))
	{
		printf("Failed to load my_missile sprite sheet Missile!\n");
		success = false;
	}
	if (!gSheetTexture[13].LoadFromFile("Images/boss.png", gRenderer))
	{
		printf("Failed to load my_missile sprite sheet Boss!\n");
		success = false;
	}
	if (!gSheetTexture[14].LoadFromFile("Images/plasma.png", gRenderer))
	{
		printf("Failed to load my_missile sprite sheet Missile!\n");
		success = false;
	}
	if (!gSheetTexture[15].LoadFromFile("Images/splash.png", gRenderer))
	{
		printf("Failed to load my_missile sprite sheet Splash Screen!\n");
		success = false;
	}
	if (!gSheetTexture[16].LoadFromFile("Images/planes.png", gRenderer))
	{
		printf("Failed to load my_missile sprite sheet Splash Screen!\n");
		success = false;
	}

	//Load sound effects
	gSounds[0] = Mix_LoadWAV("Sounds/high.wav");
	//C:\Users\Muzammil\Documents\Habib\Fall 2016\OOP\Project\Game\Sounds
	if (gSounds[0] == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	gSounds[1] = Mix_LoadWAV("Sounds/Explosion.wav");
	if (gSounds[1] == NULL)
	{
		printf("Failed to load explosion sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gSounds[2] = Mix_LoadWAV("Sounds/scratch.wav");
	if (gSounds[2] == NULL)
	{
		printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gMusic = Mix_LoadMUS("Sounds/music.mp3");
	if (gMusic == NULL)
	{
		printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	for (int i = 0; i > 17; i++)
	{
		gSheetTexture[i].Free();
	}

	//Free the sound effects
	for (int i = 0; i > 4; i++)
	{
		Mix_FreeChunk(gSounds[i]);
		gSounds[i] = NULL;
	}

	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Color col = { r,g,b,a };
	return col;
}

