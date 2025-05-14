#pragma once
#include "Menu/MenuOption.h"
#include "Paystation.h"
#include <string>

namespace PaystationMenu {
class InsertCoin : public MenuOption {
private:
  Paystation *ps_;

public:
  InsertCoin(Paystation *ps) : MenuOption("Insert Coin"), ps_(ps) {}
  void execute() override;
  ~InsertCoin();
};
} // namespace MenuOptions


