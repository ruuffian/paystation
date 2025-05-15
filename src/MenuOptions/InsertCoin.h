#pragma once
#include "Menu/MenuOption.h"
#include "Paystation.h"

namespace PaystationMenu {
class InsertCoin : public MenuOption {
private:
  Paystation *ps_;

public:
  InsertCoin(Paystation *ps);
  void execute() override;
  ~InsertCoin() = default;
};
} // namespace PaystationMenu
