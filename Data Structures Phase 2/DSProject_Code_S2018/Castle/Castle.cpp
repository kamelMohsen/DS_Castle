#include "Castle.h"

#include "..\GUI\GUI.h"

Castle::Castle()
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetRegion(i);
		Towers[i].SetUD(30);
	}
}

Tower * Castle::GetTowers()
{
	return Towers;
}


void Castle::SetTowersHealth(double h)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetHealth(h);
	}
}

void Castle::SetTowersHealthcp()
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].setHealthcp();
	}
}

void Castle::SetTowersN(int a)
{
	for (int i = 0; i < 4; i++)
	{
	
		Towers[i].SetN(a);
	
	}
}

void Castle::SetTowersTP(double tp)
{
	for (int i = 0; i < 4; i++)
	{

		Towers[i].SetFP(tp);

	}
}

double Castle::GetTowersHealth()
{
	return Towers[0].GetHealth();
}

int Castle::GetTowersN()
{
	return Towers[0].GetN();
}

double Castle::GetTowersTP()
{
	return Towers[0].GetFP();
}

