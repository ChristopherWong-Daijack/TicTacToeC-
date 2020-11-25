#include <iostream>
#include <array>
#include "tictac.h"

using namespace std;
int main() {
	
	cout << "Welcome to GHETTO tic tac toe" << endl;
	cout << "Pick a number from 1-9" << endl;
	cout << "1 2 3" << endl;
	cout << "4 5 6" << endl;
	cout << "7 8 9" << endl;
	bool gameOn = true;
	int board[ArrayY][ArrayX] = {};
	TicTac game(board);
	int playerturn = 2;
	int input = 0;
	bool isPlayer1Turn = false;
	bool tieGame = false;
	while (gameOn == true) {
		if (playerturn % 2 == 0) {//Player 1
			isPlayer1Turn = true;
			cout << "Please choose an option player 1" << endl;
			cin >> input;
			while (input < 1 || input>9) {
				cout << "Please choose a valid option 1-9" << endl;
				cin >> input;
			}
			game.convertToArray(input);
			if (game.check(board, isPlayer1Turn) == true) {
				gameOn = false;
				cout << "Player 1 wins" << endl;
			}
			else if (game.tieGame(board)==true) {
				cout << "Tie Game" << endl;
				gameOn = false;
			}
			
			//Run some check to see if input is valid or if he won
			game.drawGrid(board);
			playerturn++;
		
		}
		else {//Player 2
			isPlayer1Turn = false;
			cout << "Please choose an option player 2" << endl;
			cin >> input;
			while (input < 1 || input>9) {
				cout << "Please choose a valid option 1-9" << endl;
				cin >> input;
			}
			game.convertToArray(input);
			
			if (game.check(board, isPlayer1Turn) == true) {
				gameOn = false;
				cout << "Player 2 wins" << endl;
			}
			else if (game.tieGame(board) == true) {
				cout << "Tie Game" << endl;
				gameOn = false;
			}

			game.drawGrid(board);
			playerturn++;
		}
		

	}
	return 0;
}