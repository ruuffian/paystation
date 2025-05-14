#pragma once
#include "Menu.h"
#include "MenuOption.h"

namespace GenericMenuOption {
class Exit : public MenuOption {
private:
  Menu *menu_;

public:
  Exit(Menu *m) : MenuOption("Exit"), menu_(m) {}
  void execute() override;
  ~Exit();
};
} // namespace GenericMenuOption
