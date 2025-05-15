#include "BuyParking.h"
#include <iostream>

namespace PaystationMenu {
BuyParking::BuyParking(Paystation *ps) : Menu::Option("Buy Parking"), ps_(ps) {}

void BuyParking::execute() {
  std::string receipt = ps_->buy();
  std::cout << receipt << '\n' << '\n';
}
BuyParking::~BuyParking() {}
} // namespace PaystationMenu
