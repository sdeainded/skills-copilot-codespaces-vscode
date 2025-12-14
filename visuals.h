#ifndef VISUALS_H
#define VISUALS_H

#include <iostream>
#include <string>

// ANSI Color Codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Bold Colors
#define BOLD_RED     "\033[1;31m"
#define BOLD_GREEN   "\033[1;32m"
#define BOLD_YELLOW  "\033[1;33m"
#define BOLD_BLUE    "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN    "\033[1;36m"
#define BOLD_WHITE   "\033[1;37m"

// Background Colors
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"

// Utility functions
inline void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

inline void printBorder(char c = '=', int length = 50) {
    std::cout << BOLD_CYAN;
    for (int i = 0; i < length; i++) {
        std::cout << c;
    }
    std::cout << RESET << std::endl;
}

inline void printTitle(const std::string& title) {
    clearScreen();
    printBorder('=', 50);
    std::cout << BOLD_YELLOW << "  " << title << RESET << std::endl;
    printBorder('=', 50);
}

#endif
