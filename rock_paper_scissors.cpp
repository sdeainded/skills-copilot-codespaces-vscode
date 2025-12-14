#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playRockPaperScissors() {
    srand(time(0));
    int playerChoice, computerChoice;
    char playAgain;
    
    do {
        cout << "\n=== Rock, Paper, Scissors ===" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> playerChoice;
        
        if (playerChoice < 1 || playerChoice > 3) {
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }
        
        computerChoice = rand() % 3 + 1;
        
        string choices[] = {"", "Rock", "Paper", "Scissors"};
        cout << "\nYou chose: " << choices[playerChoice] << endl;
        cout << "Computer chose: " << choices[computerChoice] << endl;
        
        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            cout << "You win!" << endl;
        } else {
            cout << "Computer wins!" << endl;
        }
        
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}
