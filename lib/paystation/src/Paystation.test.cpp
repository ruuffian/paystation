#include "Paystation.h"
#include "Paystrategies/FixedLinearRate.h"
#include <gtest/gtest.h>

class PaystationTest : public testing::Test {
protected:
  PaystationTest() {
    rs_ = new FixedLinearRate(0, 0.4);
    ps_ = new Paystation(rs_, "1234");
  }
  FixedLinearRate *rs_;
  Paystation *ps_;
  ~PaystationTest() {
    delete ps_;
    delete rs_;
  }
};

TEST_F(PaystationTest, BalanceStartsAtZero) {
  EXPECT_EQ(ps_->getState()->balance, 0) << "Initial balance not 0.";
}

TEST_F(PaystationTest, InsertPenny) {
  EXPECT_EQ(ps_->insertCoin(1), 0);
  EXPECT_EQ(ps_->getState()->balance, 1)
      << "Inserting penny did not set balance to 1.";
}

TEST_F(PaystationTest, InsertNickel) {
  EXPECT_EQ(ps_->insertCoin(5), 0);
  EXPECT_EQ(ps_->getState()->balance, 5)
      << "Inserting nickel did not set balance to 5.";
}

TEST_F(PaystationTest, InsertDime) {
  EXPECT_EQ(ps_->insertCoin(10), 0);
  EXPECT_EQ(ps_->getState()->balance, 10)
      << "Inserting dime did not set balance to 10.";
}

TEST_F(PaystationTest, InsertQuarter) {
  EXPECT_EQ(ps_->insertCoin(25), 0);
  EXPECT_EQ(ps_->getState()->balance, 25)
      << "Inserting quarter did not set balance to 25.";
}

TEST_F(PaystationTest, InsertDollarCoin) {
  EXPECT_EQ(ps_->insertCoin(100), 0);
  EXPECT_EQ(ps_->getState()->balance, 100)
      << "Inserting dollar coin did not set balance to 100.";
}

TEST_F(PaystationTest, InsertInvalidCoin) {
  EXPECT_EQ(ps_->insertCoin(17), 17) << "Successfully inserted invalid coin.";
  EXPECT_EQ(ps_->getState()->balance, 0)
      << "Invalid coin changed station balance.";
}
