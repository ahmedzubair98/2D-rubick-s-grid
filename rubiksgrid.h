#ifndef RUBIKSRubiksGrid_H
#define RUBIKSRubiksGrid_H

using namespace std;
enum Direction{LEFT,RIGHT};
enum BlockNO{A,B,C,D};

class RubiksGrid
{
public:
	//write the destructor
	~RubiksGrid() ;
	RubiksGrid() {};
	RubiksGrid(int Rows,int Cols);
	int TotalColumns(){return cols;}
	int TotalRows(){return rows;}
	void Rotate(Direction direction,int CornerRowIndex,int CornerColIndex);
	RubiksGrid* Rotate(Direction direction,BlockNO) ;
	void Read(char *FileName);
	void Print();
	bool operator == (const RubiksGrid &g);
	bool operator != (const RubiksGrid &g);
	const RubiksGrid & operator = (const RubiksGrid &g);
	RubiksGrid *getParent(){return parent;}
	BlockNO blk;
	Direction dirn;
	void printBlock();
	void printDirn();
	
private:

	void RotateLeft(int rowIndex,int colIndex);
	void RotateRight(int rowIndex,int colIndex);

	int **RubiksGridArray;
	int rows, cols;
	
	RubiksGrid *parent;

	friend class solver;
};

class corner
{
public:
	corner(int X,int Y){x = X;y=Y;}
	int x,y;
};

#endif 