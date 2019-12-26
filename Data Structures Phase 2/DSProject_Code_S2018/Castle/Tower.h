#pragma once
#include "..\Defs.h"
class List;
class Tower
{
	double Health,Healthcp,FP,TotalDamage, DE;
	int N, UnpavedDistance, C1,C2,C3 , EnemiesKilled;
	REGION RegionT;
	List * Active;
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Tower();
	void DecrementUnpaved();
	void SetHealth(double h);
	double GetHealth() const;
	void SetRegion(int a);
	REGION GetRegion();
	void SetFP(double fp);
	double GetFP();
	void SetN(int n);
	int GetN();
	void SetUD(int ud);
	int GetUD();
	double GetTD();
	void SetDE(int ED,int k);
	double GetDE();
	void setHealthcp();
	void SetActive(List *a);
	void Attack(int ts);
	List* GetActive();
	void Kill();
	void resetEnemiesKilled();
	int GetEnemiesKilled();
	double GetDamage();
	//
	// TODO: Add More Member Functions As Needed
	//

};

