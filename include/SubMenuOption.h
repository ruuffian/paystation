#pragma once
#include "Menu.h"
#include "MenuOption.h"

class SubMenuOption : public MenuOption {
private:
  Menu *sub_menu_;

public:
  SubMenuOption(const int id);
  void execute();
  ~SubMenuOption();
};
