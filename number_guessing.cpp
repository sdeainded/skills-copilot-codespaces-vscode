#include <iostream>
#include "visuals.h"

using namespace std;

void playNumberGuessing() {
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    
    printTitle("🎯 NUMBER GUESSING GAME 🎯");
    cout << CYAN << "\n  I'm thinking of a number between " << BOLD_YELLOW << "1" << CYAN << " and " << BOLD_YELLOW << "100" << RESET << endl;
    cout << CYAN << "  Can you guess it?" << RESET << endl;
    printBorder('-', 50);
    
    do {
        cout << "\n" << BOLD_WHITE << "  Attempt #" << (attempts + 1) << " - Enter your guess: " << RESET;
        cin >> guess;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << BOLD_RED << "  ❌ Invalid input! Please enter a number." << RESET << endl;
            continue;
        }
        
        attempts++;
        
        if (guess > secretNumber) {
            int diff = guess - secretNumber;
            cout << RED << "  ⬇️  Too high! ";
            if (diff > 30) cout << "(Way too high!)";
            else if (diff > 10) cout << "(Getting warmer...)";
            else cout << "(Very close!)";
            cout << RESET << endl;
        } else if (guess < secretNumber) {
            int diff = secretNumber - guess;
            cout << BLUE << "  ⬆️  Too low! ";
            if (diff > 30) cout << "(Way too low!)";
            else if (diff > 10) cout << "(Getting warmer...)";
            else cout << "(Very close!)";
            cout << RESET << endl;
        } else {
            cout << "\n";
            printBorder('*', 50);
            cout << BOLD_GREEN << "  🎉 CONGRATULATIONS! 🎉" << RESET << endl;
            cout << BOLD_YELLOW << "  You guessed it in " << BOLD_CYAN << attempts << BOLD_YELLOW << " attempt(s)!" << RESET << endl;
            
            if (attempts <= 5) {
                cout << BOLD_MAGENTA << "  ⭐⭐⭐ Amazing! You're a mind reader! ⭐⭐⭐" << RESET << endl;
            } else if (attempts <= 8) {
                cout << BOLD_CYAN << "  ⭐⭐ Great job! Very impressive! ⭐⭐" << RESET << endl;
            } else if (attempts <= 12) {
                cout << BOLD_GREEN << "  ⭐ Good work! Well done! ⭐" << RESET << endl;
            } else {
                cout << GREEN << "  Nice! You got it!" << RESET << endl;
            }
            printBorder('*', 50);
        }
    } while (guess != secretNumber);
    
    cout << YELLOW << "\n  Press Enter to return to menu..." << RESET;
    cin.ignore();
    cin.get();
}
