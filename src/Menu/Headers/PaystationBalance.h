#pragma once
#include "Menu/Header.h"
#include "Paystation.h"

namespace PaystationMenu {
class PaystationBalance : public Menu::Header {
private:
  Paystation *ps_;

public:
  PaystationBalance(Paystation *ps);
  void render() override;
  ~PaystationBalance();
};
} // namespace PaystationMenu
