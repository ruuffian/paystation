#include <utility>

class Receipt {

public:
  Receipt(float total);
  void printReceipt();

private:
  float total;
  std::pair<int, int> time_purchased;
};
