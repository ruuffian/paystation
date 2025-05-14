#pragma once
#include "MenuOption.h"

class ExitMenuOption : public MenuOption {
public:
  ExitMenuOption() : MenuOption("Exit") {}
  void execute() override;
  ~ExitMenuOption();
};
