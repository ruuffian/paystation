#include <cctype>
#include <iostream>

#include "Menu/Menu.h"
#include "MenuOptions/Echo.h"
#include "MenuOptions/Exit.h"
#include "MenuOptions/Submenu.h"
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
  main_menu->addMenuOption(new MenuOptions::Echo());
  main_menu->addMenuOption(new MenuOptions::Submenu());
  main_menu->addMenuOption(new MenuOptions::Exit());
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
  main_menu->runMenu();
  delete main_menu;
  return 0;
}

/* This is a one-line answer to an Operating Systems lab question :-) */
void clrscr() { std::cout << "\033[2J\033[1;1H"; }
