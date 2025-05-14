#include "Echo.h"
#include <iostream>

void MenuOptions::Echo::execute() {
  using namespace std;
  cout << "Message: ";
  string in;
  cin.clear();
  cin.sync();
  getline(std::cin, in);
  cout << in << '\n';
}
MenuOptions::Echo::~Echo() {}
