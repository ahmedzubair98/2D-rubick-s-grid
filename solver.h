#include"rubiksgrid.h"
#include<vector>


class solver {
public:
	solver() {final = new RubiksGrid(3, 3);initial = new RubiksGrid(3, 3);};
	~solver() { delete final; delete initial; };
	void dfs(RubiksGrid *final, RubiksGrid *initial);
	void bfs(RubiksGrid *final, RubiksGrid *initial);
	void recursion(RubiksGrid *final, RubiksGrid *initial);
	void Write();
	vector<RubiksGrid *> getArr() { return arr; }
private:
	void dfs(RubiksGrid *final, RubiksGrid *initial, bool & done);
	void bfs(RubiksGrid *final, RubiksGrid *initial, bool & done);
	void recursion(RubiksGrid *final, RubiksGrid *initial, bool & done);
	RubiksGrid *final, *initial;
	vector<RubiksGrid *> arr;
};