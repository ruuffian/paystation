#ifndef __PAYSTATION_H
#define __PAYSTATION_H
#include <memory>
#include <unordered_map>

#include "paystrategy.h"
#include "receipt.h"

class Paystation {
public:
  Paystation(PayStrategy *rate);
  // Returns the balance, or -1 if coin is not accepted.
  int insertCoin(const int &);
  void readDisplay();
  Receipt buy(float price, int hours, int minutes);
  std::unordered_map<int, int> cancel();
  int empty();
  void setPayStrategy(PayStrategy *);

private:
  unsigned int balance = 0;
  std::unordered_map<int, int> inserted_coins{};
  std::unique_ptr<PayStrategy> rate;
};
#endif
