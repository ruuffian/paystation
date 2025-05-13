#ifndef __PAYSTRATEGIES_H
#define __PAYSTRATEGIES_H
class PayStrategy {
public:
  virtual float calculate(unsigned int minutes) = 0;
};
#endif
