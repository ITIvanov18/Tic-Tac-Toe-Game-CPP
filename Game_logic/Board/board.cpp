#include "board.h"
#include <iostream>

using namespace std;

void printBoard(const char board[3][3]) {
    cout << "━━━━━━━━━━━━━" << endl;
    for (int row = 0; row < 3; row++) {
        cout << "┃ ";
        for (int col = 0; col < 3; col++) {
            cout << board[row][col] << " ┃ ";
        }
        cout << "\n━━━━━━━━━━━━━" << endl;
    }
}

