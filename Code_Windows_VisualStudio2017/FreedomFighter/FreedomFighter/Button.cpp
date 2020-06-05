#include "pch.h"
#include "Button.h"

#include <string.h>


Button::Button()
{

}

Button::Button(LTexture* image1, LTexture* image2, int SCREEN_WIDTH, int SCREEN_HEIGHT, int yPosition, char* word)
{

    letters = strlen(word); // length of word

    buttonCenter = new SDL_Rect[letters];

    spriteSheetTexture1 = image1;
    spriteSheetTexture2 = image2;

    // cropping the left part of the button
    buttonLeft.x = 3;
    buttonLeft.y = 8;
    buttonLeft.w = 44;
    buttonLeft.h = 64;

    // cropping the right part of the button
    buttonRight.x = 209;
    buttonRight.y = 8;
    buttonRight.w = 44;
    buttonRight.h = 64;

    for (int i=0; i<letters; i++)
    {
        // cropping the middle part of the button according to the length of the word
        buttonCenter[i].x = 60;
        buttonCenter[i].y = 8;
        buttonCenter[i].w = 44;
        buttonCenter[i].h = 64;
    }

    this->width = buttonLeft.w;
    this->height = buttonLeft.h;
    this->SCREEN_WIDTH = SCREEN_WIDTH;
    this->SCREEN_HEIGHT = SCREEN_HEIGHT;

    // determines vertical positioning of button ( xPos is always center of screen)
    this->yPosition = yPosition;

    // string in button formed
    myWord = new Word(image1, SCREEN_WIDTH, SCREEN_HEIGHT, yPosition, word);
}


Button::~Button()
{
    //deallocating buttons
    spriteSheetTexture1 = NULL;
    spriteSheetTexture2 = NULL;
    delete myWord;
}


void Button::Render(SDL_Renderer* gRenderer)
{
    // if even number of letters
    if(letters%2 == 0)
    {
        // calculating position of first button piece
        int xPos = -(letters/2);

        // renders left button
        spriteSheetTexture2->Render( SCREEN_WIDTH/2 + ((xPos-1)*44), yPosition - height/2, &buttonLeft, 0.0, NULL, SDL_FLIP_NONE, gRenderer,1 );

        // renders all center buttons
        for (int i=0; i<letters; i++)
        {
            spriteSheetTexture2->Render( SCREEN_WIDTH/2 + (xPos*44), yPosition - height/2, &buttonCenter[i], 0.0, NULL, SDL_FLIP_NONE, gRenderer,1 );
            xPos++;
        }
        // renders right button
        spriteSheetTexture2->Render( SCREEN_WIDTH/2 + ((xPos)*44), yPosition - height/2, &buttonRight, 0.0, NULL, SDL_FLIP_NONE, gRenderer,1 );
    }

    // if odd number of letters
    else
    {
        // calculating position of first button piece
        int xPos = -(letters/2);

        // renders left button
        spriteSheetTexture2->Render( SCREEN_WIDTH/2 + ((xPos-1)*44) - 22, yPosition - height/2, &buttonLeft, 0.0, NULL, SDL_FLIP_NONE, gRenderer,1 );

        // renders all center buttons
        for (int i=0; i<letters; i++)
        {
            spriteSheetTexture2->Render( SCREEN_WIDTH/2 + (xPos*44) - 22, yPosition - height/2, &buttonCenter[i], 0.0, NULL, SDL_FLIP_NONE, gRenderer,1 );
            xPos++;
        }

        // renders right button
        spriteSheetTexture2->Render( SCREEN_WIDTH/2 + ((xPos)*44) - 22, yPosition - height/2, &buttonRight, 0.0, NULL, SDL_FLIP_NONE, gRenderer,1 );
    }

    // renders word on top of button
    myWord->Render(gRenderer);
}
