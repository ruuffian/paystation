#include "Menu.h"
#include <iostream>
#include <limits>

void Menu::addMenuOption(MenuOption *mo) {
  if (options_.rbegin() == options_.rend()) {
    options_[1] = mo;
  } else {
    auto max = options_.rbegin()->first;
    options_[max + 1] = mo;
  }
}

MenuOption *Menu::processInput(const int &id) {
  auto lookup = options_.find(id);
  if (lookup != options_.end()) {
    return lookup->second;
  }
  return NULL;
}

void Menu::runMenu() {
  while (!should_exit_) {
    print();
    int user_in;
    if (std::cin >> user_in) {
      MenuOption *selected_option = processInput(user_in);
      if (selected_option) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        selected_option->execute();
        /* Ew. */
        if (selected_option->getName() == "Exit") {
          should_exit_ = 1;
          continue;
        }
      } else {
        std::cout << "Invalid menu option." << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }
  }
}

void Menu::print() {
  std::cout << "Please select an option:" << '\n';
  for (const auto &[id, option] : options_) {
    std::cout << '\t' << id << " : " << option->getName() << '\n';
  }
}

Menu::~Menu() {
  for (auto &[key, option] : options_) {
    delete option;
  }
}
