#include <iostream>
#include <set>
using namespace std;

struct Cell{
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
	int value = -1;
	int abs = -1;
	int line = -1;
	int coll = -1;
	int sq = -1;

};

void printCell(Cell game[], int t){
	cout << "cell"s << endl << "value: \t\t"s<< game[t].value
	<< "\nabsolute: \t" << game[t].abs
	<< "\nline : \t\t" << game[t].line
	<< "\ncollumn : \t" << game[t].coll
	<< "\nsquare : \t" << game[t].sq << endl;
}
void printGroup(Cell * group[]){
	for (int i = 0; i<9; ++i){
		cout << group[i]->abs << ", ";
	}
	cout << endl;
}
int main()
{
	
	int Pole[]={
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
	Cell game[81];

	for (int i = 0; i<81; ++i){
		int l = i / 9; int c = i % 9; int sq;
		game[i].abs = i;
		game[i].value = Pole[i];
		game[i].line = l;
		game[i].coll = c;

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
		game[i].sq = sq;
		lines[l][c] = &game[i];
		colls[c][l] = &game[i];
		sqs[sq][(c % 3 + (l%3 * 3 ))] = &game[i];
	};
	printGroup(colls[0]);
}

// konsole -e "bash -c '/home/ilyam/Code/FSTcpp/main;read '"
