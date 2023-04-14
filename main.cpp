#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

void printSet(set <int> s);
enum type {l, c, s};
struct Cell{
	void Print(){
		cout << "cell:\t"s << abs << endl << "value: \t"s<< value
	<< "\nl c s:\t" << line<< " "<< coll<< " "<< sq << endl;
	};
	int value = -1;
	int abs = -1;
	int line = -1;
	int coll = -1;
	int sq = -1;
	set <int> peeks = {};
};
struct Group{
	set <int> getUniquePeaks(){
		map <int, int> allPeeks = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}};	
		for (Cell * c : list){
			for (int i : c->peeks){
				++allPeeks[i];
			}
		}
		set <int> rt;
		for (const auto& [n, count] : allPeeks){
			if (count == 0){
				rt.insert(n);
			}
		}
		return rt;

	}
	void Print(){
		for (int i = 0; i<9; ++i){
			cout << list[i]->value << " ";
		}
		cout << endl;
	};
	Cell* list[9];
};

struct Game{
	bool analyze_peek(int n){
		bool rt = false;
		Cell * cel = cell(n);
		int li = cel->line;
		int co = cel->coll;
		int sq = cel->sq;
		Group line = this->group(l, cel->line);
		Group coll = this->group(c, cel->coll);
		Group sqd = this->group(s, cel->sq);
		set <int> unique = line.getUniquePeaks();
		for (Cell* c : line.list){
			for (int p : c->peeks){
				if (unique.count(p)){
					c->value = p;
					rt = true;
				}
			}
		}
		unique = coll.getUniquePeaks();
		for (Cell* c : coll.list){
			for (int p : c->peeks){
				if (unique.count(p)){
					c->value = p;
					rt = true;
				}
			}
		}
		unique = sqd.getUniquePeaks();
		for (Cell* c : coll.list){
			for (int p : c->peeks){
				if (unique.count(p)){
					c->value = p;
					rt = true;
				}
			}
		}
		return rt;
	}
	bool makePeeks(int n){
		Cell* chek = cell(n);
		if (chek->value != 0) return false;
		if (chek->peeks.empty()) {
			chek->peeks = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		}

		//set <int> avl_peeks = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		Group g = this->group(l,chek->line);
		

		for (Cell* c : g.list){
			chek->peeks.erase(c->value);
		}
		g = this->group(c, chek->coll);
		
		
		for (Cell* c : g.list){
			chek->peeks.erase(c->value);
		}
		
		
		for (Cell* c : g.list){
			chek->peeks.erase(c->value);
		}
		
		if (chek->peeks.size() == 1) {
			chek->value = *(chek->peeks.begin());
			return true;
		}
		return false;
		
	};
	void print(){
		for (Cell c : game){
			cout << c.value << " ";
			if (c.coll == 8) cout << endl;
		}
	};
	bool filled(){
		for (Cell c : game){
			if (c.value == 0){
				
				return false;
			}
			return true;
		}

	}
	void rw(int abs, int value){
		game[abs].value = value;
		game[abs].abs = abs;
	};
	Cell * cell(int n){
		return &game[n];
	}
	Group group(type type, int n){
		switch (type){
		case 0:
			return lines[n];
		case 1:
			return colls[n];
		case 2:
			return sqs[n];
		};
		return sqs[n];
	};
	Cell game[81];
	Group lines[9];
	Group colls[9];
	Group sqs[9];
};

struct peeks{
	peeks(Cell * c): values(c->peeks), cell(c){};
	set<int> values;
	Cell * cell;
};

void printSet(set <int> s){
	for (int i : s){
		cout << i << " "s;
	}
	cout <<  endl;
}


