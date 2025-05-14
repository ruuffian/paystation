#pragma once
#include "Menu/MenuOption.h"

namespace GenericMenuOption {
class Exit : public MenuOption {
public:
  Exit() : MenuOption("Exit") {}
  void execute() override;
  ~Exit();
};
} // namespace GenericMenuOption
