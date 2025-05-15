#pragma once
#include <termios.h>
#include <unistd.h>

namespace tui {
/* Clears the terminal window. */
void clrscr();
void disable_echo();
void enable_echo();
} // namespace tui
