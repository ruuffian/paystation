#include "InsertCoin.h"
#include <iostream>
#include <limits>

void MenuOptions::InsertCoin::execute() {
  using namespace std;
  cout << "Insert Coin: ";
  Cents coin;
  if (cin >> coin) {
    if (ps_->insertCoin(coin) != 0) {
      cout << "Coin not recognized." << '\n';
    }
  } else {
    cout << "Invalid input." << '\n';
  }
  cout << '\n' << '\n';
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
MenuOptions::InsertCoin::~InsertCoin() {}
