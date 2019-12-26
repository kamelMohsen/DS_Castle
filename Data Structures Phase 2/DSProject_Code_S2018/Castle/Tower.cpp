#include "Tower.h"
#include "../List.h"







Tower::Tower()
{
	Active = nullptr;
	EnemiesKilled = 0;
}

void Tower::DecrementUnpaved()
{
	if (UnpavedDistance>2)
	UnpavedDistance--;
}

void Tower::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
	
}

double Tower::GetHealth() const
{
	return Health;
}

void Tower::SetRegion(int a)
{
	if (a==0)
	    RegionT = A_REG;
	if (a == 1)
		RegionT = B_REG;
	if (a == 2)
		RegionT = C_REG;
	if (a == 3)
		RegionT = D_REG;
	

}

REGION Tower::GetRegion()
{
	return RegionT;
}

void Tower::SetFP(double fp)
{
	if (fp > 0)
		FP = fp;
	else
		FP = 10;
}

double Tower::GetFP()
{
	return FP;
}

void Tower::SetN(int n)
{
	if (n > 0)
		N = n;
	else
		N = 1;

}

int Tower::GetN()
{
	return N;
}

void Tower::SetUD(int ud)
{
	if (ud >=2 )
		UnpavedDistance = ud;
}

int Tower::GetUD()
{
	return UnpavedDistance;
}



double Tower::GetTD()
{
	TotalDamage = Health - Healthcp;
	return TotalDamage;
}

void Tower::SetDE(int ED,int k)
{
	DE = ((double)1 / ED)*(FP)*((double)1 / k);
}

double Tower::GetDE()
{
	return DE;
}

void Tower::setHealthcp()
{
	Healthcp = Health;
}

void Tower::SetActive(List *a)
{
	if (a != nullptr)
	{
		Active = a;
	}
}

void Tower::Attack(int ts)
{ 
	if (Active)
	{
		Active->sort();
		int c = 0;
		for (int i = 0; i < Active->getLength(); i++)
		{

			if (c == N)
				break;
			if (Active->getEntry(i + 1) != nullptr)
			{
				if (Active->getEntry(i + 1)->GetHealth() != 0)
				{
					SetDE(Active->getEntry(i + 1)->GetDistance(), Active->getEntry(i + 1)->GetK());
					if (Active->getEntry(i + 1)->GetTFS() == -1)
					{
						Active->getEntry(i + 1)->SetTFS(ts);
						Active->getEntry(i + 1)->SetFD(Active->getEntry(i + 1)->GetTFS()- Active->getEntry(i + 1)->GetArrivalTime());
					}
						Active->getEntry(i + 1)->DecrementHealth(DE);
					c++;

				}
			}
		}
	}
}

List * Tower::GetActive()
{
	return Active;
}

void Tower::Kill()
{
	EnemiesKilled++;
}

void Tower::resetEnemiesKilled()
{
	EnemiesKilled = 0;
}

int Tower::GetEnemiesKilled()
{
	return EnemiesKilled;
}

double Tower::GetDamage()
{
	return Healthcp-Health;
}


