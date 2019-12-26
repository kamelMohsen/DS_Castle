#include "Battle.h"
#include "Paver.h"
#include "Fighter.h"
#include "ShieldedFighter.h"
#include <Windows.h>
#include <fstream>
#include <mciapi.h>
#include <iomanip>

#include<string>


#pragma comment(lib, "Winmm.lib")
#include <iostream>
using namespace std;

Battle::Battle()
{
	mciSendString("open \"F.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	EnemyCount = 0;
	BCastle.GetTowers()->SetUD(30);
	(BCastle.GetTowers()+1)->SetUD(30);
	(BCastle.GetTowers()+2)->SetUD(30);
	(BCastle.GetTowers()+3)->SetUD(30);
}

void Battle::AddEnemy(Enemy* Ptr)
{
	if (EnemyCount < MaxEnemyCount) 
		BEnemiesForDraw[EnemyCount++] = Ptr;

	// Note that this function doesn't allocate any enemy objects
	// It only makes the first free pointer in the array
	// points to what is pointed to by the passed pointer Ptr
}

void Battle::DrawEnemies(GUI * pGUI)
{
	pGUI->DrawEnemies(BEnemiesForDraw, EnemyCount);
}

Castle * Battle::GetCastle()
{
	return &BCastle;
}

int Battle::LoadData(const string a, List &Enemies, int &max)
{
	int count1 = 0;
	ifstream kamel(a);
	if (kamel.is_open())
	{
		int N;
		double TH, TP, C11, C22, C33;
		kamel >> TH;
		BCastle.SetTowersHealth(TH);
		BCastle.SetTowersHealthcp();
		kamel >> N;
		BCastle.SetTowersN(N);
		kamel >> TP;
		BCastle.SetTowersTP(TP);
		kamel >> C11;

		kamel >> C22;
		kamel >> C33;
		int S, TYP, T, RLD,SP;
		double POW, H;
		char R;

		S = 0;
		while (S != -1)
		{
			kamel >> S;
			if (S != -1)
			{
				count1 += 1;
				kamel >> TYP;
				kamel >> T;
				if (T > 0)
					max = T;
				kamel >> H;
				kamel >> POW;
				kamel >> RLD;
				kamel >> SP;
				kamel >> R;

				if (TYP == 0)
				{
					Paver  *  newEnemy = new Paver(S, TYP, T, H, POW, RLD, R,SP);
					Enemies.insert(newEnemy);
				}
				if (TYP == 1)
					{
						Fighter  *  newEnemy = new Fighter(S, TYP, T, H, POW, RLD, R,SP);
						Enemies.insert(newEnemy);
					}
				if (TYP == 2)
				{
					ShieldedFighter  *  newEnemy = new ShieldedFighter(S, TYP, T, H, POW, RLD, R,SP);
					newEnemy->SetConsts(C11, C22, C33);
					Enemies.insert(newEnemy);
				}
				
			}
		}
	}
	max = count1;
	return count1;
}
void Battle::RemoveEnemy(Enemy * a)
{
	if (a != nullptr)
	{

		for (int i = 0; i <= EnemyCount; i++)
		{


			if (BEnemiesForDraw[i] == a)
			{
				for (i; i <= EnemyCount - 1; i++)
				{
					BEnemiesForDraw[i] = BEnemiesForDraw[i + 1];

				}
				EnemyCount--;
			}

		}
	}
}

void Battle::Simulater()
{
	GUI * pGUI = new GUI(BCastle.GetTowers());
	string ab;
	List Enemies, ActiveA, ActiveB, ActiveC, ActiveD;
	Queue Killed;
	int Max = 0; 
	int EnemyCount1, i; i = 0;int ActiveEnemies = 0;
    ActionType at=GetAction(pGUI->getWindow(),pGUI);
	if (at == 0)
	{
		pGUI->PrintMessage("Enter file name to load:");
		ab = pGUI->GetString();
		EnemyCount1 = LoadData(ab+".txt", Enemies, Max);
		ActiveEnemies = EnemyCount1;
	}
	ActionType at1 = StepByStep;
	while (at1!=4)
	{
		at1 = GetAction(pGUI->getWindow(), pGUI);
		if (at1 == 0)
		{
			pGUI->PrintMessage("Enter file name to load:");
			ab = pGUI->GetString();
			at1 = GetAction(pGUI->getWindow(), pGUI);
			EnemyCount1 = LoadData(ab + ".txt", Enemies, Max);
			ActiveEnemies = EnemyCount1;

		}
		while (ActiveEnemies != 0 && !(isDestroyed()))

		{
			Point a;
			if (at1 == 2)
				pGUI->GetPointClicked(a);
			if (at1 == 3)
				Sleep(400);
			pGUI->ClearStatusBar();

			pGUI->ClearBattleArea();

			pGUI->DrawCastle(BCastle.GetTowers());
	
			activateEnemies(ActiveA, ActiveB, ActiveC, ActiveD, Enemies, i, EnemyCount1);
			
			
			if (at1 == 2 || at1 == 3)
				DrawEnemies(pGUI);
			if (at1 == 2 || at1 == 3)
				printinfo(pGUI);
			UpdateEnemies(ActiveA, ActiveB, ActiveC, ActiveD, Killed, i,at1);
			ActiveEnemies = ActiveA.getLength() + ActiveB.getLength() + ActiveC.getLength() + ActiveD.getLength();
			
			i++;
		}
		string av;
		if (ActiveEnemies != 0)
			av="Game Win!!!!!";
		else if (ActiveEnemies = 0 && isDestroyed())
			av="Game Win!!!!!";
		else if (ActiveEnemies != 0 && isDestroyed())
			av="Game Win!!!!!";
		else
			av="Game Loss!!!!!";
		Save(&Killed,av,Max);
		pGUI->ClearStatusBar();
		i = 0; EnemyCount = 0;
		for (int z = 0; z < 4; z++)
		{
			(BCastle.GetTowers() + z)->SetUD(30);
			(BCastle.GetTowers() + z)->resetEnemiesKilled();
		}
		pGUI->ClearBattleArea();
		pGUI->DrawCastle(BCastle.GetTowers());
		if ((at1 == 1 || at1 == 2 || at1 == 3) && at==0 )

		{
				pGUI->PrintMessage(av);
			EnemyCount1 = LoadData(ab + ".txt", Enemies, Max);
			ActiveEnemies = EnemyCount1;
		}

		}
	return;
}

void Battle::activateEnemies(List &a, List &b, List &c, List &d, List &e,int i , int &count )
{
	while (count != 0 && e.getEntry(count)->GetArrivalTime() == (i + 1))
	{
		(BCastle.GetTowers() + 1)->SetActive(&b);
		(BCastle.GetTowers() + 3)->SetActive(&d);
		(BCastle.GetTowers() + 2)->SetActive(&c);
		(BCastle.GetTowers()+0)->SetActive(&a);
		if (e.getEntry(count)->GetRegion() == A_REG)
		{

			a.insert(e.getEntry(count));
			AddEnemy(e.getEntry(count));
			e.getEntry(count)->SetES(1);
		    e.remove(count);
			count--;
		}
		else if (e.getEntry(count)->GetRegion() == B_REG)
		{

			b.insert(e.getEntry(count));
			AddEnemy(e.getEntry(count));
			e.getEntry(count)->SetES(1);
			e.remove(count);
			count--;
		}

		else if (e.getEntry(count)->GetRegion() == C_REG)
		{

			c.insert(e.getEntry(count));
			AddEnemy(e.getEntry(count));
			e.getEntry(count)->SetES(1);
			e.remove(count);
			count--;
		}
		else if (e.getEntry(count)->GetRegion() == D_REG)
		{

			d.insert(e.getEntry(count));
			AddEnemy(e.getEntry(count));
			e.getEntry(count)->SetES(1);
			e.remove(count);
			count--;
		}

	}
	
}

void Battle::UpdateEnemies(List & a, List & b, List & c, List & d,Queue &e,int i ,ActionType at1)
{
	TransferEnemies(0);
	BCastle.GetTowers()->Attack(i+1);
	Kill(a, e,i+1,(BCastle.GetTowers()+0));
	for (int j = 0; j <a.getLength() ; j++)
	{
		

		if (a.getLength() != 0 )
		{
			if (at1 != 1 && a.getEntry(j+1)->GetDistance()<=30)
				mciSendString("play mp3 from 0", NULL, 0, NULL);
			a.getEntry(j +1)->Move(BCastle.GetTowers(), i + 1);
			a.getEntry(j + 1)->Attack(BCastle.GetTowers(), i + 1);
			TransferEnemies(0);
		}
		
	
	}
	(BCastle.GetTowers()+1)->Attack(i+1);
	Kill(b, e,i+1, (BCastle.GetTowers() + 1));

	for (int k = 0; k < b.getLength(); k++)
	{
	
	
		if (b.getLength() != 0)
		{
		
			if (at1 != 1 && b.getEntry(k + 1)->GetDistance()<=30)
				mciSendString("play mp3 from 0", NULL, 0, NULL);
			b.getEntry(k + 1)->Move(BCastle.GetTowers(), i + 1);
		    b.getEntry(k + 1)->Attack(BCastle.GetTowers(), i + 1);
				TransferEnemies(0);
		}
	
	
		
	}
	(BCastle.GetTowers() + 2)->Attack(i+1);
	Kill(c, e,i+1, (BCastle.GetTowers() + 2));
	for (int l = 0; l < c.getLength(); l++)
	{
	
		
		if (c.getLength() != 0)
		{
			if (at1 != 1 && c.getEntry(l + 1)->GetDistance() <= 30)
				mciSendString("play mp3 from 0", NULL, 0, NULL);

			c.getEntry(l + 1)->Move(BCastle.GetTowers(), i + 1);
     		c.getEntry(l + 1)->Attack(BCastle.GetTowers(), i + 1);

			TransferEnemies(0);
		}
		
	
		

		
	}
	(BCastle.GetTowers() + 3)->Attack(i+1);
	Kill(d,e, i+1, (BCastle.GetTowers() + 3));
	for (int m = 0; m < d.getLength(); m++)
	{

	
		if (d.getLength() != 0)
		{
			if (at1 != 1 && d.getEntry(m + 1)->GetDistance() <= 30)
				mciSendString("play mp3 from 0", NULL, 0, NULL);

			d.getEntry(m + 1)->Move(BCastle.GetTowers(), i + 1);
			d.getEntry(m + 1)->Attack(BCastle.GetTowers(), i + 1);

				TransferEnemies(0);
		}
		
		
		
		
	}
}

void Battle::Kill(List & a,Queue &b,int ts,Tower *d)
{
	
	for (int j = 0; j <a.getLength(); j++)
	{
		if (a.getEntry(j + 1) != nullptr)
		{
			if (a.getEntry(j + 1)->GetHealth() == 0)
			{

				a.getEntry(j + 1)->SetTK(ts);
				a.getEntry(j + 1)->Die(d);
				a.getEntry(j + 1)->SetKD();
				a.getEntry(j + 1)->SetFD(ts - a.getEntry(j + 1)->GetTFS());
				a.getEntry(j + 1)->SetLT(ts - a.getEntry(j + 1)->GetArrivalTime());
				b.enqueue(a.getEntry(j + 1));
				RemoveEnemy(a.getEntry(j + 1));
				a.remove(j + 1);
				j--;
			}
		}
	}
}

bool Battle::TransferEnemies(int i)
{
	
		if ((BCastle.GetTowers() + 0)->GetHealth() == 0 && (BCastle.GetTowers() + 1)->GetHealth() == 0 && (BCastle.GetTowers() + 2)->GetHealth() == 0 && (BCastle.GetTowers() + 3)->GetHealth() == 0)
			return true;
		int j = i + 1;
		if ((BCastle.GetTowers() + i)->GetHealth() == 0)
		{

			if (i == 3)
				j = 0;

				for (int n = 0; n < (BCastle.GetTowers() + i)->GetActive()->getLength(); n++)
				{

					if ((BCastle.GetTowers() + i)->GetActive()->getEntry(n + 1)->GetDistance() < (BCastle.GetTowers() + j)->GetUD())
					{
						(BCastle.GetTowers() + i)->GetActive()->getEntry(n + 1)->SetDistance((BCastle.GetTowers() + j)->GetUD());
					}
						(BCastle.GetTowers() + i)->GetActive()->getEntry(n + 1)->SetRegion((BCastle.GetTowers() + j)->GetRegion());
						(BCastle.GetTowers() + j)->GetActive()->insert((BCastle.GetTowers() + i)->GetActive()->getEntry(n + 1));
						(BCastle.GetTowers() + i)->GetActive()->remove(n + 1);
						n--;
					

				}



		}

		if (i == 4)
		{
			return false;
		}
		return TransferEnemies(i + 1);


	return false;
}

ActionType Battle::GetAction(window * pWind, GUI * gui)
{
		

	    int x, y;
		pWind->WaitMouseClick(x,y);	//Get the coordinates of the user click

		while (y > 50 || x > 400)
		{
			pWind->WaitMouseClick(x, y);
		}
	
			if (y >= 0 && y < 50)
			{
			
				int ClickedItem = (x / 80);
				
				switch (ClickedItem)
				{
					
				
				case MENU_LOAD: 
				{
					return LOAD;
				}
				case MENU_SILENT:
				{
					return SILENT;
				}

				case MENU_INTERACTIVE:
				{ 
					return InterActive;
				}
				case MENU_STEPBYSTEP:
				{

					return StepByStep;
				}
				case MENU_EXIT: 
				{
					return Exit;
				}

				}
			}

	


}

bool Battle::isDestroyed()
{
	for (int i = 0; i < 4; i++)
	{
		if ((BCastle.GetTowers() + i)->GetHealth() > 0)
			return false;
	}
	return true;
}

void Battle::printinfo(GUI * a)
{
	int j = 0;
	for (int i = 0; i < 1200; i += 300)
	{
		a->DrawString(15 + i, 520, "Tower Health : " + to_string((BCastle.GetTowers()+j)->GetHealth()));
		a->DrawString(15 + i, 535, "Enemies Killed : " + to_string((BCastle.GetTowers() + j)->GetEnemiesKilled()));
		a->DrawString(15 + i, 550, "Active Enemies : " + to_string((BCastle.GetTowers() + j)->GetActive()->getLength()));
		a->DrawString(15 + i, 565, "Unpaved Distance : " + to_string((BCastle.GetTowers() + j)->GetUD()));
		j += 1;
	}


}

void Battle::Save(Queue*a,string b,int c)
{
	string name;
	name = "GameOutput";
	ofstream Outfile;
	Outfile.open(name + ".txt");
	Outfile << "KTS       S          FD       KD        LT\n";
	int x = a->getlength();
	for (int i = 0; i <x ; i++)
	{
		Enemy*aa = a->peekFront();
		Outfile << aa->GetTK()<< setw(10) << aa->GetId()<< setw(10) << aa->GetFD()<<setw(10) << aa->GetKD() << setw(10) << aa->GetLT() << "\n";
		a->enqueue(a->peekFront());
		a->dequeue();

	}
	Outfile << "T1_Total_Damage"<<setw(20)<<"T2_Total_Damage"<<setw(20) <<"T3_Total_Damage"<<setw(20) << "T4_Total_Damage \n";
	Outfile << BCastle.GetTowers()->GetDamage()<< setw(20) << (BCastle.GetTowers()+1)->GetDamage()<< setw(20) << (BCastle.GetTowers()+2)->GetDamage()<< setw(18) << (BCastle.GetTowers()+3)->GetDamage()<< "        \n";
	Outfile << "R1_Unpaved_Dist" << setw(20) << "R2_Unpaved_Dist" << setw(20) << "R3_Unpaved_Dist" << setw(20) << "R4_Unpaved_Dist \n";
	Outfile << BCastle.GetTowers()->GetUD() << setw(20) << (BCastle.GetTowers() + 1)->GetUD() << setw(20) << (BCastle.GetTowers() + 2)->GetUD() << setw(18) << (BCastle.GetTowers() + 3)->GetUD() << "        \n";

	Outfile << b<<"\n";
	Outfile <<"Total Enemies = " << c<<"\n";
	Outfile << "Average First-Shot Delay   =" << AvgFSD(a)<<"\n";
	Outfile << "Average Kill Delay   =" << AvgKD(a) << "\n";
	Outfile.close();

}

double Battle::AvgFSD(Queue * a)
{
	double sum = 0;
	int x = a->getlength();
	for (int i = 0; i < x; i++)
	{
		sum += a->peekFront()->GetFD();
		a->enqueue(a->peekFront());
		a->dequeue();
	}
	return ((double)sum/x);
}

double Battle::AvgKD(Queue * a)
{
	double sum = 0;
	int x = a->getlength();
	for (int i = 0; i < x; i++)
	{
		sum += a->peekFront()->GetKD();
		a->enqueue(a->peekFront());
		a->dequeue();
	}
	return ((double)sum / x);
}

