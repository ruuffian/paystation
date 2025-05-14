#pragma once
#include "MenuOption.h"
#include <map>

class Menu {
private:
  // We use a std::map because it's keys are sorted in Ascending order-
  // we rely on this fact to print the options in a deterministic order.
  std::map<int, MenuOption *> options_;
  int should_exit_ = 0;

public:
  void runMenu();
  /**
   * Adds an option to the options_ map.
   */
  void addMenuOption(MenuOption *c);
  MenuOption *processInput(const int &in);
  void print();
  ~Menu();
};
