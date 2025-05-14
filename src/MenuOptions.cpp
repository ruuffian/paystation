#include "MenuOptions.h"
#include "Menu.h"
#include <iostream>
#include <limits>

void ExitMenuOption::execute() {
  std::cout << "'" << name_ << "' selected." << '\n';
}

void EchoMenuOption::execute() {
  std::cout << "'" << name_ << "' selected." << '\n';
}

SubmenuOption::SubmenuOption(const int id) : MenuOption<>(id, "Submenu") {
  sub_menu_ = new Menu();
  sub_menu_->addMenuOption(new EchoMenuOption(1));
  sub_menu_->addMenuOption(new ExitMenuOption(2));
}

void SubmenuOption::execute() {
  int should_exit = 0;
  std::cout << "Welcome to the sub-menu!" << '\n';
  while (!should_exit) {
    sub_menu_->print();
    int user_in;
    if (std::cin >> user_in) {
      MenuOption<> *selected_option = sub_menu_->selectMenuOption(user_in);
      if (selected_option == NULL) {
        std::cout << "Invalid input, please try again." << '\n';
        continue;
      }
      selected_option->execute();
      if (selected_option->getName() == "Exit")
        should_exit = 1;
    } else {
      std::cout << "Input failed. Please enter a valid menu option." << '\n';
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

/* Calling delete on a null pointer is ok :> */
SubmenuOption::~SubmenuOption() { delete sub_menu_; }
