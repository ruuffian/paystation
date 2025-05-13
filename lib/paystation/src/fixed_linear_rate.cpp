#include "fixed_linear_rate.h"

FixedLinearRate::FixedLinearRate(unsigned int b, float r) {
  base = b;
  rate = r;
}

float FixedLinearRate::calculate(unsigned int cents) {
  return (base + rate*cents);
}
