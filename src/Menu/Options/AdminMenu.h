#pragma once
#include "Menu.h"
#include "Menu/Option.h"
#include "Paystation.h"

namespace PaystationMenu {
class AdminMenu : public Menu::Option {
private:
  Menu::Menu *menu_;
  Paystation *ps_;

public:
  AdminMenu(Paystation *ps);
  void execute() override;
  ~AdminMenu();
};
} // namespace PaystationMenu
