#include "pch.h"
#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::Enqueue(Unit* unit)
{
    if(head == NULL)
    {
        head = new Node;
        head->unit = unit;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->unit = unit;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void Queue::Clean(LTexture* image)
{
    Node* temp = head;
    Unit* explosion=NULL;

    while(temp!=NULL)
    {
        if (temp->unit->GetAlive() == false)
        {
            if (temp->unit->GetExplode() == true)
            {
                explosion= new Explosion(image, temp->unit->GetX(),temp->unit->GetY());
                this->Enqueue(explosion);
                explosion=NULL;
            }
            if(temp == head)
            {
                head = temp->next;
                if (temp->next == NULL)
                {
                    delete temp;
                    temp = NULL;
                    tail = NULL;
                }
                else
                {
                    temp->next->prev = NULL;
                    delete temp;
                    temp = head;
                }
            }
            else if (temp == tail)
            {
                temp->prev->next = NULL;
                tail = temp->prev;
                delete temp;
                temp = NULL;
            }
            else
            {
                Node* newTemp = temp;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp = temp->next;
                delete newTemp;

            }

        }
        else
        {
            temp=temp->next;

        }
    }

}

void Queue::Render(long int& frame, SDL_Renderer* gRenderer)
{
    Node* temp = head;
    while(temp != NULL)
    {
        temp->unit->Render(frame, gRenderer);
        temp = temp->next;
    }
}

void Queue::Move(int playerX, int PlayerY)
{
    Node* temp = head;
    while(temp != NULL)
    {
        temp->unit->Move(playerX,PlayerY);
        temp = temp->next;
    }
    Node* tmp1 = head;
    Node* tmp2 = head;
    while(tmp1 != NULL)
    {

        if (tmp1->unit->GetID() == 49 ) //homing missile
        {
            if(tmp1->unit->GetTarget() == NULL)
            {
                while(tmp2 != NULL)
                {
                    int id = tmp2->unit->GetID();
                    if (id == 21 || id == 22 || id == 23 || id == 31 || id == 32 || id == 33 || id == 42 || id == 61 || id == 70)
                    {
                        
                        if(tmp2->unit->GetY() < plane->GetY()) //homing missile fire only if there is any enemy infront of the plane
                            {
                                tmp1->unit->SetTarget(tmp2->unit); //setting target for homing missile
                                break;
                            }
                        }
                    tmp2 = tmp2->next;
                }
            }
        }
        tmp1 = tmp1->next;
    }
}

void Queue::Dodge(Unit* Player,Mix_Chunk *gSounds[], int* score)
{
    float x = NULL;
    float y = NULL;

    Node* temp1 = head;
    Node* temp2 = NULL;
    Node* temp3 = head;
    Node* temp4 = head;

    while(temp3!=NULL)
    {
        if(temp3->unit->GetID()==49 || temp3->unit->GetID()==48)//homing and straight missile
        {
            while(temp4!=NULL)
            {
                int id = temp4->unit->GetID();
                if (id == 21 || id == 22 || id == 23 || id == 31 || id == 33 || id == 70)
                {
                    if ( (temp3->unit->GetX())>=(temp4->unit->LeftCorner()) && (temp4->unit->RightCorner())>=(temp3->unit->GetX()) && (temp4->unit->Bottom())<=(temp3->unit->Top()) && (temp4->unit->Top())>=(temp3->unit->Bottom()) )
                    {//if missiles hit enemy
                        temp3->unit->SetAlive(false);
                        if (temp4->unit->GetID()== 21)
                        {
                            temp4->unit->Set_Health((temp4->unit->Get_Health())-100);
                        }
                        else if (temp4->unit->GetID()== 22)
                        {
                            temp4->unit->Set_Health((temp4->unit->Get_Health())-100);
                        }
                        else if (temp4->unit->GetID()== 23)
                        {
                            temp4->unit->Set_Health((temp4->unit->Get_Health())-50);
                        }
                        else if (temp4->unit->GetID()== 31)
                        {
                            temp4->unit->Set_Health((temp4->unit->Get_Health())-20);
                        }
                        else if (temp4->unit->GetID()== 33)
                        {
                            temp4->unit->Set_Health((temp4->unit->Get_Health())-20);
                        }
                        else if (temp4->unit->GetID()== 70)
                        {
                            temp4->unit->Set_Health((temp4->unit->Get_Health())-20);
                        }
                        if (temp4->unit->Get_Health()<= 0)
                        {
                            temp4->unit->SetAlive(false);
							temp4->unit->SetExplode(true);
                        }
                        
						*score = *score + 5;
                        x = NULL;
                        y = NULL;
                    }
                }
                temp4 = temp4->next;
            }
        }
            temp3 = temp3->next;
    }

    while(temp1 != NULL)
    {
        int id = temp1->unit->GetID();//if plane colloids with any object
        if (id == 21 || id == 22 || id == 23 || id == 31 || id == 32 || id == 33 || id == 42 || id == 43 || id == 44 || id == 61 || id == 50 || id == 51 || id == 52 || id == 70 || id == 71)
        {	//checking collision
            if ( (temp1->unit->GetX())>=(Player->LeftCorner()) && (Player->RightCorner())>=(temp1->unit->GetX()) && (Player->Bottom())<=(temp1->unit->Top()) && (Player->Top())>=(temp1->unit->Bottom()) )
            {
                if ( id == 42)
                {
                    Player->Set_Health(Player->Get_Health()-2);
                    cout<<"Health is : "<<Player->Get_Health()<<endl;
                    temp1->unit->SetAlive(false);
                    temp1->unit->SetExplode(true);
                }
				if (id == 43)
				{
					Player->Set_Health(Player->Get_Health() - 4);
					cout << "Health is : " << Player->Get_Health() << endl;
					temp1->unit->SetAlive(false);
					temp1->unit->SetExplode(true);
				}
				if (id == 44)
				{
					Player->Set_Health(Player->Get_Health() - 4);
					cout << "Health is : " << Player->Get_Health() << endl;
					temp1->unit->SetAlive(false);
					temp1->unit->SetExplode(true);
				}
				if (id == 70)
				{
					Player->Set_Health(Player->Get_Health() - 10); //when colloid with boss
					cout << "Health is : " << Player->Get_Health() << endl;
				}
				if (id == 71)
				{
					Player->Set_Health(Player->Get_Health() - 10);//boss weapon strike
					cout << "Health is : " << Player->Get_Health() << endl;
					temp1->unit->SetAlive(false);
					temp1->unit->SetExplode(true);
				}
                   if(id == 51)//addding straight missiles
                {
                    Player->Set_Straight_Missile(Player->Get_Straight_Missile()+3);
                    cout<<Player->Get_Straight_Missile()<<endl;
                    temp1->unit->SetAlive(false);
					Mix_PlayChannel(-1, gSounds[2], 0);
                } 
                 else   if(id == 50) //adding homing missiles
                {
                    Player->Set_Homing_Missile(Player->Get_Homing_Missile()+3);
                    cout<<Player->Get_Homing_Missile()<<endl;
                    temp1->unit->SetAlive(false);
					Mix_PlayChannel(-1, gSounds[2], 0);
                }
                  else  if(id == 52)//adding health
                {
                    if(Player->Get_Health() < 97)
                    {
                        Player->Set_Health(Player->Get_Health()+4);
                    }
                    cout<<Player->Get_Health()<<endl;
                    temp1->unit->SetAlive(false);
					Mix_PlayChannel(-1, gSounds[2], 0);

                }
                else if ( id ==21 || id ==22 || id ==23 )//if plane strikes enemy planes
                {
                    temp1->unit->SetAlive(false);
                    temp1->unit->SetExplode(true);
                    Player->Set_Health(Player->Get_Health()-3);
                    Mix_PlayChannel( -1, gSounds[1], 0 );
                }

            }
            temp2 = head;
            while(temp2 != NULL)
            {
                int id = temp2->unit->GetID();
                if (id == 41)//player bullet
                {
                    if ( (temp2->unit->GetX())>=(temp1->unit->LeftCorner()) && (temp2->unit->GetX())<=(temp1->unit->RightCorner()) && (temp2->unit->GetY())<=(temp1->unit->Top()) && (temp2->unit->GetY())>=(temp1->unit->Bottom()) )
                    {
                        id = temp1->unit->GetID();
                        if( id == 21 || id == 22 || id == 23 || id == 31 || id == 33 || id == 43 || id == 44 || id == 70)//detecting enemies
                        {
                            temp2->unit->SetAlive(false);
                            if (temp1->unit->GetID()== 21)
                            {
                                temp1->unit->Set_Health((temp1->unit->Get_Health())-50);
                            }
                            else if (temp1->unit->GetID()== 22)
                            {
                                temp1->unit->Set_Health((temp1->unit->Get_Health())-25);
                            }
                            else if (temp1->unit->GetID()== 23)
                            {
                                temp1->unit->Set_Health((temp1->unit->Get_Health())-13);
                            }
                            else if (temp1->unit->GetID()== 31)
                            {
                                temp1->unit->Set_Health((temp1->unit->Get_Health())-13);
                            }
                            else if (temp1->unit->GetID()== 33)
                            {
                                temp1->unit->Set_Health((temp1->unit->Get_Health())-25);
                            }
							else if (temp1->unit->GetID() == 43)
							{
								temp1->unit->Set_Health((temp1->unit->Get_Health()) - 100);
							}
							else if (temp1->unit->GetID() == 44)
							{
								temp1->unit->Set_Health((temp1->unit->Get_Health()) - 100);
							}
                            else if (temp1->unit->GetID()== 70)
                            {
                                temp1->unit->Set_Health((temp1->unit->Get_Health())-1);
								*score = *score + 4;
                            }
                            if (temp1->unit->Get_Health()<= 0)
                            {
                                temp1->unit->SetAlive(false);
								temp1->unit->SetExplode(true);
								Mix_PlayChannel(-1, gSounds[1], 0);
                            }
                            temp2 = NULL;
                            x = NULL;
                            y = NULL;
                            *score = *score + 1;

                        }
                    }
                    if (temp2 != NULL)
                    {
                       temp2 = temp2->next;
                    }

                }
                else
                {
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
        }
        else
        {
            temp1 = temp1->next;
        }
    }

}

void Queue::Enemy_Fire(long int& frame, Unit* Player, LTexture* image)
{
    Node* temp1 = head;
    Unit* temp2 = NULL;
    while(temp1!=NULL)
    {
        int id = temp1->unit->GetID();
        int random=rand()%2;
        if((id == 21 || id == 22) && frame%30==0) // Easy and Medium Enemy plane
        {
            if (temp1->unit->GetX()>Player->GetX()-250 && temp1->unit->GetX()<Player->GetX()+250 && temp1->unit->GetY()<Player->GetY()-100 )
            {
                if (random== 0)
                {
                    float x = temp1->unit->GetX();
                    float y = temp1->unit->Top();

                    temp2 = new Enemy_Bullet(&image[0], x, y, 0);
                    this->Enqueue(temp2);
                    temp2 = NULL;
                }
            }

        }
        if (id == 23 && frame%30==0) // hard enemy plane
        {
            if (random== 0)
                {
                    float x = temp1->unit->GetX();
                    float y = temp1->unit->GetY();
                    float angle= temp1->unit->GetAngle();
                    cout<<angle<<endl;

                    temp2 = new Enemy_Bullet(&image[0], x, y, angle);
                    this->Enqueue(temp2);
                    temp2 = NULL;
                }
        }
		if ((id == 31) && frame % 88 == 0)// normal turret shoots homing missile
		{
			if (temp1->unit->GetX()>Player->GetX() - 250 && temp1->unit->GetX()<Player->GetX() + 250 && temp1->unit->GetY()<Player->GetY() - 100)
			{
				if (random == 0)
				{
					float x = temp1->unit->GetX();
					float y = temp1->unit->Top();
					temp2 = new Turret_Homing_Missile(&image[4], x, y+75, 0);
					this->Enqueue(temp2);
					temp2 = NULL;
				}
			}

		}
		if ((id == 33) && frame % 30 == 0)// tracking turret shoots in the direction of the player
		{
			if (random == 0)
			{
				float x = temp1->unit->GetX();
				float y = temp1->unit->GetY();
				float angle = temp1->unit->GetAngle();
				temp2 = new Turret_Straight_Missile(&image[4], x, y, angle);
				this->Enqueue(temp2);
				temp2 = NULL;
			}
		}

		if ((id == 70) && frame % 25 == 0) // boss shoots 3 fireballs in a turn, at -45, 0 and 45 angles
		{
			if (random == 0)
			{
				float x = temp1->unit->GetX();
				float y = temp1->unit->Top();
				float angle = tan((float)(Player->GetX()- temp1->unit->GetX())/ (float)(Player->GetY()- temp1->unit->GetY()));
				angle = (int)(angle * (180 / PI)) % 90;
				cout << angle << endl;

				temp2 = new Boss_Weapon(&image[14], x, y, angle);
				this->Enqueue(temp2);
				temp2 = new Boss_Weapon(&image[14], x, y, 0);
				this->Enqueue(temp2);
				temp2 = new Boss_Weapon(&image[14], x, y, -angle);
				this->Enqueue(temp2);
				temp2 = NULL;
			}
		}
        temp1=temp1->next;

    }
}

void Queue::Save(FILE* filepointer)
{
    Node* temp = head;
    char buff[32];
    while(temp!=NULL)
    {
        fputs("<Unit>\n",filepointer);
        fputs(_itoa(temp->unit->GetID(), buff, 10),filepointer);fputs("\n",filepointer);
        fputs(_itoa(temp->unit->GetX(), buff, 10),filepointer);fputs("\n",filepointer);
        fputs(_itoa(temp->unit->GetY(), buff, 10),filepointer);fputs("\n",filepointer);
		fputs(_itoa(temp->unit->Get_Health(), buff, 10), filepointer); fputs("\n", filepointer);
        temp=temp->next;
    }
}


void Queue::plane_pointer(Unit* plane)
{
    this->plane = plane;
}
int Queue::check()
{
    Node* chk = head;
    while(chk != NULL)
    {
        if (chk->unit != NULL)
            return 1;
        else
        {
            return 0;
        }
    }
}

bool Queue::Boss_Alive() // to kep check if the boss is alive.
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->unit->GetID() == 70)
		{
			if (temp->unit->GetAlive() == false)
			{
				temp->unit->SetExplode(true);
				return temp->unit->GetAlive();
			}
			return temp->unit->GetAlive();
		}
		
		temp = temp->next;
	}
}
