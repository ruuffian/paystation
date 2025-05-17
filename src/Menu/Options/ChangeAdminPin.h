#pragma once
#include "Menu/Option.h"
#include "Paystation.h"
#include <sstream>

namespace AdministratorMenu {
class ChangeAdminPIN : public Menu::Option {
private:
  Paystation *ps_;

public:
  ChangeAdminPIN(Paystation *ps);
  void execute(std::ostringstream &out) override;
  ~ChangeAdminPIN() = default;
};
} // namespace AdministratorMenu
