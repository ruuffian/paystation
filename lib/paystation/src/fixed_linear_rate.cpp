#include "fixed_linear_rate.h"

FixedLinearRate::FixedLinearRate(float b, float r) { rate = r; base = b; }

float FixedLinearRate::calculate(unsigned int minutes) {
  return (float)minutes * rate;
}
