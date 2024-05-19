#include <iostream>

#include "game.h"
#include "../Board/board.h"
#include "../Player/player.h"


using namespace std;

bool checkDraw(const char board[3][3]) {
	// can be done with counter

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (board[row][col] != 'X' && board[row][col] != 'O') {
				return false;
			}
		}
	}

	cout << "It's a draw" << endl;

	return true;
}

bool checkWin(const char board[3][3], char currentPlayer) {
	for (int i = 0; i < 3; i++) {
		// Check rows
		if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
			return true;
		}
		// Check columns
		if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
			return true;
		}
	}
	// Check diagonals
	if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
		return true;
	}
	if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
		return true;
	}

	return false;
}


void gameLoop() {
	char board[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'},
	};

	cout << "Let's play Tic Tac Toe!" << endl;
	cout << "Starting player: ❌" << endl;
	char currentPlayer = 'X';
	bool gameEnded = false;

	while (!gameEnded) {
		printBoard(board);
		makeMove(board, currentPlayer);

		if (checkWin(board, currentPlayer)) {
			printBoard(board);
			cout << "Player " << currentPlayer << " wins!🥇" << endl;
			gameEnded = true;
		}
		else if (checkDraw(board)) {
			printBoard(board);
			gameEnded = true;
		}
		else {
			currentPlayer = switchPlayer(currentPlayer);
		}
	}
}