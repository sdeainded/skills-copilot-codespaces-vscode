#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function declarations from game files
void playNumberGuessing();
void playRockPaperScissors();
void playTicTacToe();

void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "    Welcome to C++ Games Collection!    " << endl;
    cout << "========================================" << endl;
    cout << "1. Number Guessing Game" << endl;
    cout << "2. Rock, Paper, Scissors" << endl;
    cout << "3. Tic-Tac-Toe" << endl;
    cout << "4. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    // Initialize random seed once
    srand(time(0));
    
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input! Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                playNumberGuessing();
                break;
            case 2:
                playRockPaperScissors();
                break;
            case 3:
                playTicTacToe();
                break;
            case 4:
                cout << "\nThanks for playing! Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
