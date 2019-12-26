#include "Battle.h"
#include "GUI\GUI.h"
#include "List.h"
#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	Battle * pGameBattle = new Battle;
	pGameBattle->Simulater();
	return 0;

}

