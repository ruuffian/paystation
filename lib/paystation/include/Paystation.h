#pragma once

#include "Paystrategy.h"
#include <optional>

typedef unsigned int Minutes;

struct PaystationState {
  Cents balance;
  Minutes timePurchased;
};

class Paystation {
private:
  struct PaystationState *ps;
  PayStrategy *rate;

public:
  Paystation(PayStrategy *rate);
  // Returns the balance, or -1 if coin is not accepted.
  std::optional<Cents> insertCoin(const Cents &);
  PaystationState *getState();
  //  Receipt buy(float price, int hours, int minutes);
  //  std::unordered_map<int, int> cancel();
  //  int empty();
  void setPayStrategy(PayStrategy *);
};
