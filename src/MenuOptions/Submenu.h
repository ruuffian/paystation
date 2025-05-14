#pragma once
#include "Menu/Menu.h"
#include "Menu/MenuOption.h"

namespace MenuOptions {
class Submenu : public MenuOption {
private:
  Menu *menu_;

public:
  Submenu();
  void execute();
  ~Submenu();
};
} // namespace MenuOptions
