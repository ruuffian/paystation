#pragma once
#include "Menu/Menu.h"
#include "Menu/MenuOption.h"

class SubMenuOption : public MenuOption {
private:
  Menu *sub_menu_;

public:
  SubMenuOption();
  void execute();
  ~SubMenuOption();
};
