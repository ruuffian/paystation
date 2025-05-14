#include <iostream>
#include "Exit.h"

void GenericMenuOption::Exit::execute() {
  std::cout << "Good-bye..." << '\n';
}

GenericMenuOption::Exit::~Exit() {}
