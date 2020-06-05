#include "pch.h"
#include"Word.h"

#include <string.h>
#include <stdio.h>
#include <ctype.h>


Word::Word()
{

}

Word::Word(LTexture* image, int SCREEN_WIDTH, int SCREEN_HEIGHT, int yPosition, char* word)
{

    letters = strlen(word); // length of word

    // forms new character array based on length of string
    chars = new Character[letters];

    // if even number of words
    if(letters%2 == 0)
    {
        // get position of leftmost letter
        int xPos = -(letters/2);

        // assign each character in array a letter and a position
        for (int i=0; i<letters; i++)
        {

            chars[i].SetChar(image, SCREEN_WIDTH/2 + (xPos*44), yPosition, toupper(word[i]));
            xPos++;
        }
    }
    // if odd number of words
    else
    {
        // get position of leftmost letter
        int xPos = -(letters/2);

        // assign each character in array a letter and a position
        for (int i=0; i<letters; i++)
        {
            chars[i].SetChar(image, SCREEN_WIDTH/2 + (xPos*44) - 22, yPosition, toupper(word[i]));
            xPos++;
        }
    }

}


Word::~Word()
{
    delete[] chars;
}

void Word::Render(SDL_Renderer* gRenderer)
{
    for(int i=0; i<letters; i++)
    {
        chars[i].Render(gRenderer);
    }
}
