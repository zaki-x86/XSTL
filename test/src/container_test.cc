/**
 * @file container_test.cc
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "xstl_test/array_basic_test.h"
#include "xstl_test/vector_basic_test.h"
#include "xstl_test/deque_basic_test.h"
#include "xstl_test/forward_list_basic_test.h"
#include "xstl_test/list_basic_test.h"
#include "xstl_test/set_basic_test.h"
#include "xstl_test/multiset_basic_test.h"
#include "xstl_test/unordered_set_basic_test.h"
#include "xstl_test/unordered_multiset_basic_test.h"
#include "xstl_test/map_basic_test.h"
#include "xstl_test/multimap_basic_test.h"
#include "xstl_test/unordered_map_basic_test.h"
#include "xstl_test/unordered_multimap_basic_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
