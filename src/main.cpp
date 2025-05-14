#include <cctype>
#include <iostream>

#include "Menu/Menu.h"
#include "MenuOptions/AdminMenu.h"
#include "MenuOptions/BuyParking.h"
#include "MenuOptions/Exit.h"
#include "MenuOptions/InsertCoin.h"
#include "MenuOptions/ReadMeter.h"
#include "Paystation.h"
#include "Paystrategies/FixedLinearRate.h"

void clrscr();

int main() {
  /* Paystation Initializations
   * We initialize here to pass the Paystation class around by reference,
   * avoiding copies and allowing us to edit the guts via some setter methods.
   * This isn't the safest option, but CPP is all about "Trust the programmer",
   * and it's DEFINITELY better than copying a potentially very large class all
   * over the place
   */
  FixedLinearRate *flr = new FixedLinearRate(0, 0.5);
  Paystation *ps = new Paystation(flr, "1234");
  /* UI Initializations */
  Menu *main_menu = new Menu();
  main_menu->addMenuOption(new PaystationMenu::ReadMeter(ps));
  main_menu->addMenuOption(new PaystationMenu::BuyParking(ps));
  main_menu->addMenuOption(new PaystationMenu::InsertCoin(ps));
  main_menu->addMenuOption(new GenericMenuOption::Exit());
  main_menu->addMenuOption(new PaystationMenu::AdminMenu(ps));
  clrscr();
  /* Main loop */
  std::cout << "Welcome to Paystation!" << '\n' << '\n';
  main_menu->runMenu();
  delete main_menu;
  return 0;
}

/* This is a one-line answer to an Operating Systems lab question :-) */
void clrscr() { std::cout << "\033[2J\033[1;1H"; }
