#pragma once
#include "Paystrategy.h"

/**
 * FixedLinearRate(0, .2) would yield 2 minutes of time per 5 cents spent.
 */
class FixedLinearRate : public PayStrategy {
private:
  float rate;
  unsigned int base;

public:
  /*
   * rate*cents + base
   */
  FixedLinearRate(const int b, const float r);

  float calculate(const int cents) override;
};
