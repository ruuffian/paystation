#include "ReadMeter.h"
#include <iostream>

namespace PaystationMenu {
ReadMeter::ReadMeter(Paystation *ps) : MenuOption("Read Meter"), ps_(ps) {}

void ReadMeter::execute() {
  using namespace std;
  PaystationState *state = ps_->getState();
  cout << "Money Inserted: " << state->balance << '\n';
  cout << "Time: " << state->timePurchased << '\n';
  cout << '\n' << '\n';
}
} // namespace PaystationMenu
