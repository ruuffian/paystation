#pragma once
#include "Menu/MenuOption.h"

namespace MenuOptions {
class Exit : public MenuOption {
public:
  Exit() : MenuOption("Exit") {}
  void execute() override;
  ~Exit();
};
} // namespace MenuOptions
