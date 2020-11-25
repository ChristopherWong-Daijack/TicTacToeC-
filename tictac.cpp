#include "tictac.h"
#include <array>
#include <iostream>

using namespace std;

TicTac::TicTac(int board[ArrayY][ArrayX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			board[i][j] = 0;
		}
	}
}


void TicTac::drawGrid(int board[ArrayY][ArrayX]) {
	for (int i = 0; i <MAX ; i++) {
		for (int j = 0; j < MAX; j++) {
			if (board[i][j] == 0) {
				cout << "- ";
			}
			else if(board[i][j]==1) {
				cout << "X ";
			}
			else {
				cout << "O ";
			}
			
		}
		cout << endl;
	}
}


bool upDownCheck(int board[ArrayY][ArrayX], bool isPlayer1Turn,int yPosition) {
	bool winStatus = false;
	int counter = 0;
	if(isPlayer1Turn==true){//player1
		for (int i = 0; i < 3; i++) {
			 if(board[i][yPosition] == 1) {
				++counter;
			 }

			/*if (board[i][yPosition] == 1) {
				++counter;
			}*/
		}
		if (counter == 3) {
			winStatus = true;
		}

	}
	else {//player2
		for (int i = 0; i < 3; i++) {
			if (board[i][yPosition] == 2) {//check from top down
				++counter;
			}

			/*if (board[i][yPosition] == 1) {
				++counter;
			}*/
		}
		if (counter == 3) {//3 in a row
			winStatus = true;
		}
	}
	return winStatus;
}
bool leftRightCheck(int board[ArrayY][ArrayX], bool isPlayer1Turn, int xPosition) {
	bool winStatus = false;
	int counter = 0;
	if (isPlayer1Turn == true) {
		for (int i = 0; i < 3; i++) {
			if (board[xPosition][i] == 1) {
				++counter;
			}

			/*if (board[i][yPosition] == 1) {
				++counter;
			}*/
		}
		if (counter == 3) {
			winStatus = true;
		}

	}
	else {
		for (int i = 0; i < 3; i++) {
			if (board[xPosition][i] == 2) {
				++counter;
			}

			/*if (board[i][yPosition] == 1) {
				++counter;
			}*/
		}
		if (counter == 3) {
			winStatus = true;
		}
	}
	return winStatus;
}
bool leftDiagonalCheck(int board[ArrayY][ArrayX], bool isPlayer1Turn) {
	bool winStatus = false;
	int counter = 0;
	if (isPlayer1Turn == true) {
		for (int i = 0; i < 3; i++) {
			if (board[i][i] == 1) {
				++counter;
			}

			/*if (board[i][yPosition] == 1) {
				++counter;
			}*/
		}
		if (counter == 3) {
			winStatus = true;
		}

	}
	else {
		for (int i = 0; i < 3; i++) {
			if (board[i][i] == 2) {
				++counter;
			}

			/*if (board[i][yPosition] == 1) {
				++counter;
			}*/
		}
		if (counter == 3) {
			winStatus = true;
		}
	}
	return winStatus;
}
bool rightDiagonalCheck(int board[ArrayY][ArrayX], bool isPlayer1Turn) {
	bool winStatus = false;
	int counter = 0;
	if (isPlayer1Turn == true) {
		for (int i = 0; i < 3; i++) {
			if (board[0+i][2-i] == 1) {
				++counter;
			}

			/*if (board[i][yPosition] == 1) {
				++counter;
			}*/
		}
		if (counter == 3) {
			winStatus = true;
		}

	}
	else {
		for (int i = 0; i < 3; i++) {
			if (board[0 + i][2 - i] == 2) {
				++counter;
			}

			/*if (board[i][yPosition] == 1) {
				++counter;
			}*/
		}
		if (counter == 3) {
			winStatus = true;
		}
	}
	return winStatus;
}

bool TicTac::check(int board[ArrayY][ArrayX], bool isPlayer1Turn) {
	bool winner = false;
	int anotherNum = 0;
	while (board[x][y] != 0) {
		cout << "Please pick another number" << endl;
		cin >> anotherNum;
		convertToArray(anotherNum);
		
	}

		if (isPlayer1Turn == true) {//player 1 turn
			board[x][y] = 1;
			if (upDownCheck(board, isPlayer1Turn,y) == true||leftRightCheck(board, isPlayer1Turn, x)==true|| leftDiagonalCheck(board, isPlayer1Turn)==true|| rightDiagonalCheck(board, isPlayer1Turn) == true) {
				winner = true;
			}
			//check up down left right diagonal left diagonal right value
		}
		else {
			board[x][y] = 2;
			if (upDownCheck(board, isPlayer1Turn, y) == true || leftRightCheck(board, isPlayer1Turn, x) == true || leftDiagonalCheck(board, isPlayer1Turn) == true || rightDiagonalCheck(board, isPlayer1Turn) == true) {
				winner = true;
			}
			//check up down left right diagonal left diagonal right value
		}
	
	return winner;
}
bool TicTac::tieGame(int board[ArrayY][ArrayX]) {
	bool tieGame = true;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (board[i][j]== 0) {//If any array has a 0 this means game isn't finishe
				tieGame = false;
			}
			
		}
	}
	return tieGame;
}
void TicTac::convertToArray(int input) {
	/*if (input == 1) {
		x = 0;
		y = 0;
	}else if (input == 2) {
		x = 0;
		y = 1;
	}
	else if (input == 3) {
		x = 0;
		y = 2;
	}
	else if (input == 4) {
		x = 1;
		y = 0;
	}
	else if (input == 5) {
		x = 1;
		y = 1;
	}
	else if (input == 6) {
		x = 1;
		y = 2;
	}
	else if (input == 7) {
		x = 2;
		y = 0;
	}
	else if (input == 8) {
		x = 2;
		y = 1;
	}
	else if (input == 9) {
		x = 2;
		y = 2;
	}*/
	x = (input - 1) / ArrayX;
	y = (input - 1) % ArrayY;
}