#pragma once
#include "MenuOption.h"
#include "Paystation.h"

namespace AdministratorMenu {
class ChangeAdminPIN : public MenuOption {
private:
  Paystation *ps_;

public:
  ChangeAdminPIN(Paystation *ps);
  void execute() override;
  ~ChangeAdminPIN() = default;
};
} // namespace AdministratorMenu
