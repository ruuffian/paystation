#include "AdminMenu.h"
#include "ChangeAdminPIN.h"
#include "Exit.h"
#include <iostream>

PaystationMenu::AdminMenu::AdminMenu(Paystation *ps)
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

void PaystationMenu::AdminMenu::execute() {
  using namespace std;
  /* Check Admin PIN */
  string pin;
  cout << "PIN: ";
  getline(std::cin, pin);
  if (ps_->checkAdminPIN(pin)) {
    menu_->runMenu();
  } else {
    cout << "Incorrect PIN." << '\n';
  }
}

/* Calling delete on a null pointer is ok :> */
PaystationMenu::AdminMenu::~AdminMenu() { delete menu_; }
