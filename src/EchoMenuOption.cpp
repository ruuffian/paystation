#include <iostream>
#include "EchoMenuOption.h"

void EchoMenuOption::execute() {
  std::cout << "'" << name_ << "' selected." << '\n';
}
EchoMenuOption::~EchoMenuOption() {}
