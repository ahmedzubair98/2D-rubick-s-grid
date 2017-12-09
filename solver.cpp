#include<iostream>
#include"solver.h"
#include"stacks.h"
#include"ques.h"
#include<fstream>

using namespace std;


void solver::recursion(RubiksGrid *f, RubiksGrid *in)
{
	*final = *f;
	*initial = *in;
	bool done = false;
	recursion(final, initial, done);
	for (int i = 0; i < arr.size(); i++)
		arr[i]->Print();
	Write();
}

void solver::dfs(RubiksGrid *f, RubiksGrid *in)
{
	*final = *f;
	*initial = *in;
	bool done = false;
	dfs(final, initial, done);
	for (int i = 0; i < arr.size(); i++)
		arr[i]->Print();
	Write();
}


void solver::bfs(RubiksGrid *f, RubiksGrid *in)
{
	*final = *f;
	*initial = *in;
	bool done = false;
	bfs(final, initial, done);
	for (int i = 0; i < arr.size(); i++)
		arr[i]->Print();
	Write();
}


void solver::recursion(RubiksGrid *f, RubiksGrid *in, bool & done)
{
	RubiksGrid *p = new RubiksGrid(3, 3);
	*p = *f;
	RubiksGrid *q = new RubiksGrid(3, 3);
	*q = *in;
	bool flag = false;
	BlockNO b[] = { A,B,C,D };
	Direction directions[] = { RIGHT,LEFT };

	
	for (int k = 0; k < arr.size() && !flag; k++)
	{
		if (*arr[k] == *q)
			flag = true;
	}
	if (*q == *p)
	{
		done = true;
	}
	if (!flag)
	{
		arr.push_back(q);
		//q->Print();
		for (int j = 0; j < 4 && !done; j++)
		{
			in = q->Rotate(directions[0], b[j]);
			recursion(f, in, done);
		}
	}
		
}



void solver::dfs(RubiksGrid *f, RubiksGrid *in, bool & done)
{
	RubiksGrid *p = new RubiksGrid(3, 3);
	*p = *f;
	RubiksGrid *q = new RubiksGrid(3, 3);
	*q = *in;
	bool flag = false;
	stack<RubiksGrid *> stack;
	BlockNO b[] = { A,B,C,D };
	Direction directions[] = { RIGHT,LEFT };
	stack.push(q);
	while (!stack.empty() && !done)
	{
		stack.pop(q);
		for (int i = 0; i < arr.size() && !flag; i++)
		{
			if (*arr[i] == *q)
				flag = true;
		}
		if (!flag)
		{
			arr.push_back(q);
			if (*q == *p)
				done = true;
			//q->Print();
			for (int i = 3; i >= 0; i--)
			{
				in = q->Rotate(directions[0], b[i]);
				stack.push(in);
			}
		}
		flag = false;
	}
}


void solver::bfs(RubiksGrid *f, RubiksGrid *in, bool & done)
{
	RubiksGrid *p = new RubiksGrid(3, 3);
	*p = *f;
	RubiksGrid *q = new RubiksGrid(3, 3);
	*q = *in;
	bool flag = false;
	que<RubiksGrid *> que(50000);
	BlockNO b[] = { A,B,C,D };
	Direction directions[] = { RIGHT,LEFT };
	que.enque(q);
	while (!que.empty() && !done)
	{
		que.deque(q);
		for (int i = 0; i < arr.size() && !flag; i++)
		{
			if (*arr[i] == *q)
				flag = true;
		}
		if (!flag)
		{
			arr.push_back(q);
			//q->Print();
			if (*q == *p)
				done = true;
			for (int i = 0; i < 4; i++)
			{
				in = q->Rotate(directions[0], b[i]);
				que.enque(in);
			}
		}
		flag = false;
	}
}


void solver::Write()
{
	int i, j;
	ofstream fout;
	fout.open("visitedArr.txt");
	for (int n = 0; n < arr.size(); n++)
	{
		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				fout << arr[n]->RubiksGridArray[i][j] << " ";

			}
			fout << "\n";
		}
		fout << "\n";
	}
	fout.close();
}