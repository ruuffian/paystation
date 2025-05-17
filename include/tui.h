#pragma once
#include <termios.h>
#include <unistd.h>

#define clrscr() std::cout << "\033[2J\033[1;1H";

namespace tui {
/* Clears the terminal window. */
void disable_echo();
void enable_echo();
} // namespace tui
