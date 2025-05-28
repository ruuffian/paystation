#include "Paystrategies/FixedLinearRate.h"

/** r = minutes/cent */
FixedLinearRate::FixedLinearRate(int b, float r) {
  base = b;
  rate = r;
}

float FixedLinearRate::calculate(int cents) {
  /* Negative money doesn't exist */
  cents = (cents > 0) ? cents : 0;
  return (float(base) + rate * float(cents));
}
