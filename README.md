# skills-copilot-codespaces-vscode
My clone repository

## C++ Games Collection

A collection of easy-to-play C++ console games for entertainment and learning.

### Games Included

1. **Number Guessing Game** - Guess the secret number between 1 and 100
2. **Rock, Paper, Scissors** - Classic game against the computer
3. **Tic-Tac-Toe** - Two-player strategy game

### How to Build and Run

#### Prerequisites
- C++ compiler (g++ recommended)
- Make (optional, but recommended)

#### Using Make (Recommended)
```bash
# Compile the games
make

# Run the games
make run

# Clean build files
make clean
```

#### Manual Compilation
```bash
# Compile all files together
g++ -std=c++11 -Wall main.cpp number_guessing.cpp rock_paper_scissors.cpp tic_tac_toe.cpp -o games

# Run the program
./games
```

### How to Play

After running the program, you'll see a menu with game options. Simply enter the number corresponding to the game you want to play and follow the on-screen instructions.

Enjoy playing!
