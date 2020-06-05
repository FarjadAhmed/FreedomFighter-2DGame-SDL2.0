#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include"Node.h"
#include "Unit.h"
#include "Explosion.h"
#include "LTexture.h"
#include "math.h"
#include "stdlib.h"
#include "Enemy_Bullet.h"
#include "SDL_mixer.h"
#include "Turret_Homing_Missile.h"
#include "Turret_Straight_Missile.h"
#include "Boss_Weapon.h"

class Queue
{
private:
    Node* head;
    Node* tail;
    Unit* plane;
public:
    void plane_pointer(Unit*);
    Queue();
    int check();
    ~Queue();
    void Enqueue(Unit*);
    void Clean(LTexture* image);
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Move(int playerX, int PlayerY);
    void Dodge(Unit* Player,Mix_Chunk *gSounds[], int* score);
    void Enemy_Fire(long int& frame, Unit* Player, LTexture* image);
    void Save(FILE* filepointer);
	bool Boss_Alive();
};
