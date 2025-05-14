#pragma once
#include "Menu/Menu.h"
#include "Menu/MenuOption.h"
#include "Paystation.h"

namespace PaystationMenu {
class AdminMenu : public MenuOption {
private:
  Menu *menu_;
  Paystation *ps_;

public:
  AdminMenu(Paystation *ps);
  void execute() override;
  ~AdminMenu();
};
} // namespace PaystationMenu
