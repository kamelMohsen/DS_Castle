#pragma once
#include "List.h"
#include "Queue.h"
#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "../DSProject_Code_S2018/CMUgraphicsLib/CMUgraphics.h"
// it is the controller of the project
class Battle
{
private:
	Castle BCastle;
	int EnemyCount;	//the actual number of enemies in the game
	Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function

	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Battle();
	void AddEnemy(Enemy* Ptr);
	void DrawEnemies(GUI * pGUI);
	Castle * GetCastle();
	int LoadData(const string a, List &Enemies, int &max);
	void RemoveEnemy(Enemy * a);
	void Simulater();
	void activateEnemies(List &a, List &b, List &c, List &d, List &e, int i, int &count);
	void UpdateEnemies(List &a, List &b, List &c, List &d, Queue &e, int i, ActionType at1 );
	void Kill(List &a,Queue &b,int ts,Tower*d);
	bool TransferEnemies(int i);
	ActionType GetAction(window * pWind,GUI * gui);
	bool isDestroyed();
	void printinfo(GUI * a);
	void Save(Queue*a,string b,int c);
	double AvgFSD(Queue * a);
	double AvgKD(Queue*a);
	// TODO: Add More Member Functions As Needed
	//
};

