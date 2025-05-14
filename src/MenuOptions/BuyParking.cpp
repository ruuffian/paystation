#include "BuyParking.h"
#include <iostream>

PaystationMenu::BuyParking::BuyParking(Paystation *ps)
    : MenuOption("Buy Parking"), ps_(ps) {}

void PaystationMenu::BuyParking::execute() {
  using namespace std;
  string receipt = ps_->buy();
  cout << receipt << '\n' << '\n';
}
PaystationMenu::BuyParking::~BuyParking() {}
