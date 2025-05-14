#pragma once
#include "Menu.h"
#include "MenuOption.h"

class ExitMenuOption : public MenuOption<> {
public:
  ExitMenuOption(const int id) : MenuOption(id, "Exit") {}
  void execute() override;
};

class EchoMenuOption : public MenuOption<> {
public:
  EchoMenuOption(const int id) : MenuOption(id, "Echo") {}
  void execute() override;
};

class SubmenuOption : public MenuOption<> {
private:
  Menu *sub_menu_;

public:
  SubmenuOption(const int id);
  void execute();
  ~SubmenuOption();
};
