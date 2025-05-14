#include <iostream>
#include "ExitMenuOption.h"

void ExitMenuOption::execute() {
  std::cout << "Good-bye..." << '\n';
}

ExitMenuOption::~ExitMenuOption() {}
