#include <cctype>
#include <iostream>
#include <limits>

#include "Menu.h"
#include "MenuOptions.h"
// #include "paystation.h"

// #include "fixed_linear_rate.h"

struct UiState {
  short int shouldExit;
};

void clrscr();
// void printPaystationDisplay(Paystation *ps);

int main() {
  /* UI Initializations */
  Menu *main_menu = new Menu();
  main_menu->addMenuOption(new EchoMenuOption(1));
  main_menu->addMenuOption(new ExitMenuOption(2));
  UiState state = {0};
  /* Paystation Initializations
   * We initialize here to pass the Paystation class around by reference,
   * avoiding copies and allowing us to edit the guts via some setter methods.
   * This isn't the safest option, but CPP is all about "Trust the programmer",
   * and it's DEFINITELY better than copying a potentially very large class all
   * over the place
   * FixedLinearRate *flr = new FixedLinearRate(0, 0.5);
   * Paystation *ps = new Paystation(flr);
   */
  clrscr();

  /* Main loop */
  std::cout << "Welcome to Paystation!" << '\n' << '\n';
  while (!state.shouldExit) {
    main_menu->print();
    int user_in;
    if (std::cin >> user_in) {
      MenuOption<> *selected_option = main_menu->selectMenuOption(user_in);
      if (selected_option == NULL) {
        std::cout << "Invalid input, please try again." << '\n';
        continue;
      }
      selected_option->execute();
      /* Ew. */
      if (selected_option->getName() == "Exit")
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
