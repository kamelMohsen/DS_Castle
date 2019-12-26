#pragma once
#include"Enemies\Enemy.h"
class ShieldedFighter :
	public Enemy
{
	double C1, C2, C3;
public:
	ShieldedFighter(int a, int b, int c, double d, double e, int f, char g,int s);
	void Move(Tower * a, int ts);
	void Attack(Tower * a, int ts);
	void SetPr();
	void SetDT();
	void SetConsts(double a,double b,double c);
	void Die(Tower*a);
	~ShieldedFighter();
};

