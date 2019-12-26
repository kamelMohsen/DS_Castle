#include "Enemy.h"



Enemy::Enemy(int a, int b, int c, double d, double e, int f, char g,int s)
{
	if (s >= 1)
		Speed = s;

	ID = a;
	if (b == 0)
		Clr = DARKBLUE;
	else if (b == 1)
		Clr = DARKOLIVEGREEN;
	else if (b == 2)
		Clr = ORANGERED;
	if (c>0)
	ArrivalTime = c;
	AttackTime= c;
	if (d>0)
	Health = d;
	if (e>0)
	FirePower = e;
	if (f>0)
	RLD = f;
	if (g == 'A')
		Region = A_REG;
	if (g == 'B')
		Region = B_REG;
	if (g == 'C')
		Region = C_REG;
	if (g == 'D')
		Region = D_REG;
	Distance = 60;
	EnemyState = 0;
	TFS = -1;
}

Enemy::~Enemy()
{
}

color Enemy::GetColor() const
{
	return Clr;
}

REGION Enemy::GetRegion() const
{
	return Region;
}



void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::DecrementHealth(double fp)
{
	if (fp <= Health)
		Health -= fp;
	else
		Health = 0; 

}



void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}

void Enemy::SetId(int id)
{
	if (id > 0)
		ID = id;

}

int Enemy::GetId()
{
	return ID;
}

void Enemy::SetRLD(int rld)
{
	if (RLD > 0 && RLD < 10)
		RLD = rld;

}

int Enemy::GetRLD()
{
	return RLD;
}

void Enemy::SetES(int es)
{
	if (es == 0 || es == 1 || es == 2)
		EnemyState = es;
}

int Enemy::GetES()
{
	return EnemyState;
}

void Enemy::SetTFS(int tfs)
{
	if (tfs > ArrivalTime)
		TFS = tfs;
}

int Enemy::GetTFS()
{
	return TFS;
}

void Enemy::SetTK(int tk)
{
	if (tk > TFS)
		TK = tk;
}

int Enemy::GetTK()
{
	return TK;
}

void Enemy::SetKD()
{
	KD = TK - TFS;
}

int Enemy::GetKD()
{
	return KD;
}

void Enemy::SetLT(int lt)
{
	LT = KD + FD;
}

int Enemy::GetLT()
{
	return LT;
}

void Enemy::SetHealth(double H)
{
	if (H > 0)
		Health = H;
	else
		Health = 100;
}

double Enemy::GetHealth()
{
	return Health;
}

void Enemy::SetFP(double fp)
{
	if (fp > 0)
		FirePower = fp;
}

double Enemy::GetFP()
{
	return FirePower;
}

void Enemy::SetFD(int fd)
{
	FD = TFS - ArrivalTime;
}

int Enemy::GetFD()
{
	return FD;
}



double Enemy::GetPr()
{
	return Prio;
}

double Enemy::GetDT()
{
	return DT;
}

int Enemy::GetK()
{
	return K;
}

void Enemy::SetRegion(REGION a)
{
	Region = a;
}



void Enemy::SetArrivalTime(int AT)
{
	ArrivalTime = AT;
}

int Enemy::GetArrivalTime()
{
	return ArrivalTime;
}

void Enemy::SetAttackTime(int AT)
{
	AttackTime = AT;
}

int Enemy::GetAttackTime()
{
	return AttackTime;
}
