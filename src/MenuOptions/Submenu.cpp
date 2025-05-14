#include "Submenu.h"
#include "Echo.h"
#include "Exit.h"
#include "Menu.h"
#include <iostream>

MenuOptions::Submenu::Submenu() : MenuOption("Submenu") {
  menu_ = new Menu();
  menu_->addMenuOption(new MenuOptions::Echo());
  menu_->addMenuOption(new MenuOptions::Exit());
}

void MenuOptions::Submenu::execute() {
  std::cout << "Welcome to the sub-menu!" << '\n';
  menu_->runMenu();
}

/* Calling delete on a null pointer is ok :> */
MenuOptions::Submenu::~Submenu() { delete menu_; }
