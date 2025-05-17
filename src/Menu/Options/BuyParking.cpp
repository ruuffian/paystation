#include "BuyParking.h"
#include <sstream>

namespace PaystationMenu {
BuyParking::BuyParking(Paystation *ps) : Menu::Option("Buy Parking"), ps_(ps) {}

void BuyParking::execute(std::ostringstream &out) {
  std::string receipt = ps_->buy();
  out << receipt << '\n' << '\n';
}
BuyParking::~BuyParking() {}
} // namespace PaystationMenu
