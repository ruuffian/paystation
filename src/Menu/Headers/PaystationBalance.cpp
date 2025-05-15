#include "PaystationBalance.h"
#include "Paystation.h"
#include <iostream>
#include <sstream>

/* Takes in a # of cents and formats it into $00.00 */
std::string format_money(int cents);

/* Takes in a # of minutes and formats as 00:00:00 */
std::string format_minutes(int min);

namespace PaystationMenu {
PaystationBalance::PaystationBalance(Paystation *ps)
    : Menu::Header(), ps_(ps) {}

void PaystationBalance::print() {
  PaystationState *ps_state = ps_->getState();
  std::cout << "Time: " << format_minutes(ps_state->timePurchased) << '\n';
  std::cout << "Cost: " << format_money(ps_state->balance) << '\n';
}
PaystationBalance::~PaystationBalance() {}
} // namespace PaystationMenu

std::string format_minutes(int min) {
  /* I think its possible to write a cool algorithm with a linked list of
   * 'weights' to calculate several layers of time (minutes -> hours ->
   * days...) but I am WAY too lazy to do that...
   */
  int days = min / (24*60);
  int hours = (min / 60) % 24;
  int minutes = min % (24*60);
  std::ostringstream total;
  total << days << ":";
  if (hours < 10) {
    total << "0";
  }
  total << hours << ":";
  if (minutes < 10) {
    total << "0";
  }
  total << minutes;
  return total.str();
}

std::string format_money(int cents) {
  std::ostringstream total;
  total << "$" << cents / 100;
  total << ".";
  int fractional = cents % 100;
  if (fractional < 10) {
    total << "0";
  }
  total << cents;
  return total.str();
}
