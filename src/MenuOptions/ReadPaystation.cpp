#include "ReadPaystation.h"
#include <iostream>

void MenuOptions::ReadPaystation::execute() {
  using namespace std;
  PaystationState *state = ps_->getState();
  cout << "Money Inserted: " << state->balance << '\n';
  cout << "Time: " << state->timePurchased << '\n';
}
MenuOptions::ReadPaystation::~ReadPaystation() {}
