#include <iostream>
#include "Exit.h"

void MenuOptions::Exit::execute() {
  std::cout << "Good-bye..." << '\n';
}

MenuOptions::Exit::~Exit() {}
