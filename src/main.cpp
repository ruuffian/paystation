#include <cctype>
#include <iostream>
#include <limits>

#include "EchoMenuOption.h"
#include "ExitMenuOption.h"
#include "Menu.h"
#include "SubMenuOption.h"
// #include "paystation.h"

// #include "fixed_linear_rate.h"

void clrscr();
// void printPaystationDisplay(Paystation *ps);

int main() {
  /* UI Initializations */
  Menu *main_menu = new Menu();
  /* I should stop relying on explicit command IDs and couple it to order of
   * adding. That can be clearly documented and should be an easy constraint for
   * a client. Explicitly giving an id requires changes to multiple lines just
   * to add 1 option.
   */
  main_menu->addMenuOption(new EchoMenuOption(1));
  main_menu->addMenuOption(new SubMenuOption(2));
  main_menu->addMenuOption(new ExitMenuOption(3));
  int should_exit{0};
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
  while (!should_exit) {
    main_menu->print();
    int user_in;
    if (std::cin >> user_in) {
      MenuOption *selected_option = main_menu->processInput(user_in);
      if (selected_option == NULL) {
        std::cout << "Invalid input, please try again." << '\n';
        continue;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      selected_option->execute();
      /* Ew. */
      if (selected_option->getName() == "Exit")
        should_exit = 1;
    } else {
      std::cout << "Please enter a valid menu option." << '\n';
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  delete main_menu;
  return 0;
}

/* This is a one-line answer to an Operating Systems lab question :-) */
void clrscr() { std::cout << "\033[2J\033[1;1H"; }
