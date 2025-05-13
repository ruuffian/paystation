#include "paystation.h"
#include <iostream>
#include <memory>

Paystation::Paystation(PayStrategy *r) {
  rate = std::unique_ptr<PayStrategy>(r);
}

int Paystation::insertCoin(const int &coin) {
  switch (coin) {
  case 1:
  case 5:
  case 10:
  case 25:
  case 100:
    break;
  default:
    return -1;
  }
  balance += coin;
  return balance;
}

void Paystation::readDisplay() {
  std::cout << "Balance: " << balance << '\n';
  std::cout << "Time: " << rate->calculate(balance) << '\n';
}

void Paystation::setPayStrategy(PayStrategy *ps) {
  rate = std::unique_ptr<PayStrategy>(ps);
}
