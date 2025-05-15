#include "AdminMenu.h"
#include "ChangeAdminPIN.h"
#include "Exit.h"
#include <iostream>
#include <tui.h>

namespace PaystationMenu {
AdminMenu::AdminMenu(Paystation *ps)
    : MenuOption("Admin Menu"), menu_(new Menu()), ps_(ps) {
  /* Empty */
  menu_->addMenuOption(NULL);
  /* Change Rate Strategy (another sub menu) */
  menu_->addMenuOption(NULL);
  /* Change admin PIN */
  menu_->addMenuOption(new AdministratorMenu::ChangeAdminPIN(ps_));
  /* Reboot */
  menu_->addMenuOption(NULL);
  /* Exit */
  menu_->addMenuOption(new GenericMenuOption::Exit(menu_));
}

void AdminMenu::execute() {
  using namespace std;
  /* Check Admin PIN */
  string pin;
  cout << "PIN: ";
  tui::disable_echo();
  getline(std::cin, pin);
  tui::enable_echo();
  if (ps_->checkAdminPIN(pin)) {
    menu_->runMenu();
  } else {
    cout << "Incorrect PIN." << '\n';
  }
}

/* Calling delete on a null pointer is ok :> */
AdminMenu::~AdminMenu() { delete menu_; }
} // namespace PaystationMenu
