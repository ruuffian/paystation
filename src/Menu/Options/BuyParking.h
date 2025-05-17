#pragma once
#include "Menu/Option.h"
#include "Paystation.h"
#include <sstream>

namespace PaystationMenu {
class BuyParking : public Menu::Option {
private:
  Paystation *ps_;

public:
  BuyParking(Paystation *ps);
  void execute(std::ostringstream &out) override;
  ~BuyParking();
};
} // namespace PaystationMenu
