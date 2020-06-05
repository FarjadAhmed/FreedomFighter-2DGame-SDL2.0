#include "pch.h"
#include "File_IO.h"


File_IO::File_IO()
{

}

File_IO::~File_IO()
{

}

void File_IO::New_game()
{

}

void File_IO::Load(LTexture* image, Unit* plane, Queue* myQueue, char* filename, int* score)
{
    Unit* unit;
    FILE* filepointer_data;
    char buff[32];
    int x,y,id,counter,health;
    x=y=id=counter=health=0;



    filepointer_data=fopen(filename,"r");

    if (filepointer_data!=NULL)
    {
        while (fgets(buff,32,filepointer_data)!=NULL)
        {
            counter++; // counts number of lines in the file.
        }
    }

    filepointer_data=fopen(filename,"r");
	fgets(buff, 32, filepointer_data); //score_tag
	fgets(buff, 32, filepointer_data); //score
	*score = atoi(buff);
	fgets(buff, 32, filepointer_data); //player_power_up_tag
	fgets(buff, 32, filepointer_data); //straight_missile
	plane->Set_Straight_Missile(atoi(buff));
	fgets(buff, 32, filepointer_data); //homing_missile
	plane->Set_Homing_Missile(atoi(buff));
	counter = counter - 5;
    for (int i=0;i<counter/5;i++)
    {
        fgets(buff,32,filepointer_data);//tag
        fgets(buff,32,filepointer_data);// id
        id=atoi(buff);
        fgets(buff,32,filepointer_data);// x
        x=atoi(buff);
        fgets(buff,32,filepointer_data);// y
        y=atoi(buff);
		fgets(buff, 32, filepointer_data);// health
		health = atoi(buff);

        if (id==10)//plane
        {
            plane->SetX(x);
            plane->SetY(y);
			plane->Set_Health(health);
        }
        else if (id==21)//enemy_easy
        {
            unit = new Enemy_Easy(&image[0], x, y);
			unit->Set_Health(health);
            myQueue->Enqueue(unit);
            unit = NULL;
        }
        else if (id==22)//enemy_medium
        {
            unit = new Enemy_Medium(&image[0], x, y);
			unit->Set_Health(health);
            myQueue->Enqueue(unit);
            unit = NULL;
        }
        else if (id==23)//enemy_hard
        {
            unit = new Enemy_Hard(&image[0], x, y);
			unit->Set_Health(health);
            myQueue->Enqueue(unit);
            unit = NULL;
        }
		else if (id == 31)//turret_easy
		{
			unit = new Turret(&image[3], x, y);
			unit->Set_Health(health);
			myQueue->Enqueue(unit);
			unit = NULL;
		}
		else if (id == 33)//turret_hard
		{
			unit = new Turret_Hard(&image[3], x, y);
			unit->Set_Health(health);
			myQueue->Enqueue(unit);
			unit = NULL;
		}
        else if (id==41)//player_bullet
        {
            unit = new Player_Bullet(&image[0], x, y);
            myQueue->Enqueue(unit);
            unit = NULL;
        }
        else if (id==42)//enemy_bullet
        {
            unit = new Player_Bullet(&image[0], x, y);
            myQueue->Enqueue(unit);
            unit = NULL;
        }
		else if (id == 48)//straight_missile
		{
			unit = new Player_Straight_Missile(&image[12], x, y);
			myQueue->Enqueue(unit);
			unit = NULL;
		}
		else if (id == 49)//homing_missile
		{
			unit = new Player_Homing_Missile(&image[12], x, y);
			myQueue->Enqueue(unit);
			unit = NULL;
		}
		else if (id == 50)//power_up_homing_missile
		{
			unit = new Power_Up_Homing_Missile(&image[12], x, y);
			myQueue->Enqueue(unit);
			unit = NULL;
		}
		else if (id == 51)//power_up_straight_missile
		{
			unit = new Power_Up_Straight_Missile(&image[12], x, y);
			myQueue->Enqueue(unit);
			unit = NULL;
		}
		else if (id == 52)//health_power_up
		{
			unit = new Health_Up(&image[11], x, y);
			myQueue->Enqueue(unit);
			unit = NULL;
		}
		else if (id == 70)//boss
		{
			unit = new Boss(&image[13], x, y);
			myQueue->Enqueue(unit);
			unit = NULL;
		}

    }
    return ;

}

void File_IO::Save(Unit* plane, Queue* myQueue, char* filename, int score)
{
    FILE* filepointer_data;
    char buff[32];
    int x,y,id,angle;
    x=y=id=angle=0;
    filepointer_data= fopen(filename,"w"); // write on txt file.
	fputs("<Score>\n", filepointer_data); //Score
	fputs(_itoa(score, buff, 10), filepointer_data); fputs("\n", filepointer_data);
	fputs("<Player_Power_Ups>\n", filepointer_data); // Player power ups
	fputs(_itoa(plane->Get_Straight_Missile(), buff, 10), filepointer_data); fputs("\n", filepointer_data);
	fputs(_itoa(plane->Get_Homing_Missile(), buff, 10), filepointer_data); fputs("\n", filepointer_data);
    fputs("<Player>\n",filepointer_data); // player
    fputs(_itoa(plane->GetID(), buff, 10),filepointer_data);fputs("\n",filepointer_data); //player ID
    fputs(_itoa(plane->GetX(), buff, 10),filepointer_data);fputs("\n",filepointer_data); // player X
    fputs(_itoa(plane->GetY(), buff, 10),filepointer_data);fputs("\n",filepointer_data); // player Y
	fputs(_itoa(plane->Get_Health(), buff, 10), filepointer_data); fputs("\n", filepointer_data); // player health

    myQueue->Save(filepointer_data); // saves whole queue.
    fclose(filepointer_data);
}
