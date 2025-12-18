#include <iostream>
#include "visuals.h"

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    cout << BOLD_CYAN << "     ╔═══╦═══╦═══╗" << RESET << endl;
    for (int i = 0; i < 3; i++) {
        cout << BOLD_CYAN << "     ║" << RESET;
        for (int j = 0; j < 3; j++) {
            cout << " ";
            if (board[i][j] == 'X') {
                cout << BOLD_RED << "X" << RESET;
            } else if (board[i][j] == 'O') {
                cout << BOLD_BLUE << "O" << RESET;
            } else {
                cout << BOLD_YELLOW << board[i][j] << RESET;
            }
            cout << " " << BOLD_CYAN << "║" << RESET;
        }
        cout << endl;
        if (i < 2) {
            cout << BOLD_CYAN << "     ╠═══╬═══╬═══╣" << RESET << endl;
        }
    }
    cout << BOLD_CYAN << "     ╚═══╩═══╩═══╝" << RESET << endl;
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
    int xWins = 0, oWins = 0, draws = 0;
    
    do {
        resetBoard();
        int moves = 0;
        bool gameWon = false;
        
        printTitle("⭕ TIC-TAC-TOE ❌");
        
        // Display scoreboard
        cout << "\n";
        cout << BOLD_CYAN << "  ╔═══════════ SCOREBOARD ═══════════╗" << RESET << endl;
        cout << BOLD_CYAN << "  ║" << RESET << "  " << BOLD_RED << "X: " << xWins << RESET << "  |  " 
             << BOLD_BLUE << "O: " << oWins << RESET << "  |  " 
             << BOLD_YELLOW << "Draws: " << draws << RESET << "       " << BOLD_CYAN << "║" << RESET << endl;
        cout << BOLD_CYAN << "  ╚═══════════════════════════════════╝" << RESET << endl;
        
        cout << "\n  " << BOLD_RED << "Player X (Red)" << RESET << " vs " << BOLD_BLUE << "Player O (Blue)" << RESET << endl;
        
        while (!gameWon && moves < 9) {
            displayBoard();
            
            string playerColor = (currentPlayer == 'X') ? BOLD_RED : BOLD_BLUE;
            cout << "  " << playerColor << "Player " << currentPlayer << RESET 
                 << BOLD_WHITE << ", enter position (1-9): " << RESET;
            
            int position;
            cin >> position;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << BOLD_RED << "  ❌ Invalid input! Please enter a number." << RESET << endl;
                continue;
            }
            
            if (makeMove(position)) {
                moves++;
                
                if (checkWin()) {
                    clearScreen();
                    printTitle("⭕ TIC-TAC-TOE ❌");
                    displayBoard();
                    printBorder('*', 50);
                    cout << "  " << playerColor << "🎉 PLAYER " << currentPlayer << " WINS! 🎉" << RESET << endl;
                    printBorder('*', 50);
                    
                    if (currentPlayer == 'X') xWins++;
                    else oWins++;
                    
                    gameWon = true;
                } else if (checkDraw()) {
                    clearScreen();
                    printTitle("⭕ TIC-TAC-TOE ❌");
                    displayBoard();
                    printBorder('=', 50);
                    cout << BOLD_YELLOW << "  🤝 IT'S A DRAW! 🤝" << RESET << endl;
                    printBorder('=', 50);
                    draws++;
                    gameWon = true;
                } else {
                    clearScreen();
                    printTitle("⭕ TIC-TAC-TOE ❌");
                    cout << "\n  " << BOLD_RED << "Player X (Red)" << RESET << " vs " << BOLD_BLUE << "Player O (Blue)" << RESET << endl;
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                cout << BOLD_RED << "  ❌ Invalid move! That position is taken or out of range." << RESET << endl;
            }
        }
        
        cout << "\n" << BOLD_WHITE << "  Play again? (y/n): " << RESET;
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    // Final scoreboard
    clearScreen();
    printBorder('=', 50);
    cout << BOLD_CYAN << "  FINAL SCOREBOARD" << RESET << endl;
    printBorder('=', 50);
    cout << BOLD_RED << "  Player X: " << xWins << RESET << endl;
    cout << BOLD_BLUE << "  Player O: " << oWins << RESET << endl;
    cout << BOLD_YELLOW << "  Draws:    " << draws << RESET << endl;
    printBorder('=', 50);
    
    if (xWins > oWins) {
        cout << BOLD_RED << "  🏆 PLAYER X IS THE CHAMPION! 🏆" << RESET << endl;
    } else if (oWins > xWins) {
        cout << BOLD_BLUE << "  🏆 PLAYER O IS THE CHAMPION! 🏆" << RESET << endl;
    } else {
        cout << BOLD_YELLOW << "  🤝 It's a perfect tie!" << RESET << endl;
    }
    
    cout << YELLOW << "\n  Press Enter to return to menu..." << RESET;
    cin.ignore(10000, '\n');
    cin.get();
}
