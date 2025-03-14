#include "pch.h"
#include "14-LongestCommonPrefix.h"
TEST(Basics, LongestCommonPrefix) {
  EXPECT_EQ(longestCommonPrefix(std::vector<string>{"flower", "flow", "flight"}), "fl");
  EXPECT_EQ(longestCommonPrefix(std::vector<string>{"flower"}), "flower");
  EXPECT_EQ(longestCommonPrefix(std::vector<string>{"flower", "flowers"}), "flower");
  EXPECT_EQ(longestCommonPrefix(std::vector<string>{"dog", "racecar", "car"}), "");
}