#include "pch.h"
#include "Game_Menu.h"

Game_Menu::Game_Menu()
{

}

Game_Menu::~Game_Menu()
{

}

char* Game_Menu::Start(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer)
{
    bool mouseClicked = false;
    SDL_Event e;                            //Event handler

    // text on buttons
    char* word_new = "New Game";
    char* word_load = "Load Game";
    char* word_quit = "Exit";

    char* com=NULL; // works as a switch, returns a value at user's click on a button

    Button* myWord_new = new Button(&gSheetTexture[5], &gSheetTexture[6], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT/2-70, word_new);
    Button* myWord_load = new Button(&gSheetTexture[5], &gSheetTexture[6], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT/2, word_load);
    Button* myWord_quit = new Button(&gSheetTexture[5], &gSheetTexture[6], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT/2+70, word_quit);

    while( com==NULL )                          //While application is running
    {
        while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
        {

        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if( e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
        {
            //Get mouse position
            int x, y;
            SDL_GetMouseState( &x, &y );


            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    if(mouseClicked == false)
                    {
                        mouseClicked = true;
                        if (x>292 && x<731 && y>SCREEN_HEIGHT/2-70-24 && y<SCREEN_HEIGHT/2-70+24)
                        {
                            com= "new"; // com != NULL, breaks the while loop
                        }
                        else if (x>270 && x<753 && y>SCREEN_HEIGHT/2-24 && y<SCREEN_HEIGHT/2+24)
                        {
                            com= "load";
                        }
                        else if (x>380 && x<643 && y>SCREEN_HEIGHT/2+70-24 && y<SCREEN_HEIGHT/2+70+24)
                        {
                            com= "quit";
                        }
                    }
                }
            }

            if(e.type == SDL_MOUSEBUTTONUP)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    mouseClicked = false;
                }
            }
        }
        //renders the buttons
        myWord_new->Render(gRenderer);
        myWord_load->Render(gRenderer);
        myWord_quit->Render(gRenderer);

        // displays the buttons
        SDL_RenderPresent( gRenderer );
    }

    delete myWord_new;
    delete myWord_quit;
    delete myWord_load;

    return com; // returns command (new/load/quit)
}

char* Game_Menu::Middle(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer)
{

    bool quit = false;                      //Main loop flag
    bool mouseClicked = false;
    SDL_Event e;                            //Event handler

    // text on buttons
    char* word_resume = "Resume Game";
    char* word_save = "Save Game";
    char* word_back = "Quit";

    char* com=NULL; // works as a switch, returns a value at user's click on a button

    Button* myWord_resume = new Button(&gSheetTexture[5], &gSheetTexture[6], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT/2-70, word_resume);
    Button* myWord_save = new Button(&gSheetTexture[5], &gSheetTexture[6], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT/2, word_save);
    Button* myWord_back = new Button(&gSheetTexture[5], &gSheetTexture[6], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT/2+70, word_back);

    while( com==NULL )                          //While application is running
    {
        while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
        {

        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if( e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
        {
            //Get mouse position
            int x, y;
            SDL_GetMouseState( &x, &y );


            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    if(mouseClicked == false)
                    {
                        mouseClicked = true;
                        if (x>292 && x<731 && y>SCREEN_HEIGHT/2-70-24 && y<SCREEN_HEIGHT/2-70+24)
                        {
                            com= "resume";
                        }
                        else if (x>270 && x<753 && y>SCREEN_HEIGHT/2-24 && y<SCREEN_HEIGHT/2+24)
                        {
                            com= "save";
                        }
                        else if (x>380 && x<643 && y>SCREEN_HEIGHT/2+70-24 && y<SCREEN_HEIGHT/2+70+24)
                        {
                            com= "back";
                        }
                    }
                }
            }

            if(e.type == SDL_MOUSEBUTTONUP)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    mouseClicked = false;
                }
            }
        }
        //renders the buttons
        myWord_resume->Render(gRenderer);
        myWord_save->Render(gRenderer);
        myWord_back->Render(gRenderer);

        // displays the buttons
        SDL_RenderPresent( gRenderer );
    }
    delete myWord_resume;
    delete myWord_back;
    delete myWord_save;

    // returns command (resume/save/back)
    return com;
}

