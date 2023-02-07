
/**
 * @file runner.cc
 * @author M Zaki 
 * @brief test driver for multimap container test
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright M Zaki (c) 2022
 * 
 */

#include <iostream>
#include "gtest/gtest.h"
#include "multimap.tests.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

