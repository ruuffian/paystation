#pragma once
#include "MenuOption.h"

class ExitMenuOption : public MenuOption {
public:
  ExitMenuOption(const int id) : MenuOption(id, "Exit"){}
  void execute();
};

class EchoMenuOption : public MenuOption {
public:
  EchoMenuOption(const int id) : MenuOption(id, "Echo") {}
  void execute();
};
