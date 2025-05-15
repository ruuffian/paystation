#pragma once
#include "Menu/Option.h"
#include "Paystation.h"

namespace PaystationMenu {
class BuyParking : public Menu::Option {
private:
  Paystation *ps_;

public:
  BuyParking(Paystation *ps);
  void execute() override;
  ~BuyParking();
};
} // namespace PaystationMenu
