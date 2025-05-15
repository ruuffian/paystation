#pragma once
#include "Menu/Option.h"
#include "Paystation.h"

namespace AdministratorMenu {
class ChangeAdminPIN : public Menu::Option {
private:
  Paystation *ps_;

public:
  ChangeAdminPIN(Paystation *ps);
  void execute() override;
  ~ChangeAdminPIN() = default;
};
} // namespace AdministratorMenu
