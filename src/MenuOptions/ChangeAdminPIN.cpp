#include "ChangeAdminPIN.h"
#include "Paystation.h"
#include "tui.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

namespace AdministratorMenu {

ChangeAdminPIN::ChangeAdminPIN(Paystation *ps)
    : MenuOption("Change PIN"), ps_(ps) {}

void ChangeAdminPIN::execute() {
  using namespace std;
  /* Check Admin PIN */
  string current_pin;
  cout << "Current PIN: ";
  tui::disable_echo();
  getline(std::cin, current_pin);
  tui::enable_echo();
  if (ps_->checkAdminPIN(current_pin)) {
    string new_pin1;
    cout << '\n' << "New PIN: ";
    tui::disable_echo();
    getline(std::cin, new_pin1);
    tui::enable_echo();
    string new_pin2;
    cout << '\n' << "Verify New PIN: ";
    tui::disable_echo();
    getline(std::cin, new_pin2);
    tui::enable_echo();
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
}
} // namespace AdministratorMenu
