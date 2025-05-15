#pragma once
#include "Menu/MenuOption.h"
#include "Paystation.h"

namespace PaystationMenu {
class ReadMeter : public MenuOption {
private:
  Paystation *ps_;

public:
  ReadMeter(Paystation *ps);
  void execute() override;
  ~ReadMeter() = default;
};
} // namespace MenuOptions
