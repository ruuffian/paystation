#include "MenuOptions.h"
#include <iostream>

void ExitMenuOption::execute() {
  std::cout << "'" << name_ << "' selected." << '\n';
}

void EchoMenuOption::execute() {
  std::cout << "'" << name_ << "' selected." << '\n';
}
