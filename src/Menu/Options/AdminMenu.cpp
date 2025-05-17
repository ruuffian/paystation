#include "AdminMenu.h"
#include "ChangeAdminPin.h"
#include "Exit.h"
#include <iostream>
#include <sstream>
#include <tui.h>

namespace PaystationMenu {
AdminMenu::AdminMenu(Paystation *ps)
    : Menu::Option("Admin Menu"), menu_(new Menu::Menu()), ps_(ps) {
  /* Empty */
  menu_->addOption(NULL);
  /* Change Rate Strategy (another sub menu) */
  menu_->addOption(NULL);
  /* Change admin PIN */
  menu_->addOption(new AdministratorMenu::ChangeAdminPIN(ps_));
  /* Reboot */
  menu_->addOption(NULL);
  /* Exit (maybe exit the entire machine including the parent menu?) */
  menu_->addOption(new GenericMenu::Exit(menu_));
}

void AdminMenu::execute(std::ostringstream &out) {
  using namespace std;
  /* Check Admin PIN */
  string pin;
  cout << "PIN: ";
  tui::disable_echo();
  getline(std::cin, pin);
  tui::enable_echo();
  if (ps_->checkAdminPIN(pin)) {
    std::ostringstream parent{};
    menu_->render(parent);
  } else {
    out << "Incorrect PIN." << '\n';
  }
}

/* Calling delete on a null pointer is ok :> */
AdminMenu::~AdminMenu() { delete menu_; }
} // namespace PaystationMenu
