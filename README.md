# skills-copilot-codespaces-vscode
My clone repository

## C++ Games Collection

A collection of easy-to-play C++ console games with colorful, interactive visuals for entertainment and learning.

### ✨ Features

- 🎨 **Colorful Interface** - Beautiful ANSI color-coded menus and game boards
- 📊 **Score Tracking** - Keep track of wins, losses, and ties across multiple rounds
- 🎯 **Interactive Gameplay** - Engaging visual feedback and animations
- 🧹 **Clean UI** - Clear screen updates for smooth gameplay experience

### Games Included

1. **Number Guessing Game** 🎯 - Guess the secret number between 1 and 100 with helpful hints and performance ratings
2. **Rock, Paper, Scissors** ✊📄✂️ - Classic game against the computer with score tracking and visual matchups
3. **Tic-Tac-Toe** ⭕❌ - Two-player strategy game with colorful board and win tracking

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

After running the program, you'll see a colorful menu with game options. Simply enter the number corresponding to the game you want to play and follow the on-screen instructions.

The games feature:
- 🌈 **Color-coded players and elements** (X in red, O in blue, etc.)
- 📊 **Live scoreboards** showing wins, losses, and ties
- 💬 **Visual feedback** with emojis and colored text
- ✅ **Input validation** to ensure smooth gameplay

Enjoy playing!
