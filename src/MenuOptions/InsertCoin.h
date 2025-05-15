#pragma once
#include "Menu/Option.h"
#include "Paystation.h"

namespace PaystationMenu {
class InsertCoin : public Menu::Option {
private:
  Paystation *ps_;

public:
  InsertCoin(Paystation *ps);
  void execute() override;
  ~InsertCoin() = default;
};
} // namespace PaystationMenu
