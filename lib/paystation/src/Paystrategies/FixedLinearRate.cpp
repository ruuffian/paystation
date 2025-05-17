#include "Paystrategies/FixedLinearRate.h"

/** r = minutes/cent */
FixedLinearRate::FixedLinearRate(int b, float r) {
  base = b;
  rate = r;
}

float FixedLinearRate::calculate(int cents) {
  return (float(base) + rate * float(cents));
}
