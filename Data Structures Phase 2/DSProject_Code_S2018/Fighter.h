#pragma once
#include "c:\Users\kamel\Desktop\Data Structures Phase 2\DSProject_Code_S2018\Enemies\Enemy.h"

class Fighter :
	public Enemy
{
public:
	Fighter(int a, int b, int c, double d, double e, int f, char g,int s);
	void Move(Tower * a,int ts);
	void Attack(Tower * a,int ts);
	void SetPr();
	void SetDT();
	void Die(Tower*a);
	~Fighter();
};

