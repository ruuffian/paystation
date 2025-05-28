#include "Paystrategies/FixedLinearRate.h"
#include <gtest/gtest.h>
#include <limits>

TEST(FixedLinearRateTest, Linear1) {
  /* 2 minutes costs 5 cents */
  FixedLinearRate rs = FixedLinearRate{0, 0.4};
  EXPECT_EQ(rs.calculate(0), 0);
  EXPECT_EQ(rs.calculate(5), 2);
  EXPECT_EQ(rs.calculate(10), 4);
  EXPECT_EQ(rs.calculate(-1), 0);
  EXPECT_EQ(rs.calculate(std::numeric_limits<int>::max()),
            2*(std::numeric_limits<int>::max() / 5));
  EXPECT_EQ(rs.calculate(std::numeric_limits<int>::min()), 0);
}
