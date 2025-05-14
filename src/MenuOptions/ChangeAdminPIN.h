#pragma once
#include "MenuOption.h"
#include "Paystation.h"

namespace AdministratorMenu {
class ChangeAdminPIN : public MenuOption {
private:
  Paystation *ps_;

public:
  ChangeAdminPIN(Paystation *ps) : MenuOption("Change PIN"), ps_(ps) {}
  void execute() override;
  ~ChangeAdminPIN() = default;
};
} // namespace AdminMenu
