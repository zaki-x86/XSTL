
#ifndef _UNORDERED_MAP_TESTS_H_

#define _UNORDERED_MAP_TESTS_H_

#include "container/unordered_map.test/unordered_map.fixture.h"
#include <iostream>
#include <unordered_map>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(unordered_map_test);


TYPED_TEST_P(unordered_map_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(unordered_map_test,
    DefaultConstructorTest

);

using TestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string, 
    std::unordered_map<int, 10>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_map_Test, unordered_map_test, TestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_UNORDERED_MAP_TESTS_H_ 
    
