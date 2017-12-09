#include <stdio.h>
#include <iostream>
#include <fstream>
#include "rubiksgrid.h"

RubiksGrid::RubiksGrid(int Rows,int Cols)
{
	int i,j;
	RubiksGridArray = new int*[Rows];
	for ( i=0;i<Rows;++i)
		RubiksGridArray[i] = new int[Cols];

	rows = Rows;
	cols = Cols;

	//fill in the goal state
	int number = 1;
	for (i=0;i<Rows;++i)
	{	for (j=0;j<Cols;++j)
		{
			RubiksGridArray[i][j] = number;
			number++;
		}
	}
	parent = NULL;
}

void RubiksGrid::Print()
{
	int i,j;

	for (i=0;i<rows;++i)
	{	for (j=0;j<cols;++j)
		{
			cout << RubiksGridArray[i][j] << " ";
			
		}
		cout << "\n";
	}

	cout <<"\n";
}


RubiksGrid* RubiksGrid::Rotate(Direction direction,BlockNO block) 
{
	
	RubiksGrid *g = new RubiksGrid(3,3);
	g->parent = this;
	g->blk = block;
	g->dirn = direction;
	*g = *this;

	if (block == A)
		g->Rotate(direction,0,0);
	else if (block == B)
		g->Rotate(direction,0,2);
	else if (block == C)
		g->Rotate(direction,2,0);
	else
		g->Rotate(direction,2,2);
	
	return g;
}

//this is assuming we are only rotating a 2x2 block and the indices are valid
void RubiksGrid::Rotate(Direction direction,int CornerRowIndex,int CornerColIndex)
{
	//first adjust coordinates
	if (CornerRowIndex == 0)
		CornerRowIndex++;
	if (CornerColIndex == TotalColumns()-1)
		CornerColIndex--;


	if (direction == LEFT)
		RotateLeft(CornerRowIndex,CornerColIndex);
	else
		RotateRight(CornerRowIndex,CornerColIndex);
}

void RubiksGrid::RotateLeft(int rowIndex,int colIndex)
{
	int temp = RubiksGridArray[rowIndex][colIndex];
	RubiksGridArray[rowIndex][colIndex] = RubiksGridArray[rowIndex-1][colIndex];
	RubiksGridArray[rowIndex-1][colIndex] = RubiksGridArray[rowIndex-1][colIndex+1];
	RubiksGridArray[rowIndex-1][colIndex+1] = RubiksGridArray[rowIndex][colIndex+1];
	RubiksGridArray[rowIndex][colIndex+1] = temp;
}

void RubiksGrid::RotateRight(int rowIndex,int colIndex)
{
	int temp = RubiksGridArray[rowIndex][colIndex];
	RubiksGridArray[rowIndex][colIndex] = RubiksGridArray[rowIndex][colIndex+1];
	RubiksGridArray[rowIndex][colIndex+1] = RubiksGridArray[rowIndex-1][colIndex+1];
	RubiksGridArray[rowIndex-1][colIndex+1] = RubiksGridArray[rowIndex-1][colIndex];
	RubiksGridArray[rowIndex-1][colIndex] = temp;
}

bool RubiksGrid::operator == (const RubiksGrid &g)
{
	bool same = true;
	for (int i=0;i<rows&&same;++i)
	{
		for (int j=0;j<cols&&same;++j)
		{
			if (g.RubiksGridArray[i][j] != RubiksGridArray[i][j])
				same = false;
		}
	}
	return same;
}

bool RubiksGrid::operator != (const RubiksGrid &g)
{
	bool same = true;
	for (int i=0;i<rows&&same;++i)
	{
		for (int j=0;j<cols&&same;++j)
		{
			if (g.RubiksGridArray[i][j] != RubiksGridArray[i][j])
				same = false;
		}
	}
	return !same;
}


void RubiksGrid::Read(char *fileName)
{
	ifstream strm(fileName);
	while (!strm.is_open())
	{
		system("cls");
		cout << "File name incorrect. Try again!\n";
		cout << "Enter filename: ";
		cin >> fileName;
		strm.open(fileName);
	}
	for (int i=0;i<rows;++i)
	{
		for (int j=0;j<cols;++j)
		{
			strm >> RubiksGridArray[i][j];
		}
	}

}

const RubiksGrid & RubiksGrid::operator = (const RubiksGrid &g)
{
	for (int i=0;i<rows;++i)
	{
		for (int j=0;j<cols;++j)
		{
			RubiksGridArray[i][j] = g.RubiksGridArray[i][j];
		}
	}
	return *this;
}

void RubiksGrid::printBlock()
{
	if (blk==A) cout << 'A'; 
	else if (blk==B) cout << 'B';
	else if (blk==C) cout << 'C';
	else cout << 'D';
}
void RubiksGrid::printDirn()
{	
	if (dirn == LEFT) cout << "Left";
	else cout << "Right";
}

RubiksGrid::~RubiksGrid()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] RubiksGridArray[i];
	}
	delete[] RubiksGridArray;
	delete parent;
}