#pragma once
#include "Menu/MenuOption.h"
#include "Paystation.h"
#include <string>

namespace MenuOptions {
class BuyParking : public MenuOption {
private:
  Paystation *ps_;

public:
  BuyParking(Paystation *ps) : MenuOption("Buy Parking"), ps_(ps) {}
  void execute() override;
  ~BuyParking();
};
} // namespace MenuOptions
