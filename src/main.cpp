#include <cctype>
#include <iostream>

#include "Menu.h"
#include "Menu/Headers/PaystationBalance.h"
#include "Menu/Options/AdminMenu.h"
#include "Menu/Options/BuyParking.h"
#include "Menu/Options/InsertCoin.h"
#include "Paystation.h"
#include "Paystrategies/FixedLinearRate.h"

int main() {
  /* Paystation Initializations
   * We initialize here to pass the Paystation class around by reference,
   * avoiding copies and allowing us to edit the guts via some setter methods.
   * This isn't the safest option, but CPP is all about "Trust the programmer",
   * and it's DEFINITELY better than copying a potentially very large class all
   * over the place
   */
  auto *flr{new FixedLinearRate(0, 0.4)};
  auto *ps{new Paystation(flr, "1234")};
  /* UI Initializations */
  auto main_menu{new Menu::Menu()};
  main_menu->setHeader(new PaystationMenu::PaystationBalance(ps));
  main_menu->addOption(new PaystationMenu::BuyParking(ps));
  main_menu->addOption(new PaystationMenu::InsertCoin(ps));
  main_menu->addOption(new PaystationMenu::AdminMenu(ps));
  /* Main loop */
  main_menu->render();
  std::cout << "Have a nice day!" << '\n';
  delete main_menu;
  return 0;
}
