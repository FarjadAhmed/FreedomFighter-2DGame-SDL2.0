#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include <math.h>
#include <cmath>

const float PI = 3.14159265;

using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class Unit
{
    protected:
        bool alive;
        float x;
        float y;
        float speedx;
        float speedy;
        int width;
        int height;
        float friction; //lower speed means more friction
        float angle;
        int ID;
        bool explode;
        int health;
        int straight_missile;
        int homing_missile;
        Unit* target;
		Uint8 alpha;


        enum ANIMATION_FRAMES {FLYING_FRAMES = 3};
        SDL_Rect spriteClips[ 49 ];
        LTexture* spriteSheetTexture;

    public:


        virtual Unit* GetTarget();
        virtual void SetTarget(Unit*);
        void Set_Straight_Missile(int);
        int Get_Straight_Missile();
        void Set_Homing_Missile(int);
        int Get_Homing_Missile();
        int Get_Health();
        void Set_Health(int health);

        static float static_angle;
        Unit(LTexture* image, float x, float y);
        Unit();
        virtual ~Unit();
        void SetAlive(bool);
        bool GetAlive();
        virtual void Move();
        virtual void Move(int direction);
        virtual void Move(int playerX, int PlayerY);
        virtual void Render(long int& frame, SDL_Renderer* gRenderer);
        void SetX(float);
        void SetY(float);
        int GetX();
        int GetY();
        int GetID();
        void SetAngle(float angle);
        float GetAngle();
		void SetAlpha(Uint8 alpha);
		Uint8 GetAlpha();
        float LeftCorner();
        float RightCorner();
        float Top();
        float Bottom();
        void SetExplode(bool explode);
        bool GetExplode();
        void RenderHPBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor, SDL_Renderer* gRenderer);
};

//SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
//{
//   SDL_Color col = {r,g,b,a};
//   return col;
//}

