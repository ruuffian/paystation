#include "Menu.h"
#include "tui.h"
#include <iostream>
#include <limits>

namespace Menu {
void Menu::render() {
  should_exit_ = 0;
  while (!should_exit_) {
    clrscr();
    renderHeader();
    renderOptions();
    /* renderFooter(); */
    auto selected_option = readInput();
    if (selected_option) {
      /* Need to clear the newline left in stdin */
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      selected_option->execute();
      std::cout << '\n';
    }
  }
}

Option *Menu::readInput() {
  int user_in{0};
  if (std::cin >> user_in) {
    auto lookup{options_.find(user_in)};
    if (lookup != options_.end()) {
      return lookup->second;
    } else {
      std::cout << "Invalid menu option." << '\n';
    }
  } else {
    std::cout << "Invalid input.";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return nullptr;
}

void Menu::renderHeader() {
  if (header_) {
    header_->render();
  }
}

void Menu::renderOptions() {
  if (options_.size() > 0) {
    std::cout << "Please select an option:" << '\n';
    for (const auto &[id, option] : options_) {
      option->render(id);
    }
  } else {
    std::cout << "Empty list." << '\n';
  }
}

void Menu::addOption(Option *mo) {
  if (mo) {
    /* Empty map case */
    if (options_.rbegin() == options_.rend()) {
      options_[1] = mo;
    } else {
      auto max = options_.rbegin()->first;
      options_[max + 1] = mo;
    }
  }
}

Header *Menu::setHeader(Header *h) {
  if (header_) {
    header_ = h;
    return nullptr;
  } else {
    auto old = header_;
    header_ = h;
    return old;
  }
}

void Menu::exit() { should_exit_ = 1; }

Menu::~Menu() {
  delete header_;
  for (auto &[key, option] : options_) {
    delete option;
  }
}
} // namespace Menu
