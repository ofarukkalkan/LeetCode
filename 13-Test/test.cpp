#include "pch.h"
#include "13-RomanToInteger.h"

TEST(Basics, RomanToInteger) {
  EXPECT_EQ(romanToInt("MCMXCIV"), 1994);
  EXPECT_EQ(romanToInt("LVIII"), 58);
  EXPECT_EQ(romanToInt("III"), 3);
}