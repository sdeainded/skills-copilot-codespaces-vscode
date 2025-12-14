#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2) {
            cout << "---|---|---" << endl;
        }
    }
    cout << "\n";
}

bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    
    if (position < 1 || position > 9) {
        return false;
    }
    
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    
    board[row][col] = currentPlayer;
    return true;
}

bool checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
    currentPlayer = 'X';
}

void playTicTacToe() {
    char playAgain;
    
    do {
        resetBoard();
        int moves = 0;
        bool gameWon = false;
        
        cout << "\n=== Tic-Tac-Toe ===" << endl;
        cout << "Player 1: X | Player 2: O" << endl;
        
        while (!gameWon && moves < 9) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter position (1-9): ";
            
            int position;
            cin >> position;
            
            if (makeMove(position)) {
                moves++;
                
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameWon = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw!" << endl;
                    gameWon = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                cout << "Invalid move! Try again." << endl;
            }
        }
        
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}
