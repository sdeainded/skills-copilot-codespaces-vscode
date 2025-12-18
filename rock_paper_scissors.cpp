#include <iostream>
#include "visuals.h"

using namespace std;

void playRockPaperScissors() {
    int playerChoice, computerChoice;
    char playAgain;
    int playerScore = 0, computerScore = 0, ties = 0;
    
    do {
        printTitle("✊ ROCK, PAPER, SCISSORS ✂️");
        
        // Display scoreboard
        cout << "\n";
        cout << BOLD_CYAN << "  ╔══════════════ SCOREBOARD ══════════════╗" << RESET << endl;
        cout << BOLD_CYAN << "  ║" << RESET << "  " << BOLD_GREEN << "You: " << playerScore << RESET << "  |  " 
             << BOLD_RED << "Computer: " << computerScore << RESET << "  |  " 
             << BOLD_YELLOW << "Ties: " << ties << RESET << "     " << BOLD_CYAN << "║" << RESET << endl;
        cout << BOLD_CYAN << "  ╚════════════════════════════════════════╝" << RESET << endl;
        
        cout << "\n" << BOLD_WHITE << "  Choose your weapon:" << RESET << endl;
        cout << "  " << BOLD_BLUE << "1." << RESET << " 🪨  Rock" << endl;
        cout << "  " << BOLD_BLUE << "2." << RESET << " 📄  Paper" << endl;
        cout << "  " << BOLD_BLUE << "3." << RESET << " ✂️  Scissors" << endl;
        printBorder('-', 50);
        cout << BOLD_WHITE << "  Enter your choice (1-3): " << RESET;
        cin >> playerChoice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << BOLD_RED << "  ❌ Invalid input! Please enter a number." << RESET << endl;
            cout << YELLOW << "  Press Enter to continue..." << RESET;
            cin.get();
            continue;
        }
        
        if (playerChoice < 1 || playerChoice > 3) {
            cout << BOLD_RED << "  ❌ Invalid choice! Please try again." << RESET << endl;
            cout << YELLOW << "  Press Enter to continue..." << RESET;
            cin.ignore(10000, '\n');
            cin.get();
            continue;
        }
        
        computerChoice = rand() % 3 + 1;
        
        string choices[] = {"", "🪨  Rock", "📄  Paper", "✂️  Scissors"};
        string choiceIcons[] = {"", "🪨", "📄", "✂️"};
        
        cout << "\n";
        printBorder('=', 50);
        cout << BOLD_CYAN << "  You chose:      " << BOLD_YELLOW << choices[playerChoice] << RESET << endl;
        cout << BOLD_CYAN << "  Computer chose: " << BOLD_MAGENTA << choices[computerChoice] << RESET << endl;
        printBorder('=', 50);
        
        cout << "\n  " << BOLD_YELLOW << choiceIcons[playerChoice] << "  VS  " << choiceIcons[computerChoice] << RESET << endl;
        cout << "\n";
        
        if (playerChoice == computerChoice) {
            ties++;
            cout << BOLD_YELLOW << "  🤝 It's a TIE! 🤝" << RESET << endl;
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            playerScore++;
            cout << BOLD_GREEN << "  🎉 YOU WIN! 🎉" << RESET << endl;
            if (playerChoice == 1 && computerChoice == 3) {
                cout << GREEN << "  Rock crushes Scissors!" << RESET << endl;
            } else if (playerChoice == 2 && computerChoice == 1) {
                cout << GREEN << "  Paper covers Rock!" << RESET << endl;
            } else {
                cout << GREEN << "  Scissors cuts Paper!" << RESET << endl;
            }
        } else {
            computerScore++;
            cout << BOLD_RED << "  😞 COMPUTER WINS! 😞" << RESET << endl;
            if (computerChoice == 1 && playerChoice == 3) {
                cout << RED << "  Rock crushes Scissors!" << RESET << endl;
            } else if (computerChoice == 2 && playerChoice == 1) {
                cout << RED << "  Paper covers Rock!" << RESET << endl;
            } else {
                cout << RED << "  Scissors cuts Paper!" << RESET << endl;
            }
        }
        
        printBorder('-', 50);
        cout << "\n" << BOLD_WHITE << "  Play again? (y/n): " << RESET;
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    // Final scoreboard
    clearScreen();
    printBorder('=', 50);
    cout << BOLD_CYAN << "  FINAL SCOREBOARD" << RESET << endl;
    printBorder('=', 50);
    cout << BOLD_GREEN << "  You:      " << playerScore << RESET << endl;
    cout << BOLD_RED << "  Computer: " << computerScore << RESET << endl;
    cout << BOLD_YELLOW << "  Ties:     " << ties << RESET << endl;
    printBorder('=', 50);
    
    if (playerScore > computerScore) {
        cout << BOLD_GREEN << "  🏆 YOU ARE THE CHAMPION! 🏆" << RESET << endl;
    } else if (computerScore > playerScore) {
        cout << BOLD_RED << "  💻 Computer wins this time!" << RESET << endl;
    } else {
        cout << BOLD_YELLOW << "  🤝 It's a perfect tie!" << RESET << endl;
    }
    
    cout << YELLOW << "\n  Press Enter to return to menu..." << RESET;
    cin.ignore(10000, '\n');
    cin.get();
}
