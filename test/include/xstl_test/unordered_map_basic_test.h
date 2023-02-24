
#ifndef _UNORDERED_MAP_TESTS_H_

#define _UNORDERED_MAP_TESTS_H_

#include "xstl_test/unordered_map_tester.h"
#include <iostream>
#include <unordered_map>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(unordered_map_test);


TYPED_TEST_P(unordered_map_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(unordered_map_test,
    DefaultConstructorTest

);

using UnorderedMapTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_map_Test, unordered_map_test, UnorderedMapTestTypeParameters);

_END_XSTL_TEST


#endif // !_UNORDERED_MAP_TESTS_H_ 
    
