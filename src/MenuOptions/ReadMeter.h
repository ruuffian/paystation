#pragma once
#include "Menu/Option.h"
#include "Paystation.h"

namespace PaystationMenu {
class ReadMeter : public Menu::Option {
private:
  Paystation *ps_;

public:
  ReadMeter(Paystation *ps);
  void execute() override;
  ~ReadMeter() = default;
};
} // namespace PaystationMenu
