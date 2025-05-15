#include "Paystrategies/FixedLinearRate.h"

/** r = minutes/cent */
FixedLinearRate::FixedLinearRate(unsigned int b, float r) {
  base = b;
  rate = r;
}

float FixedLinearRate::calculate(unsigned int cents) {
  return (float(base) + rate * float(cents));
}
