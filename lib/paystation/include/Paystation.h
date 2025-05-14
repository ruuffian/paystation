#pragma once

#include "Paystrategy.h"
#include <string>

typedef unsigned int Minutes;

struct PaystationState {
  Cents balance;
  Minutes timePurchased;
};

class Paystation {
private:
  struct PaystationState *state_;
  PayStrategy *pay_strategy_;
  std::string pin_;

public:
  Paystation(PayStrategy *rate, std::string admin_pin);
  /**
   * Accepts a non-negative coin value, validates it is American currency, and
   * adds it to ps_->balance. Additionally, ps_->timePurchased is recalculated.
   * Returns 0 when successfuly and the inserted amount when not.
   */
  Cents insertCoin(const Cents &);
  /**
   * Returns a copy of the Paystation state. Editing this memory is considered
   * undefined behavior.
   */
  struct PaystationState *getState();
  std::string buy();
  //  cancel();
  //  int empty();
  /**
   * Sets a new paystrategy and returns the old one.
   */
  PayStrategy *setPayStrategy(PayStrategy *);
};
