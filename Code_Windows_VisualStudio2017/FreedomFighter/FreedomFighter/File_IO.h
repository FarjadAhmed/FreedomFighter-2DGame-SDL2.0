#pragma once

#include "Include.h"

class File_IO
{
    public:
        File_IO();
        ~File_IO();
        void New_game();
        static void Load(LTexture* image,Unit* Player, Queue* myQueue, char* filename, int* score);
        static void Save(Unit* Player, Queue*, char*, int score);
};
