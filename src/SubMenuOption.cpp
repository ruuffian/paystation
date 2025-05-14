#include "SubMenuOption.h"
#include "EchoMenuOption.h"
#include "ExitMenuOption.h"
#include "Menu.h"
#include <iostream>
#include <limits>

SubMenuOption::SubMenuOption(const int id) : MenuOption(id, "SubMenu") {
  sub_menu_ = new Menu();
  sub_menu_->addMenuOption(new EchoMenuOption(1));
  sub_menu_->addMenuOption(new ExitMenuOption(2));
}

void SubMenuOption::execute() {
  int should_exit = 0;
  std::cout << "Welcome to the sub-menu!" << '\n';
  while (!should_exit) {
    sub_menu_->print();
    int user_in;
    if (std::cin >> user_in) {
      MenuOption *selected_option = sub_menu_->selectMenuOption(user_in);
      if (selected_option == NULL) {
        std::cout << "Please enter a valid menu option." << '\n';
        continue;
      }
      selected_option->execute();
      if (selected_option->getName() == "Exit")
        should_exit = 1;
    } else {
      std::cout << "Please enter a valid menu option." << '\n';
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

/* Calling delete on a null pointer is ok :> */
SubMenuOption::~SubMenuOption() { delete sub_menu_; }
