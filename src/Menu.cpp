#include "Menu.h"
#include <iostream>
#include <limits>

MenuOption *Menu::addMenuOption(MenuOption *mo) {
  auto lookup = options_.find(mo->getId());
  options_[mo->getId()] = mo;
  if (lookup != options_.end()) {
    return lookup->second;
  }
  return mo;
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
      if (selected_option == NULL) {
        std::cout << "Invalid input, please try again." << '\n';
        continue;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      selected_option->execute();
      /* Ew. */
      if (selected_option->getName() == "Exit")
        should_exit_ = 1;
    } else {
      std::cout << "Please enter a valid menu option." << '\n';
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

void Menu::print() {
  using namespace std;
  cout << "Please select an option:" << '\n';
  for (const auto &[id, option] : options_) {
    cout << '\t' << id << " : " << option->getName() << '\n';
  }
}

Menu::~Menu() {
  for (auto &[key, option] : options_) {
    delete option;
  }
}
