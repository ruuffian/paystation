#include "ChangeAdminPIN.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

void disable_term_echo(termios &oldt) {
  tcgetattr(STDIN_FILENO, &oldt);
  termios newt = oldt;
  newt.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void enable_term_echo(termios &oldt) {
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void AdministratorMenu::ChangeAdminPIN::execute() {
  using namespace std;
  /* Very hacky and not-reusable way of switching off terminal echo for password
   * input.Also does not port to windows / macos.disable_term_echo(oldt);
   */
  termios oldt;
  disable_term_echo(oldt);
  /* Check Admin PIN */
  string current_pin;
  cout << "Current PIN: ";
  getline(std::cin, current_pin);
  if (ps_->checkAdminPIN(current_pin)) {
    string new_pin1;
    cout << '\n' << "New PIN: ";
    getline(std::cin, new_pin1);
    string new_pin2;
    cout << '\n' << "Verify New PIN: ";
    getline(std::cin, new_pin2);
    if (new_pin1 != new_pin2) {
      cout << '\n' << "PINs do not match." << '\n';
    } else {
      int res;
      if ((res = ps_->setAdminPIN(new_pin1)) == 0) {
        cout << '\n' << "Successfully updated PIN." << '\n';
      } else {
        res == ERR_SAME_PIN ? cout << '\n'
                                   << "Can't re-use PIN." << '\n'
                            : cout << '\n'
                                   << "Failed to update PIN." << '\n';
      }
    }
  } else {
    cout << '\n' << "Incorrect PIN." << '\n';
  }
  enable_term_echo(oldt);
}
