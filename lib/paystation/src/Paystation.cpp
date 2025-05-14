#include "Paystation.h"
#include <sstream>

Paystation::Paystation(PayStrategy *ps, std::string ap) {
  state_ = new PaystationState{0, 0};
  pay_strategy_ = ps;
  pin_ = ap;
}

Cents Paystation::insertCoin(const unsigned int &coin) {
  switch (coin) {
  case 1:
  case 5:
  case 10:
  case 25:
  case 100:
    state_->balance += coin;
    state_->timePurchased = pay_strategy_->calculate(state_->balance);
    return 0;
  default:
    return coin;
  }
}

PaystationState *Paystation::getState() { return state_; }

std::string Paystation::buy() {
  std::ostringstream s;
  s << "Total: " << state_->balance << '\n';
  s << "Minutes purchased: " << state_->timePurchased << '\n';
  state_->balance = 0;
  state_->timePurchased = 0;
  return s.str();
}

PayStrategy *Paystation::setPayStrategy(PayStrategy *ps) {
  /* Can be replaced with std::exchange() */
  auto old = pay_strategy_;
  pay_strategy_ = ps;
  return old;
}

bool Paystation::checkAdminPIN(const std::string &pin) { return pin == pin_; }
int Paystation::setAdminPIN(const std::string pin) {
  if (pin == pin_)
    return ERR_SAME_PIN;
  else {
    pin_ = pin;
    return 0;
  }
}
