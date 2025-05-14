#pragma once
typedef unsigned int Cents;
class PayStrategy {
public:
  /** Calculates time purchased by 'cents'. */
  virtual float calculate(Cents c) = 0;
};
