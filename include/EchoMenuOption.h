#pragma once
#include "MenuOption.h"

class EchoMenuOption : public MenuOption {
public:
  EchoMenuOption(const int id) : MenuOption(id, "Echo") {}
  void execute() override;
  ~EchoMenuOption();
};
