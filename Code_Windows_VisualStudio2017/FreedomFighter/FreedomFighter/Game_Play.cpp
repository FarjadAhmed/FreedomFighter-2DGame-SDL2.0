#include "pch.h"
#include "Game_Play.h"

Game_Play::Game_Play()
{

}

Game_Play::~Game_Play()
{

}

void Game_Play::Run(int SCREEN_WIDTH, int SCREEN_HEIGHT, LTexture gSheetTexture[], Mix_Chunk *gSounds[], SDL_Renderer* gRenderer, SDL_Window* gWindow)
{
            int boss = 0;
			int score=0;
			char buff[32];
			float background_scale = 1256*((float)SCREEN_WIDTH / 2048);
			cout << background_scale << endl;
			Word* Score_Display = new Word(&gSheetTexture[5], (SCREEN_WIDTH*1.75), SCREEN_HEIGHT, 70, _itoa(score,buff,10));
			Word* Score = new Word(&gSheetTexture[5], (SCREEN_WIDTH*1.75)-350, SCREEN_HEIGHT, 70, "Score");
			Word* Health_Display = new Word(&gSheetTexture[5], (SCREEN_WIDTH/1.75), SCREEN_HEIGHT, 70, "100");
			Word* Straight_Missile_Display = new Word(&gSheetTexture[5], (SCREEN_WIDTH / 1.75), SCREEN_HEIGHT, 150, "3");
			Word* Homing_Missile_Display = new Word(&gSheetTexture[5], (SCREEN_WIDTH / 1.75), SCREEN_HEIGHT, 250, "3");
			Unit* Straight_Missile_Icon = new Player_Straight_Missile(&gSheetTexture[12], (SCREEN_WIDTH*0.8), 144);
			Unit* Homing_Missile_Icon = new Player_Homing_Missile(&gSheetTexture[12], (SCREEN_WIDTH*0.8), 214);
			int Homing_Missile_Angle = 0;
			string com;
			string com1="start";
			bool quit = false;          //Main loop flag
			long int frame = 0;
			Queue* myQueue= new Queue;

			Unit* background_1 = new Background(&gSheetTexture[2], 0, background_scale, SCREEN_WIDTH);
			Unit* background_2 = new Background(&gSheetTexture[2], 0, 0, SCREEN_WIDTH);
			Unit* background_3 = new Background(&gSheetTexture[2], 0, -(background_scale), SCREEN_WIDTH);
			background_1->Render(frame, gRenderer);
			background_2->Render(frame, gRenderer);
			background_3->Render(frame, gRenderer);

		    Unit* plane= new Player(&gSheetTexture[16], (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
		    plane->Set_Homing_Missile(3);
		    plane->Set_Straight_Missile(3);
		    Unit* unit = NULL;





			SDL_Event e;                            //Event handler

			                     //Current animation frame

			/* initialize random seed: */
            srand (time(NULL));

            /* generate secret number between 1 and 10: */
            int random = 0;




			while( !quit )                          //While application is running
			{
			    //loadMedia();
			    if (com1=="start")
                {
					com=Game_Menu::Start(SCREEN_WIDTH,SCREEN_HEIGHT,gSheetTexture,gRenderer);
                    if (com == "new")
                    {
                        delete myQueue;
                        delete plane;
                        delete background_1;
                        delete background_2;
						delete background_3;
						score = 0;
                        myQueue = new Queue;
                        plane= new Player(&gSheetTexture[16], (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
						background_1 = new Background(&gSheetTexture[2], 0, background_scale, SCREEN_WIDTH);
						background_2 = new Background(&gSheetTexture[2], 0, 0, SCREEN_WIDTH);
						background_3 = new Background(&gSheetTexture[2], 0, -(background_scale), SCREEN_WIDTH);
                        frame=0;
                        com="";
                    }
                    else if (com =="load")
                    {
                        delete myQueue;
                        delete plane;
                        delete background_1;
                        delete background_2;
						delete background_3;
						score = 0;
                        myQueue = new Queue;
                        plane= new Player(&gSheetTexture[16], (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
						background_1 = new Background(&gSheetTexture[2], 0, background_scale, SCREEN_WIDTH);
						background_2 = new Background(&gSheetTexture[2], 0, 0, SCREEN_WIDTH);
						background_3 = new Background(&gSheetTexture[2], 0, -(background_scale), SCREEN_WIDTH);
                        frame=0;
                        background_1->Render(frame, gRenderer);
                        background_2->Render(frame, gRenderer);
						background_3->Render(frame, gRenderer);
                        string load= Game_Menu::Load(SCREEN_WIDTH,SCREEN_HEIGHT,gSheetTexture,gRenderer, gWindow, plane, myQueue, &score);
                        com="";
                    }
                    else if (com =="quit")
                    {
                        quit = true;
                        com="";
                    }
                    com1="middle";
                }
				Mix_ResumeMusic();

				myQueue->Dodge(plane, gSounds, &score); // Collision function.
                if( score % 100 < 49 && boss == 0)
                {
    			    if(frame%120 == 119)
                    {
                        random = rand() % SCREEN_WIDTH;
                        unit= new Enemy_Easy(&gSheetTexture[16], random, -100);
                        myQueue->Enqueue(unit);
                        unit=NULL;
                    }
                    if (frame % 1200 == 119)
                    {
                        random = rand() % 2;
                        if (random == 0)
                        {
                            unit = new Turret(&gSheetTexture[3], SCREEN_WIDTH / 2 + 38, -100);
                            myQueue->Enqueue(unit);
                            unit = NULL;
                        }

                        else
                        {
                            unit = new Turret(&gSheetTexture[3], SCREEN_WIDTH / 2 - 63, -100);
                            myQueue->Enqueue(unit);
                            unit = NULL;
                        }

                    }
                    if (frame % 1200 == 119)
                    {
                        random = rand() % 2;
                        if (random == 0)
                        {
                            unit = new Turret_Hard(&gSheetTexture[3], 105, -100);
                            myQueue->Enqueue(unit);
                            unit = NULL;
                        }
                        else
                        {
                            unit = new Turret_Hard(&gSheetTexture[3], SCREEN_WIDTH - 115, -100);
                            myQueue->Enqueue(unit);
                            unit = NULL;
                        }
                    }
                    if(frame%450 == 0)
                    {
                        random = rand() % SCREEN_WIDTH;
                        unit= new Health_Up(&gSheetTexture[11], random, -100);
                        myQueue->Enqueue(unit);
                        unit=NULL;

                    }
                    if(frame%390 == 0)
                    {
                        random = rand() % SCREEN_WIDTH;
                        unit= new Power_Up_Straight_Missile(&gSheetTexture[12], random, -100);
                        myQueue->Enqueue(unit);
                        unit=NULL;

                    }
                    if(frame%630 == 0)
                    {
                        random = rand() % SCREEN_WIDTH;
                        unit= new Power_Up_Homing_Missile(&gSheetTexture[12], random, -100);
                        myQueue->Enqueue(unit);
                        unit=NULL;

                    }
                    if(frame%600 == 599)
                    {
                        random = rand() % SCREEN_WIDTH;
                        unit= new Enemy_Medium(&gSheetTexture[16], random, -100);
                        myQueue->Enqueue(unit);
                        unit=NULL;
                    }
                    if(frame%600 == 100)
                    {
                        random = rand() % SCREEN_WIDTH;
                        unit= new Enemy_Hard(&gSheetTexture[16], random, -100);
                        myQueue->Enqueue(unit);
                        unit=NULL;
                    }
                }
                else
				{
				    if(boss == 0)
                    {
                        unit = new Boss(&gSheetTexture[13], -400, 200);
                        myQueue->Enqueue(unit);
                        unit = NULL;
                        boss = 1;
                    }
					else
					{
						//Boss dies
						if (myQueue->Boss_Alive() == false)
						{
							cout << "2" << endl;
							boss = 0;
							Word* line_1 = new Word(&gSheetTexture[5], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT / 2, "You Won");;
							for (int i = SCREEN_HEIGHT; i>-100; i = i - 3)
							{
								SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);    //Clear screen
								SDL_RenderClear(gRenderer);
								background_1->Render(frame, gRenderer);
								background_2->Render(frame, gRenderer);
								background_3->Render(frame, gRenderer);
								myQueue->Move(plane->GetX(), plane->GetY());
								myQueue->Render(frame, gRenderer);
								myQueue->Clean(&gSheetTexture[1]);
								plane->Render(frame, gRenderer);
								line_1->Render(gRenderer);
								SDL_RenderPresent(gRenderer);
							}
							delete line_1;
							quit = true;
						}
					}

				}

				while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
				{

				}
				const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
				//Player Movement
                if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
                {
					if (plane->GetX() + (55*2) < 1024)
					{
						plane->Move(RIGHT);
					}
                }

                if(currentKeyStates[ SDL_SCANCODE_LEFT ])
                {
					if (plane->GetX() - (55*2) > 0)
					{
						plane->Move(LEFT);
					}
                }

                if(currentKeyStates[ SDL_SCANCODE_UP ])
                {
					if (plane->GetY() - (47*2) > 0)
					{
						plane->Move(UP);
					}
                }

                if(currentKeyStates[ SDL_SCANCODE_DOWN ])
                {
					if (plane->GetY() + (47*2) < 768)
					{
						plane->Move(DOWN);
					}
                }
                if(currentKeyStates[ SDL_SCANCODE_SPACE ])
                {
                    if(frame%10==0)
                    {

                        unit= new Player_Bullet(&gSheetTexture[0], plane->GetX(), plane->Bottom());
                        myQueue->Enqueue(unit);
                        unit=NULL;
                        Mix_PlayChannel( -1, gSounds[0], 0 );
                    }
                }
                if(currentKeyStates[ SDL_SCANCODE_LSHIFT ])
                {
                    if(frame%45==0)
                    {
                        if(plane->Get_Homing_Missile() > 0)
                        {
                            unit= new Player_Homing_Missile(&gSheetTexture[12], plane->GetX(), plane->Bottom());
                            myQueue->Enqueue(unit);
                            plane->Set_Homing_Missile(plane->Get_Homing_Missile()-1);
                            cout<<"Homing missiles left : "<<plane->Get_Homing_Missile()<<endl;
                            unit=NULL;
                            Mix_PlayChannel( -1, gSounds[0], 0 );
                        }
                    }
                }
                if(currentKeyStates[ SDL_SCANCODE_LCTRL ])
                {
                    if(frame%45==0)
                    {
                        if(plane->Get_Straight_Missile() > 0)
                        {
                            unit= new Player_Straight_Missile(&gSheetTexture[12], plane->GetX(), plane->Bottom());
                            myQueue->Enqueue(unit);
                            plane->Set_Straight_Missile(plane->Get_Straight_Missile()-1);
                            cout<<"Straight missiles left : "<<plane->Get_Straight_Missile()<<endl;
                            unit=NULL;
                            Mix_PlayChannel( -1, gSounds[0], 0 );
                        }

                    }
                }
                if(currentKeyStates[ SDL_SCANCODE_ESCAPE ])
                {
                    com=Game_Menu::Middle(SCREEN_WIDTH,SCREEN_HEIGHT,gSheetTexture,gRenderer);

                    if (com == "back")
                    {
                        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);    //Clear screen
                        SDL_RenderClear( gRenderer );
                        com1="start";
                    }
                }

				//Rendering
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);    //Clear screen
				SDL_RenderClear( gRenderer );


                background_1->Render(frame, gRenderer);
                background_2->Render(frame, gRenderer);
				background_3->Render(frame, gRenderer);
                myQueue->Render(frame, gRenderer);
                plane->Render(frame, gRenderer);
				Score_Display->Render(gRenderer);
				Score->Render(gRenderer);
				Health_Display->Render(gRenderer);
				Straight_Missile_Display->Render(gRenderer);
				Straight_Missile_Icon->Render(frame, gRenderer);
				Homing_Missile_Display->Render(gRenderer);
				Homing_Missile_Icon->SetAngle(Homing_Missile_Angle-=6);
				Homing_Missile_Icon->Render(frame, gRenderer);



				SDL_RenderPresent( gRenderer );     //Update screen

				if (com == "save")
                {
					string save= Game_Menu::Save(SCREEN_WIDTH,SCREEN_HEIGHT,gSheetTexture,gRenderer,plane, myQueue, score);
                    char* name=NULL;
					//rendering screen again before taking screenshot
                    SDL_RenderClear( gRenderer );
					SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);    //Clear screen
                    background_1->Render(frame, gRenderer);
                    background_2->Render(frame, gRenderer);
					background_3->Render(frame, gRenderer);
                    myQueue->Render(frame, gRenderer);
                    plane->Render(frame, gRenderer);
					Score_Display->Render(gRenderer);
					Score->Render(gRenderer);
					Health_Display->Render(gRenderer);
					Straight_Missile_Display->Render(gRenderer);
					Straight_Missile_Icon->Render(frame, gRenderer);
					Homing_Missile_Display->Render(gRenderer);
					Homing_Missile_Icon->Render(frame, gRenderer);
                    SDL_RenderPresent( gRenderer );

                    if (save== "Files/1.txt")
                    {
                        name="Files/State 1.bmp";
                    }
                    else if (save== "Files/2.txt")
                    {
                        name="Files/State 2.bmp";
                    }
                    else if (save== "Files/3.txt")
                    {
                        name="Files/State 3.bmp";
                    }
                    else if (save== "Files/4.txt")
                    {
                        name="Files/State 4.bmp";
                    }
                    else if (save== "Files/5.txt")
                    {
                        name="Files/State 5.bmp";
                    }
					//Screenshot
                    SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
                    SDL_RenderReadPixels(gRenderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
                    SDL_SaveBMP(sshot, name);
                    SDL_FreeSurface(sshot);
                    com="";
                    save="";
                    name=NULL;
                }

                myQueue->plane_pointer(plane);
                myQueue->Move(plane->GetX(),plane->GetY());
                myQueue->Enemy_Fire(frame, plane, gSheetTexture);
                myQueue->Clean(&gSheetTexture[1]);
                plane->Move();
                background_1->Move(0,0);
                background_2->Move(0,0);
				background_3->Move(0, 0);

				//Updating Score, Health and Power Ups
				delete Score_Display;
				Score_Display= new Word(&gSheetTexture[5], (SCREEN_WIDTH*1.75), SCREEN_HEIGHT, 70, _itoa(score, buff, 10));
				delete Health_Display;
				Health_Display = new Word(&gSheetTexture[5], (SCREEN_WIDTH/1.75), SCREEN_HEIGHT, 70, _itoa(plane->Get_Health(), buff, 10));
				delete Straight_Missile_Display;
				Straight_Missile_Display = new Word(&gSheetTexture[5], (SCREEN_WIDTH*1.75), SCREEN_HEIGHT, 140, _itoa(plane->Get_Straight_Missile(), buff, 10));
				delete Homing_Missile_Display;
				Homing_Missile_Display = new Word(&gSheetTexture[5], (SCREEN_WIDTH*1.75), SCREEN_HEIGHT, 210, _itoa(plane->Get_Homing_Missile(), buff, 10));
				
				if (plane->Get_Health() <= 0) //player dies
				{
					Word* line_1 = new Word(&gSheetTexture[5], SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_HEIGHT/2, "Defeated");;
					unit = new Explosion(&gSheetTexture[1], plane->GetX(), plane->GetY());
					myQueue->Enqueue(unit);
					unit = NULL;
					for (int i = SCREEN_HEIGHT; i>-100; i = i - 3)
					{
						SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);    //Clear screen
						SDL_RenderClear(gRenderer);
						background_1->Render(frame, gRenderer);
						background_2->Render(frame, gRenderer);
						background_3->Render(frame, gRenderer);
						myQueue->Render(frame, gRenderer);
						myQueue->Clean(&gSheetTexture[1]);
						line_1->Render(gRenderer);
						SDL_RenderPresent(gRenderer);
					}
					delete line_1;
					quit = true;
				}
				++frame;                            //Go to next frame

			}


			delete plane;
			delete unit;
			delete myQueue;
			delete background_1;
			delete background_2;
			delete background_3;
			delete Score;
			delete Score_Display;
			delete Health_Display;
			delete Straight_Missile_Display;
			delete Straight_Missile_Icon;
			delete Homing_Missile_Display;
			delete Homing_Missile_Icon;
		}
