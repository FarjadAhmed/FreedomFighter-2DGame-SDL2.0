
#pragma once
#include"Unit.h"

class Player_Straight_Missile:public Unit
{
private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
public:
    Player_Straight_Missile(LTexture* image, float x, float y); //taking in the position of player and Ltexture pointer
    Player_Straight_Missile();
    ~Player_Straight_Missile();
    void Move(int playerX,int playerY);
    void Render(long int& frame, SDL_Renderer* gRenderer);
};
