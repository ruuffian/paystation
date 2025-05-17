#pragma once
#include "Menu.h"
#include "Menu/Option.h"
#include <sstream>

namespace GenericMenu {
class Exit : public Menu::Option {
private:
  Menu::Menu *menu_;

public:
  Exit(Menu::Menu *m);
  void execute(std::ostringstream &out) override;
  ~Exit() = default;
};
} // namespace GenericMenu
