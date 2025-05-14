#include "Paystation.h"

Paystation::Paystation(PayStrategy *r) {
  ps = new PaystationState{0, 0};
  rate = r;
}

std::optional<Cents> Paystation::insertCoin(const unsigned int &coin) {
  switch (coin) {
  case 1:
  case 5:
  case 10:
  case 25:
  case 100:
    break;
  default:
    // Do something else
    break;
  }
  ps->balance += coin;
  return ps->balance;
}

PaystationState *Paystation::getState() { return ps; }

void Paystation::setPayStrategy(PayStrategy *ps) { rate = ps; }