int main()
{
	
	int Poles[]={
		0, 0, 0, 5, 0, 8, 6, 0, 1,
		0, 0, 4, 0, 0, 0, 0, 3, 0,
		5, 0, 0, 0, 1, 3, 0, 0, 0,
		9, 5, 0, 0, 7, 1, 2, 6, 4,
		4, 7, 0, 6, 0, 0, 0, 0, 0,
		2, 3, 0, 4, 8, 6, 1, 5, 0,
		6, 0, 9, 0, 0, 0, 7, 1, 0,
		0, 0, 5, 0, 9, 0, 4, 0, 3,
		1, 0, 0, 8, 0, 0, 0, 0, 0};
	/* for (int i = 0; i<81; ++i){
	// 	Pole[i] = i;
	// } */
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	const int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Cell * lines[9][9];
	Cell * colls[9][9];
	Cell * sqs[9][9];
	Game g1;
//генерация поля и распределение по группам ⬇️⬇️⬇️
	for (int i = 0; i<81; ++i){
		int l = i / 9; int c = i % 9; int sq;
		int v;
		g1.game[i].abs = i;
		cin >> g1.game[i].value;
		g1.game[i].line = l;
		g1.game[i].coll = c;

		if (l <3){
			if (c <3) sq = 0;
			else if (c <6) sq = 1;
			else  sq = 2;
		}else if (l <6){
			if (c <3) sq = 3;
			else if (c <6) sq = 4;
			else sq = 5;
		}else{
			if (c <3) sq = 6;
			else if (c <6) sq = 7;
			else  sq = 8;
		}
		g1.game[i].sq = sq;
		g1.lines[l].list[c] = &g1.game[i];
		g1.colls[c].list[l] = &g1.game[i];
		g1.sqs[sq].list[(c % 3 + (l%3 * 3 ))] = &g1.game[i];
	};
	
	//g1.cell(73).Print(); 		//Распечатать клетку
	//g1.rw(73, 99);			//Присвоить клетке 73 значение 99
	//g1.group(s, 6).Print();	//Распечатать 6 группу sq
	//lien = строка = l = 0 // collumn = столбец = c = 1
	//square = квадрат = s = 2

	bool changed = false;
	for (int in = 0; in<100; ++in){
		for (int i; i<81; ++i){
			if(g1.makePeeks(i)){
				changed = true;
			}
		}
		for (int i; i<81; ++i){
			g1.analyze_peek(i);
		}
	}
	//printSet(g1.cell(47)->peeks);
	//g1.cell(47)->Print();
	g1.print();
	
}
// Мусор ⬇️⬇️⬇️
// konsole -e "bash -c '/home/ilyam/Code/FSTcpp/main;read '"


// void printCell(Cell c){
// 	cout << "cell:\t"s << c.abs << endl << "value: \t"s<< c.value
// 	<< "\nl c s:\t" << c.line<< " "<< c.coll<< " "<< c.sq << endl;
// }
// void printGroup(Group  group){
// 	for (int i = 0; i<9; ++i){
// 		cout << group.values[i]->value << " ";
// 	}
// 	cout << endl;
// }

	// Cell();
	// Cell(const int val, const int abs, Cell ** lines, Cell ** colls, Cell ** sqs){
	// 	this -> abs = abs;
	// 	this -> value = val;
	// 	this -> line = abs / 9;
	// 	this -> coll = abs % 9;
	// 	if (this -> line <3){
	// 		if (this -> coll <3) this -> sq = 0;
	// 		else if (this -> coll <6) this -> sq = 1;
	// 		else this -> sq = 2;
	// 	}else if (this -> line <6){
	// 		if (this -> coll <3) this -> sq = 3;
	// 		else if (this -> coll <6) this -> sq = 4;
	// 		else this -> sq = 5;
	// 	}else{
	// 		if (this -> coll <3) this -> sq = 6;
	// 		else if (this -> coll <6) this -> sq = 7;
	// 		else this -> sq = 8;
	// 	}
	// 	lines[this -> line][this -> coll] = *this;
	// 	colls[this -> coll][this -> line] = *this;
	// 	sqs[this -> sq][(this -> coll%3 + (line%3 * 3 ))];
	// };
