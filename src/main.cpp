#include <cctype>
#include <iostream>
#include <limits>
#include <string>

#include "Menu.h"
#include "MenuOptions.h"
// #include "paystation.h"

// #include "fixed_linear_rate.h"

struct UiState {
  short int shouldExit;
  std::string input;
};

void clrscr();
// void printPaystationDisplay(Paystation *ps);

int main() {
  /* UI Initializations */
  Menu *menu = new Menu();
  menu->addMenuOption(new ExitMenuOption(1));
  menu->addMenuOption(new EchoMenuOption(2));
  UiState state = {0, ""};
  /* Paystation Initializations */
  /*
  FixedLinearRate *flr = new FixedLinearRate(0, 0.5);
  Paystation *ps = new Paystation(flr);
  */
  clrscr();

  /* Main loop */
  int choice = -1;
  std::cout << "Welcome to Paystation!" << '\n' << '\n';
  while (!state.shouldExit) {
    // printPaystationDisplay(ps);
    menu->print();
    // What happens when a non-integer is entered?
    if (std::cin >> choice) {
      MenuOption *mo = menu->selectMenuOption(choice);
      if (mo == NULL) {
        std::cout << "Invalid input, please try again." << '\n';
        continue;
      }
      mo->execute();
      /* Ew. */
      if (mo->getName() == "Exit")
        state.shouldExit = 1;
    } else {
      std::cout << "Input failed. Please enter a valid menu option." << '\n';
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return 0;
}

/* This is a one-line answer to an Operating Systems lab question :-) */
void clrscr() { std::cout << "\033[2J\033[1;1H"; }

/*void printPaystationDisplay(Paystation *ps) {
  using namespace std;
  PaystationState *pss = ps->getState();
  cout << "Money Inserted: " << pss->balance << '\n';
  cout << "Minutes: " << pss->timePurchased << '\n';
}*/
