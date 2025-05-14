#include "ReadMeter.h"
#include <iostream>

void MenuOptions::ReadMeter::execute() {
  using namespace std;
  PaystationState *state = ps_->getState();
  cout << "Money Inserted: " << state->balance << '\n';
  cout << "Time: " << state->timePurchased << '\n';
  cout << '\n' << '\n';
}
MenuOptions::ReadMeter::~ReadMeter() {}
