#include "ShieldedFighter.h"
#include "Castle\Tower.h"
#include <mciapi.h>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")

ShieldedFighter::ShieldedFighter(int a, int b, int c, double d, double e, int f, char g,int s) :Enemy(a, b, c, d, e, f, g,s)
{

	Type = 2;
	SetPr();
	K = 2;
}

void ShieldedFighter::Move(Tower * a, int ts)
{
	SetPr();

	for (int i = 0; i < 4; i++)
	{
		if ((a + i)->GetRegion() == Region)
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

void ShieldedFighter::Attack(Tower * a, int ts)
{
	for (int i = 0; i < 4; i++)
	{
		if ((a + i)->GetRegion() == Region)
		{
			if (AttackTime == ts)
			{

				if (Distance <= 30)
				{
					SetDT();

					(a + i)->SetHealth((a + i)->GetHealth() - DT);
				
				}

				AttackTime = ts + RLD + 1;
			}
		}
	}

}


void ShieldedFighter::SetPr()
{

	Prio = 1+ ((FirePower / (double)(Distance))*C1 + (C2 / (double)(ArrivalTime + 1)) + (Health*C3));
}

void ShieldedFighter::SetDT()
{
	DT = ((double)2 / (Distance + 1))*(FirePower);
}

void ShieldedFighter::SetConsts(double a, double b, double c)
{
	if (a > 0 && b > 0 && c > 0)

	{
		C1 = a;
		C2 = b;
		C3 = c;

	}
}

void ShieldedFighter::Die(Tower * a)
{
	a->Kill();
}

ShieldedFighter::~ShieldedFighter()
{
}
