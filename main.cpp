#include <iostream>
#include <cstdlib>
#include <ctime>
#include "visuals.h"

using namespace std;

// Function declarations from game files
void playNumberGuessing();
void playRockPaperScissors();
void playTicTacToe();

void displayMenu() {
    clearScreen();
    cout << "\n";
    cout << BOLD_CYAN << "╔════════════════════════════════════════════════╗" << RESET << endl;
    cout << BOLD_CYAN << "║" << BOLD_YELLOW << "    🎮  Welcome to C++ Games Collection!  🎮    " << BOLD_CYAN << "║" << RESET << endl;
    cout << BOLD_CYAN << "╠════════════════════════════════════════════════╣" << RESET << endl;
    cout << BOLD_CYAN << "║" << RESET << "  " << BOLD_GREEN << "1." << RESET << " 🎯 Number Guessing Game                    " << BOLD_CYAN << "║" << RESET << endl;
    cout << BOLD_CYAN << "║" << RESET << "  " << BOLD_GREEN << "2." << RESET << " ✊ Rock, Paper, Scissors                  " << BOLD_CYAN << "║" << RESET << endl;
    cout << BOLD_CYAN << "║" << RESET << "  " << BOLD_GREEN << "3." << RESET << " ⭕ Tic-Tac-Toe                            " << BOLD_CYAN << "║" << RESET << endl;
    cout << BOLD_CYAN << "║" << RESET << "  " << BOLD_RED << "4." << RESET << " 🚪 Exit                                   " << BOLD_CYAN << "║" << RESET << endl;
    cout << BOLD_CYAN << "╚════════════════════════════════════════════════╝" << RESET << endl;
    cout << "\n" << BOLD_WHITE << "Enter your choice (1-4): " << RESET;
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
            cout << BOLD_RED << "\n❌ Invalid input! Please enter a number." << RESET << endl;
            cout << YELLOW << "Press Enter to continue..." << RESET;
            cin.get();
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
                clearScreen();
                cout << BOLD_GREEN << "\n✨ Thanks for playing! Goodbye! ✨\n" << RESET << endl;
                break;
            default:
                cout << BOLD_RED << "\n❌ Invalid choice! Please try again." << RESET << endl;
                cout << YELLOW << "Press Enter to continue..." << RESET;
                cin.ignore(10000, '\n');
                cin.get();
        }
    } while (choice != 4);
    
    return 0;
}
