#pragma once
#include "Menu/MenuOption.h"
#include "Paystation.h"
#include <string>

namespace MenuOptions {
class ReadMeter : public MenuOption {
private:
  Paystation *ps_;

public:
  ReadMeter(Paystation *ps) : MenuOption("Read Meter"), ps_(ps) {}
  void execute() override;
  ~ReadMeter();
};
} // namespace MenuOptions
