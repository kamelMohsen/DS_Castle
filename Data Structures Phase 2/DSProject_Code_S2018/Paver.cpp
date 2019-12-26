#include "Paver.h"

#include "Castle\Tower.h"

#include <mciapi.h>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")


Paver::Paver(int a, int b, int c, double d, double e, int f, char g,int s):Enemy(a,b,c,d,e,f,g,s)
{
	mciSendString("open \"P.mp3\" type mpegvideo alias mp3", NULL, 1, NULL);
	Type = 0;
	SetPr();
	K = 1;
}

void Paver::Move(Tower * a,int ts)
{
	for (int i = 0; i < 4; i++)
	{
		if ((a + i)->GetRegion() == Region)
		{
			for (int m = 0; m < Speed; m++)
			{
				if (Distance > (a + i)->GetUD() && ts != AttackTime)
				{
					DecrementDist();
				}
			}
		}
	}

		

		
		

	
	
	
}

void Paver::Attack(Tower * a,int ts)
{
	SetDT();
	for (int i = 0; i < 4; i++)
	{
		if ((a + i)->GetRegion() == Region)
		{
			if (AttackTime == ts)
			{
				for (int j = 0; j < FirePower; j++)
				{
					if (Distance == (a + i)->GetUD())
					{
						(a + i)->DecrementUnpaved();
						//PlaySound(TEXT("P.wav"), NULL, SND_FILENAME);
					}
					DecrementDist();

				}
			
				AttackTime = ts + RLD + 1;

			}



		}
	}


			
}

void Paver::SetPr()
{
	Prio = ((double)1 / ArrivalTime);
}

void Paver::SetDT()
{
	DT = 0;
}

void Paver::Die(Tower * a)
{
	a->Kill();
}

Paver::~Paver()
{
}
