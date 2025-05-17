#pragma once
class PayStrategy {
public:
  /** Calculates time purchased by 'cents'. */
  virtual float calculate(int c) = 0;
};
