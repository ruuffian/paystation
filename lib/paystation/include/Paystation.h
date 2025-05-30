#pragma once

#include "Paystrategy.h"
#include <string>

#define ERR_SAME_PIN (1 << 0)
#define ERR_UNKNOWN (2 << 0)

struct PaystationState {
  int balance;
  int timePurchased;
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
  int insertCoin(const int &);
  /**
   * Returns a copy of the Paystation state. Editing this memory is considered
   * undefined behavior.
   */
  struct PaystationState *getState();
  /** This will have to use exceptions once it uses the Receipt interface in
   * case of I/O failures (printer out of paper etc) */
  std::string buy();
  //  cancel();
  //  int empty();
  /**
   * Sets a new paystrategy and returns the old one.
   */
  PayStrategy *setPayStrategy(PayStrategy *);
  bool checkAdminPIN(const std::string &pin);
  /**
   * Sets pin_ to pin. Returns 0 if successful, or ERR_SAME_PIN if the new pin
   * is the same as the old one.
   */
  int setAdminPIN(const std::string pin);
};
