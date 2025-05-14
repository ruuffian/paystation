#include "EchoMenuOption.h"
#include <iostream>

void EchoMenuOption::execute() {
  using namespace std;
  cout << "Message: ";
  string in;
  cin.clear();
  cin.sync();
  getline(std::cin, in);
  cout << in << '\n';
}
EchoMenuOption::~EchoMenuOption() {}
