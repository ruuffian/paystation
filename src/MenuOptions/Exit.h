#pragma once
#include "Menu.h"
#include "MenuOption.h"

namespace GenericMenuOption {
class Exit : public MenuOption {
private:
  Menu *menu_;

public:
  Exit(Menu *m);
  void execute() override;
  ~Exit() = default;
};
} // namespace GenericMenuOption
