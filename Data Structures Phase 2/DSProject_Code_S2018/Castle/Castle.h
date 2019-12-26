#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"

class Castle
{
	Tower Towers[NoOfRegions];
	
	//
	// TODO: Add More Data Members As Needed
	//
	
public:

	Castle();
	Tower * GetTowers();
	void SetTowersHealth(double h);
	void SetTowersHealthcp();
	void SetTowersN(int a);
	void SetTowersTP(double tp);
	double GetTowersHealth();
	int GetTowersN();
	double GetTowersTP();

	//
	// TODO: Add More Member Functions As Needed
	//
};
