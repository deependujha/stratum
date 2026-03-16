#include <gtest/gtest.h>
#include "math_utils.h"

// Demonstrate some basic assertions.
TEST(SampleTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  EXPECT_EQ(MathUtils::add(2, 3), 5);
}
