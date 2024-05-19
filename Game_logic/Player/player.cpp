#include "player.h"
#include <iostream>
#include <limits.h>

using namespace std;

char switchPlayer(char currentPlayer) {
    cout << "Switch turns" << endl;
    return currentPlayer == 'X' ? 'O' : 'X';
}

void makeMove(char board[3][3], char currentPlayer) {
    int choice;
    cout << "Enter the number of the cell: ";

    while (!(cin >> choice) || choice < 1 || choice > 9) {
		cin.clear(); // Изчиства грешките от потока
		cin.ignore(INT_MAX, '\n'); // Игнорира грешния вход
		cout << "Invalid cell! You can choose between the numbers 1 and 9."<< endl;
		cout << "Enter the number of the cell: ";
	}

    int index = choice - 1;
    int row = index / 3;
    int col = index % 3;

    board[row][col] = currentPlayer;
}

