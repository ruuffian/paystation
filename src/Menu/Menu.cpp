#include "Menu.h"
#include "tui.h"
#include <iostream>
#include <limits>

namespace Menu {
void Menu::addOption(Option *mo) {
  if (mo) {
    if (options_.rbegin() == options_.rend()) {
      options_[1] = mo;
    } else {
      auto max = options_.rbegin()->first;
      options_[max + 1] = mo;
    }
  }
}

Option *Menu::processInput(const int &id) {
  auto lookup = options_.find(id);
  if (lookup != options_.end()) {
    return lookup->second;
  }
  return NULL;
}

void Menu::exit() { should_exit_ = 1; }

void Menu::runMenu() {
  should_exit_ = 0;
  while (!should_exit_) {
    clrscr();
    printHeader();
    printOptions();
    std::cout << '\n';
    int user_in;
    if (std::cin >> user_in) {
      Option *selected_option = processInput(user_in);
      if (selected_option) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        selected_option->execute();
      } else {
        std::cout << "Invalid menu option." << '\n';
      }
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

void Menu::printHeader() {
  if (header_) {
    header_->print();
  }
}

Header *Menu::setHeader(Header *h) {
  if (header_) {
    header_ = h;
    return NULL;
  } else {
    Header *old = header_;
    header_ = h;
    return old;
  }
}

void Menu::printOptions() {
  std::cout << "Please select an option:" << '\n';
  for (const auto &[id, option] : options_) {
    std::cout << '\t' << id << " : " << option->getName() << '\n';
  }
}

Menu::~Menu() {
  delete header_;
  for (auto &[key, option] : options_) {
    delete option;
  }
}
} // namespace Menu
