#pragma once
#include "Castle\Tower.h"
#include "Enemies\Enemy.h"

class Paver:public Enemy

{
public:
	Paver(int a, int b, int c, double d, double e, int f, char g,int s);
	void Move(Tower * a,int ts);
	void Attack(Tower * a,int ts);
	void SetPr();
	void SetDT();
	void Die(Tower*a);
	~Paver();
};

