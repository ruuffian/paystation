#include "InsertCoin.h"
#include <iostream>
#include <limits>

namespace PaystationMenu {
InsertCoin::InsertCoin(Paystation *ps) : Menu::Option("Insert Coin"), ps_(ps) {}

void InsertCoin::execute(std::ostringstream &out) {
  using namespace std;
  cout << "Insert Coin: ";
  int coin;
  if (cin >> coin) {
    if (ps_->insertCoin(coin) != 0) {
      out << "Coin not recognized." << '\n';
    }
  } else {
    out << "Invalid input." << '\n';
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}
} // namespace PaystationMenu
