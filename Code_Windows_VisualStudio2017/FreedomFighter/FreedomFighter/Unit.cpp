#include "pch.h"
#include "Unit.h"

Unit::Unit()
{

}

Unit::Unit(LTexture* image, float x, float y)
{

}


Unit::~Unit()
{
}

void Unit::SetAlive(bool alive)
{
    this->alive = alive;
}

bool Unit::GetAlive()
{
    return alive;
}
void Unit::Move()
{

}

void Unit::Move(int direction)
{

}

void Unit::Move(int playerX, int PlayerY)
{

}

void Unit::SetX(float x)
{
    this->x=x;
}
void Unit::SetY(float y)
{
    this->y=y;
}

 int Unit::GetX()
 {
     return x;
 }
int Unit::GetY()
 {
     return y;
 }

int Unit::GetID()
 {
     return ID;
 }

float Unit::GetAngle()
 {
     return angle;
 }
void Unit::SetAngle(float angle)
 {
     this->angle=angle;
 }

int Unit::Get_Health()
{
    return health;
}

void Unit::Set_Health(int health)
{
    this->health = health;
}
void Unit::Set_Straight_Missile(int s_missile)
{
    this->straight_missile = s_missile;
}
int Unit::Get_Straight_Missile()
{
    return straight_missile;
}
void Unit::Set_Homing_Missile(int h_missile)
{
    this->homing_missile = h_missile;
}
int Unit::Get_Homing_Missile()
{
    return homing_missile;
}
Unit* Unit::GetTarget()
{
	return target;
}

void Unit::SetTarget(Unit* target)
{

}
void Unit::SetAlpha(Uint8 alpha)
{
	this->alpha = alpha;
}

Uint8 Unit::GetAlpha()
{
	return alpha;
}

 float Unit::LeftCorner()
{
    return x-width/2;
}

float Unit::RightCorner()
{
    return x+width/2;
}

float Unit::Top()
{
    return y+height/2;
}

float Unit::Bottom()
{
    return y-height/2;
}

void Unit::SetExplode(bool explode)
{
    this->explode=explode;
}
bool Unit::GetExplode()
{
    return explode;
}

void Unit::Render(long int& frame, SDL_Renderer* gRenderer)
{

}

//health bar
void Unit::RenderHPBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor, SDL_Renderer* gRenderer)
{
   Percent = (Percent/100);
   Percent = Percent > 1.f ? 1.f : Percent < 0.f ? 0.f : Percent;
   SDL_Color old;
   SDL_GetRenderDrawColor(gRenderer, &old.r, &old.g, &old.g, &old.a);
   SDL_Rect bgrect = { x, y, w, h };
   SDL_SetRenderDrawColor(gRenderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
   SDL_RenderFillRect(gRenderer, &bgrect);
   SDL_SetRenderDrawColor(gRenderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
   int pw = (int)((float)w * Percent);
   int px = x + (w - pw);
   SDL_Rect fgrect = { px, y, pw, h };
   SDL_RenderFillRect(gRenderer, &fgrect);
   SDL_SetRenderDrawColor(gRenderer, old.r, old.g, old.b, old.a);
}