char* Game_Menu::Save(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer, Unit* plane, Queue* myQueue, int score)
{
    bool quit = false;                      //Main loop flag
    bool mouseClicked = false;
    SDL_Event e;                            //Event handler

    long int frame=0;

    // text on buttons
    char* word_1 = "State 1";
    char* word_2 = "State 2";
    char* word_3 = "State 3";
    char* word_4 = "State 4";

    char* com=NULL; // works as a switch, returns a value at user's click on a button

    Word* myWord_save = new Word(&gSheetTexture[5], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT*0.5, "Save Game");
    Word* myWord_1 = new Word(&gSheetTexture[5], SCREEN_WIDTH*0.4, SCREEN_HEIGHT, SCREEN_HEIGHT*0.3, word_1);
    Word* myWord_2 = new Word(&gSheetTexture[5], SCREEN_WIDTH*1.6, SCREEN_HEIGHT, SCREEN_HEIGHT*0.3, word_2);
    Word* myWord_3 = new Word(&gSheetTexture[5], SCREEN_WIDTH*0.4, SCREEN_HEIGHT, SCREEN_HEIGHT*0.9, word_3);
    Word* myWord_4 = new Word(&gSheetTexture[5], SCREEN_WIDTH*1.6, SCREEN_HEIGHT, SCREEN_HEIGHT*0.9, word_4);

    int w_half,h_half,w_quat,h_quat;
    w_quat=SCREEN_WIDTH*0.3;
    h_quat=SCREEN_HEIGHT*0.3;

	gSheetTexture[7].LoadFromFile("Files/State 1.bmp", gRenderer);
	gSheetTexture[8].LoadFromFile("Files/State 2.bmp", gRenderer);
	gSheetTexture[9].LoadFromFile("Files/State 3.bmp", gRenderer);
	gSheetTexture[10].LoadFromFile("Files/State 4.bmp", gRenderer);
	Screens* state_1= new Screens(&gSheetTexture[7],SCREEN_WIDTH*0.05,SCREEN_HEIGHT*0.05);
    Screens* state_2= new Screens(&gSheetTexture[8],SCREEN_WIDTH*0.65,SCREEN_HEIGHT*0.05);
    Screens* state_3= new Screens(&gSheetTexture[9],SCREEN_WIDTH*0.05,SCREEN_HEIGHT*0.65);
    Screens* state_4= new Screens(&gSheetTexture[10],SCREEN_WIDTH*0.65,SCREEN_HEIGHT*0.65);

    while( com==NULL )                          //While application is running
    {
        while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
        {

        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if( e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
        {
            //Get mouse position
            int x, y;
            SDL_GetMouseState( &x, &y );


            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    if(mouseClicked == false)
                    {
                        mouseClicked = true;
                        if (x>SCREEN_WIDTH*0.05 && x<SCREEN_WIDTH*0.05+w_quat && y>SCREEN_HEIGHT*0.05 && y<SCREEN_HEIGHT*0.05+h_quat)
                        {
                            com= "Files/1.txt";
                            File_IO::Save(plane, myQueue, com, score);
                        }
                        else if (x>SCREEN_WIDTH*0.65 && x<SCREEN_WIDTH*0.65+w_quat && y>SCREEN_HEIGHT*0.05 && y<SCREEN_HEIGHT*0.05+h_quat)
                        {
                            com= "Files/2.txt";
                            File_IO::Save(plane, myQueue, com, score);
                        }
                        else if (x>SCREEN_WIDTH*0.05 && x<SCREEN_WIDTH*0.05+w_quat && y>SCREEN_HEIGHT*0.65 && y<SCREEN_HEIGHT*0.65+h_quat)
                        {
                            com= "Files/3.txt";
                            File_IO::Save(plane, myQueue, com, score);
                        }
                        else if (x>SCREEN_WIDTH*0.65 && x<SCREEN_WIDTH*0.65+w_quat && y>SCREEN_HEIGHT*0.65 && y<SCREEN_HEIGHT*0.65+h_quat)
                        {
                            com= "Files/4.txt";
                            File_IO::Save(plane, myQueue, com, score);
                        }
                        else
                        {
                            com="back";
                        }
                    }
                }
            }


            if(e.type == SDL_MOUSEBUTTONUP)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    mouseClicked = false;
                }
            }

        }
		SDL_RenderClear(gRenderer);
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);    //Clear screen
		state_1->Render(frame, gRenderer);
        state_2->Render(frame, gRenderer);
        state_3->Render(frame, gRenderer);
        state_4->Render(frame, gRenderer);
        myWord_save->Render(gRenderer);
        myWord_1->Render(gRenderer);
        myWord_2->Render(gRenderer);
        myWord_3->Render(gRenderer);
        myWord_4->Render(gRenderer);

        SDL_RenderPresent( gRenderer );
    }

    delete myWord_save;
    delete myWord_1;
    delete myWord_2;
    delete myWord_3;
    delete myWord_4;
    delete state_1;
    delete state_2;
    delete state_3;
    delete state_4;

    return com;
}

