#include <iostream>
#include <string>

#include "paystation.h"
#include "fixed_linear_rate.h"

void printMenu();
void clrscr();
void processInput(int &state, const std::string &in);

int main() {
  /* Initializations */
  int shouldExit = 0;
  std::string input;
  clrscr();
  FixedLinearRate *flr = new FixedLinearRate(20.1, 1.5);
  Paystation *ps = new Paystation(flr);

  /* Main loop */
  std::cout << "Welcome to Paystation!" << '\n' << '\n';
  while (!shouldExit) {
    printMenu();
    std::getline(std::cin, input);
    processInput(shouldExit, input);
  }
  return 0;
}

void printMenu() {
  using namespace std;
  cout << "Please select an option:" << '\n';
  cout << "\t(P)urchase parking" << '\n';
  cout << "\t(E)xit" << '\n';
}

void processInput(int &shouldExit, const std::string &in) {
  if (in == "E" || in == "e") {
    std::cout << "Good-bye..." << '\n';
    shouldExit = 1;
    return;
  }
  std::cout << in << std::endl;
}

void clrscr() { std::cout << "\033[2J\033[1;1H"; }
