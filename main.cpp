#include <iostream>
#include <set>
using namespace std;


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
};
struct Group{
	void Print(){
		for (int i = 0; i<9; ++i){
			cout << values[i]->value << " ";
		}
		cout << endl;
	};
	int id;
	Cell* values[9];
};

struct Game{
	void rw(int abs, int value){
		game[abs].value = value;
		game[abs].abs = abs;
	};
	Cell cell(int n){
		return game[n];
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

	};
	Cell game[81];
	Group lines[9];
	Group colls[9];
	Group sqs[9];
};


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

	const set<int>  list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
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
		g1.lines[l].values[c] = &g1.game[i];
		g1.colls[c].values[l] = &g1.game[i];
		g1.sqs[sq].values[(c % 3 + (l%3 * 3 ))] = &g1.game[i];
	};
	
	g1.cell(73).Print(); 		//Распечатать клетку
	//g1.rw(73, 99);			//Присвоить клетке 73 значение 99
	g1.group(s, 6).Print();	//Распечатать 6 группу sq
	//lien = строка = l = 0 // collumn = столбец = c = 1
	//square = квадрат = s = 2

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
