#include <stdio.h>
#include <iostream>
#include <fstream>
#include"solver.h"
#include "RubiksGrid.h"




int main()
{
	
	int i,j;
	RubiksGrid final(3,3),initial(3,3);

	solver a;
	bool done = false;
	vector<RubiksGrid *> arr;
	char str[]="";

	while (1)
	{
		cout << "1. Read initial state.\n";
		cout << "2. Read final state.\n";
		cout << "3. Do depth first search using recuresion.\n";
		cout << "4. Do depth first search using stack.\n";
		cout << "5. Do breadth first search.\n";
		cout << "6. Exit\n";
		cin >> i;
		if (i == 1)
		{
			system("cls");
			cout << "Enter filename: \n";
			cin >> str;
			initial.Read(str);
		}
		if (i == 2)
		{
			system("cls");
			cout << "Enter filename: \n";
			cin >> str;
			final.Read(str);
		}
		if (i == 3)
		{
			system("cls");
			a.recursion(&final, &initial);
			cin >> j;
		}
		if (i == 4)
		{
			system("cls");
			a.dfs(&final, &initial);
			cin >> j;
		}
		if (i == 5)
		{
			system("cls");
			a.bfs(&final, &initial);
			cin >> j;
		}
		if (i == 6)
		{
			system("cls");
			break;
		}
		system("cls");
	}


}
