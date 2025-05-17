#include "tui.h"

/* Enable or disable terminal echoing on UNIX. */
void toggle_tty_echo(bool enable);

namespace tui {
/* This is a one-line answer to an Operating Systems lab question :-) */
void disable_echo() { toggle_tty_echo(false); }
void enable_echo() { toggle_tty_echo(true); }
} // namespace tui

// TODO: Windows support
void toggle_tty_echo(bool enable = true) {
  termios t{};
  tcgetattr(STDIN_FILENO, &t);
  enable ? t.c_lflag |= ECHO : t.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);
}
