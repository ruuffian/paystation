#pragma once
#include "Menu/Option.h"
#include "Paystation.h"
#include <sstream>

namespace PaystationMenu {
class InsertCoin : public Menu::Option {
private:
  Paystation *ps_;

public:
  InsertCoin(Paystation *ps);
  void execute(std::ostringstream &out) override;
  ~InsertCoin() = default;
};
} // namespace PaystationMenu
