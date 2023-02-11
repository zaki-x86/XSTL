/**
 * @file runner.cc
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "gtest/gtest.h"

#include "container/array.test/array.tests.h"
#include "container/vector.test/vector.tests.h"
#include "container/deque.test/deque.tests.h"
#include "container/forward_list.test/forward_list.tests.h"
#include "container/list.test/list.tests.h"
#include "container/set.test/set.tests.h"
#include "container/multiset.test/multiset.tests.h"
#include "container/unordered_set.test/unordered_set.tests.h"
#include "container/unordered_multiset.test/unordered_multiset.tests.h"
#include "container/map.test/map.tests.h"
#include "container/multimap.test/multimap.tests.h"
#include "container/unordered_map.test/unordered_map.tests.h"
#include "container/unordered_multimap.test/unordered_multimap.tests.h"


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
