#pragma once
#include "Menu.h"
#include "Menu/Option.h"

namespace GenericMenu {
class Exit : public Menu::Option {
private:
  Menu::Menu *menu_;

public:
  Exit(Menu::Menu *m);
  void execute() override;
  ~Exit() = default;
};
} // namespace GenericMenu
