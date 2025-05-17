#pragma once
#include "Menu.h"
#include "Menu/Option.h"
#include "Paystation.h"
#include <sstream>

namespace PaystationMenu {
class AdminMenu : public Menu::Option {
private:
  Menu::Menu *menu_;
  Paystation *ps_;

public:
  AdminMenu(Paystation *ps);
  void execute(std::ostringstream &out) override;
  ~AdminMenu();
};
} // namespace PaystationMenu
