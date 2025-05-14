#include "BuyParking.h"
#include <iostream>

void MenuOptions::BuyParking::execute() {
  using namespace std;
  string receipt = ps_->buy();
  cout << receipt << '\n' << '\n';
}
MenuOptions::BuyParking::~BuyParking() {}
