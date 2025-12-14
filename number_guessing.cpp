#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playNumberGuessing() {
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    
    cout << "\n=== Number Guessing Game ===" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    cout << "Can you guess it?" << endl;
    
    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "\nCongratulations! You guessed it in " << attempts << " attempts!" << endl;
        }
    } while (guess != secretNumber);
}
