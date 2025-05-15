#include "BuyParking.h"
#include <iostream>

namespace PaystationMenu {
BuyParking::BuyParking(Paystation *ps) : MenuOption("Buy Parking"), ps_(ps) {}

void BuyParking::execute() {
  using namespace std;
  string receipt = ps_->buy();
  cout << receipt << '\n' << '\n';
}
BuyParking::~BuyParking() {}
} // namespace PaystationMenu