char* Game_Menu::Load(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], SDL_Renderer* gRenderer, SDL_Window* gWindow, Unit* plane, Queue* myQueue, int* score)
{
    bool quit = false;                      //Main loop flag
    bool mouseClicked = false;
    SDL_Event e;                            //Event handler

    long int frame=0;
    char* word_1 = "State 1";
    char* word_2 = "State 2";
    char* word_3 = "State 3";
    char* word_4 = "State 4";
    char* com=NULL;

    Word* myWord_load = new Word(&gSheetTexture[5], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT*0.5, "Load Game");
    Word* myWord_1 = new Word(&gSheetTexture[5], SCREEN_WIDTH*0.4, SCREEN_HEIGHT, SCREEN_HEIGHT*0.3, word_1);
    Word* myWord_2 = new Word(&gSheetTexture[5], SCREEN_WIDTH*1.6, SCREEN_HEIGHT, SCREEN_HEIGHT*0.3, word_2);
    Word* myWord_3 = new Word(&gSheetTexture[5], SCREEN_WIDTH*0.4, SCREEN_HEIGHT, SCREEN_HEIGHT*0.9, word_3);
    Word* myWord_4 = new Word(&gSheetTexture[5], SCREEN_WIDTH*1.6, SCREEN_HEIGHT, SCREEN_HEIGHT*0.9, word_4);

    int w_half,h_half,w_quat,h_quat;
    w_quat=SCREEN_WIDTH*0.3;
    h_quat=SCREEN_HEIGHT*0.3;

	gSheetTexture[7].LoadFromFile("Files/State 1.bmp", gRenderer);
	gSheetTexture[8].LoadFromFile("Files/State 2.bmp", gRenderer);
	gSheetTexture[9].LoadFromFile("Files/State 3.bmp", gRenderer);
	gSheetTexture[10].LoadFromFile("Files/State 4.bmp", gRenderer);
	Screens* state_1= new Screens(&gSheetTexture[7],SCREEN_WIDTH*0.05,SCREEN_HEIGHT*0.05);
    Screens* state_2= new Screens(&gSheetTexture[8],SCREEN_WIDTH*0.65,SCREEN_HEIGHT*0.05);
    Screens* state_3= new Screens(&gSheetTexture[9],SCREEN_WIDTH*0.05,SCREEN_HEIGHT*0.65);
    Screens* state_4= new Screens(&gSheetTexture[10],SCREEN_WIDTH*0.65,SCREEN_HEIGHT*0.65);

    while( com==NULL )                          //While application is running
    {
        while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
        {

        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if( e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
        {
            //Get mouse position
            int x, y;
            SDL_GetMouseState( &x, &y );


            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    if(mouseClicked == false)
                    {
                        mouseClicked = true;
                        if (x>SCREEN_WIDTH*0.05 && x<SCREEN_WIDTH*0.05+w_quat && y>SCREEN_HEIGHT*0.05 && y<SCREEN_HEIGHT*0.05+h_quat)
                        {
                            com= "Files/1.txt";
                            File_IO::Load(gSheetTexture, plane, myQueue, com, score);
                        }
                        else if (x>SCREEN_WIDTH*0.65 && x<SCREEN_WIDTH*0.65+w_quat && y>SCREEN_HEIGHT*0.05 && y<SCREEN_HEIGHT*0.05+h_quat)
                        {
                            com= "Files/2.txt";
                            File_IO::Load(gSheetTexture,plane, myQueue, com, score);
                        }
                        else if (x>SCREEN_WIDTH*0.05 && x<SCREEN_WIDTH*0.05+w_quat && y>SCREEN_HEIGHT*0.65 && y<SCREEN_HEIGHT*0.65+h_quat)
                        {
                            com= "Files/3.txt";
                            File_IO::Load(gSheetTexture,plane, myQueue, com, score);
                        }
                        else if (x>SCREEN_WIDTH*0.65 && x<SCREEN_WIDTH*0.65+w_quat && y>SCREEN_HEIGHT*0.65 && y<SCREEN_HEIGHT*0.65+h_quat)
                        {
                            com= "Files/4.txt";
                            File_IO::Load(gSheetTexture,plane, myQueue, com, score);
                        }
                        else
                        {
                            com="";
                        }
                    }
                }
            }


            if(e.type == SDL_MOUSEBUTTONUP)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    mouseClicked = false;
                }
            }

        }
		SDL_RenderClear(gRenderer);
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);    //Clear screen
		state_1->Render(frame, gRenderer);
        state_2->Render(frame, gRenderer);
        state_3->Render(frame, gRenderer);
        state_4->Render(frame, gRenderer);
        myWord_load->Render(gRenderer);
        myWord_1->Render(gRenderer);
        myWord_2->Render(gRenderer);
        myWord_3->Render(gRenderer);
        myWord_4->Render(gRenderer);


        //SDL_RenderPresent( gRenderer );
        SDL_RenderPresent( gRenderer );

    }

    delete myWord_load;
    delete myWord_1;
    delete myWord_2;
    delete myWord_3;
    delete myWord_4;
    delete state_1;
    delete state_2;
    delete state_3;
    delete state_4;
    return com;
}
