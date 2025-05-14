#pragma once
#include "Menu/MenuOption.h"
#include "Paystation.h"
#include <string>

namespace MenuOptions {
class ReadPaystation : public MenuOption {
private:
  Paystation *ps_;

public:
  ReadPaystation(Paystation *ps) : MenuOption("ReadPaystation"), ps_(ps) {}
  void execute() override;
  ~ReadPaystation();
};
} // namespace MenuOptions
