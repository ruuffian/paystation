#ifndef __FIXED_LINEAR_RATE_H
#define __FIXED_LINEAR_RATE_H
#include "paystrategy.h"

class FixedLinearRate : public PayStrategy {
private:
  float rate;
  float base;

public:
  /**
   * Calculates time based on a set base charge and a linear rate.
   */
  FixedLinearRate(const float base, const float r);

  float calculate(const unsigned int time) override;
};
#endif
