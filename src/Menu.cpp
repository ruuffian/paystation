#include "Menu.h"
#include <iostream>

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
