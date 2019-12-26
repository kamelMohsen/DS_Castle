#include "Fighter.h"
#include "Castle\Tower.h"

Fighter::Fighter(int a, int b, int c, double d, double e, int f, char g,int s) :Enemy(a, b, c, d, e, f, g,s)
{

	Type = 1;
	SetPr();
	K = 2;
}

void Fighter::Move(Tower * a, int ts)
{
	for (int i = 0; i < 4; i++)
	{
		if ((a+i)->GetRegion() == Region)
		{
			for (int m = 0; m < Speed; m++)
			{
				if (Distance > (a + i)->GetUD())
				{
					DecrementDist();
				}
			}

		}
	}
	
}

void Fighter::Attack(Tower * a,int ts)
{
	for (int i = 0; i < 4; i++)
	{
		if ((a+i)->GetRegion() == Region)
		{
			if (AttackTime == ts)
			{

				if (Distance <= 30)
				{
					SetDT();

					(a + i)->SetHealth((a + i)->GetHealth()-DT);
		
				}

				AttackTime = ts + RLD + 1;
			}
		}
	}
	
	
	
}

void Fighter::SetPr()
{
	Prio = ((double)1 / ArrivalTime);
}

void Fighter::SetDT()
{
	DT = ((double)1 / (Distance+1))*(FirePower);
}

void Fighter::Die(Tower * a)
{
	a->Kill();
}


Fighter::~Fighter()
{
}
