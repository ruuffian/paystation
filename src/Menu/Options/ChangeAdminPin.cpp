#include "ChangeAdminPin.h"
#include "Paystation.h"
#include "tui.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

namespace AdministratorMenu {
ChangeAdminPIN::ChangeAdminPIN(Paystation *ps)
    : Menu::Option("Change PIN"), ps_(ps) {}

void ChangeAdminPIN::execute(std::ostringstream &out) {
  /* Check Admin PIN */
  std::string current_pin;
  std::cout << "Current PIN: ";
  tui::disable_echo();
  std::getline(std::cin, current_pin);
  tui::enable_echo();
  if (ps_->checkAdminPIN(current_pin)) {
    std::string new_pin1;
    std::cout << '\n' << "New PIN: ";
    tui::disable_echo();
    std::getline(std::cin, new_pin1);
    tui::enable_echo();
    std::string new_pin2;
    std::cout << '\n' << "Verify New PIN: ";
    tui::disable_echo();
    std::getline(std::cin, new_pin2);
    tui::enable_echo();
    if (new_pin1 != new_pin2) {
      out << '\n' << "PINs do not match." << '\n';
    } else {
      int res;
      if ((res = ps_->setAdminPIN(new_pin1)) == 0) {
        out << '\n' << "Successfully updated PIN." << '\n';
      } else {
        res == ERR_SAME_PIN ? out << '\n'
                                  << "Can't re-use PIN." << '\n'
                            : out << '\n'
                                  << "Failed to update PIN." << '\n';
      }
    }
  } else {
    out << '\n' << "Incorrect PIN." << '\n';
  }
}
} // namespace AdministratorMenu
