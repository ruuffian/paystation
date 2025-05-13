#ifndef __PAYSTRATEGIES_H
#define __PAYSTRATEGIES_H
class PayStrategy {
public:
  /** Calculates time purchased by 'cents'. */
  virtual float calculate(unsigned int cents) = 0;
};
#endif
