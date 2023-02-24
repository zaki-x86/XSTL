
#include <gtest/gtest.h>
#include <xstl/algorithm.hpp>

TEST(TmpTest, CheckValues)
{
  EXPECT_TRUE(xstl::algorithm_test1() == 1);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
