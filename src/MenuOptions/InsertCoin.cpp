#include "InsertCoin.h"
#include <iostream>
#include <limits>

void PaystationMenu::InsertCoin::execute() {
  using namespace std;
  cout << "Insert Coin: ";
  Cents coin;
  if (cin >> coin) {
    if (ps_->insertCoin(coin) != 0) {
      cout << "Coin not recognized." << '\n';
    }
  } else {
    cout << "Invalid input." << '\n';
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  cout << '\n' << '\n';
}
