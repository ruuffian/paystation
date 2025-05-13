#ifndef __FIXED_LINEAR_RATE_H
#define __FIXED_LINEAR_RATE_H
#include "paystrategy.h"

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
  FixedLinearRate(const unsigned int b, const float r);

  float calculate(const unsigned int cents) override;
};
#endif
