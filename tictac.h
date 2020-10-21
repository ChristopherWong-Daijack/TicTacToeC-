
#ifndef TICTAC_H
#define TICTAC_H
#include <array>
#include <iostream>
const int MAX = 3;
using namespace std;
const int ArrayY = 3;
const int ArrayX = 3;
class TicTac {
	int gameBoard[3][3] = {};
	int x = 0;
	int y = 0;
	
public:

	void drawGrid(int board[ArrayY][ArrayX]);
	TicTac(int board[ArrayY][ArrayX]);
	TicTac() {};
	bool check(int board[ArrayY][ArrayX], bool isPlayer1Turn);
	void convertToArray(int value);
};


#endif // !1
