#pragma once
#include "Menu/MenuOption.h"

class ExitMenuOption : public MenuOption {
public:
  ExitMenuOption() : MenuOption("Exit") {}
  void execute() override;
  ~ExitMenuOption();
};
