#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"


// Enemy is the base class of each type of enemy
// Enemy is an abstract class.
class Tower;
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int Distance,Type,ArrivalTime,AttackTime,RLD,EnemyState,FD,TFS,KD,TK,LT,K,Speed;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health,FirePower,Prio,DT;	//Enemy health
	
	//
	// TODO: Add More Data Members As Needed
	//

public:

	Enemy(int a, int b, int c, double d, double e, int f, char g,int s);
	virtual ~Enemy();

	color GetColor() const;
	REGION GetRegion() const;

	void DecrementDist();
	void DecrementHealth(double fp);

	void SetDistance(int d);
	int GetDistance() const;
	void SetId(int id);
	int GetId();
	void SetArrivalTime(int AT);
	int GetArrivalTime();
	void SetAttackTime(int AT);
	int GetAttackTime();
	void SetRLD(int rld);
	int GetRLD();
	void SetES(int es);
	int GetES();
	void SetTFS(int tfs);
	int GetTFS();
	void SetTK(int tk);
	int GetTK();
	void SetKD();
	int GetKD();
	void SetLT(int lt);
	int GetLT();
	void SetHealth(double H);
	double GetHealth();
	void SetFP(double fp);
	double GetFP();
	void SetFD(int fd);
	int GetFD();
    double GetPr();
	double GetDT();
	int GetK();
	void SetRegion(REGION a);
	// Virtual Functions: ----------------
	
	virtual void Move(Tower * a, int ts) = 0;	    //All enemies can move
	virtual void Attack(Tower * a, int ts) = 0;	//All enemies can attack (attacking is paving or shooting or healing)
	virtual  void SetPr() = 0;
	virtual void Die(Tower*a) = 0;
//	virtual void Die(List active ,List killed) = 0;
	
	virtual void SetDT() = 0;
};

