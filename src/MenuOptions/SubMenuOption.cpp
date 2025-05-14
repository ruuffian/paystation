#include "SubMenuOption.h"
#include "EchoMenuOption.h"
#include "ExitMenuOption.h"
#include "Menu.h"
#include <iostream>

SubMenuOption::SubMenuOption() : MenuOption("SubMenu") {
  sub_menu_ = new Menu();
  sub_menu_->addMenuOption(new EchoMenuOption());
  sub_menu_->addMenuOption(new ExitMenuOption());
}

void SubMenuOption::execute() {
  std::cout << "Welcome to the sub-menu!" << '\n';
  sub_menu_->runMenu();
}

/* Calling delete on a null pointer is ok :> */
SubMenuOption::~SubMenuOption() { delete sub_menu_; }
