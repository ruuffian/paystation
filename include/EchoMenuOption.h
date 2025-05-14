#pragma once
#include "MenuOption.h"
#include <string>

class EchoMenuOption : public MenuOption {
public:
  EchoMenuOption() : MenuOption("Echo") {}
  void execute() override;
  ~EchoMenuOption();
};
