#pragma once
#include "Menu/MenuOption.h"
#include <string>

namespace MenuOptions {

class Echo : public MenuOption {
public:
  Echo() : MenuOption("Echo") {}
  void execute() override;
  ~Echo();
};
} // namespace MenuOptions
