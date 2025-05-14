#pragma once
#include "MenuOption.h"
#include <map>

class Menu {
private:
  // We use a std::map because it's keys are sorted in Ascending order-
  // we rely on this fact to print the options in a deterministic order.
  std::map<int, MenuOption *> options_;

public:
  /**
   * Adds an option to the options_ map.
   * If a MenuOption exists with the same id, overwrite it and return it.
   * Otherwise, insert it and return the new MenuOption
   */
  MenuOption *addMenuOption(MenuOption *c);
  MenuOption *selectMenuOption(const int &in);
  void print();
  ~Menu();
};
