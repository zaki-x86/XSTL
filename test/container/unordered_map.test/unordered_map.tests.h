
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

using UnorderedMapTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
<<<<<<< HEAD:test/include/container/unordered_map.test/unordered_map.tests.h
    std::string, 
    std::unordered_map<std::string, int>
=======
    std::string
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/unordered_map.test/unordered_map.tests.h
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_map_Test, unordered_map_test, UnorderedMapTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_UNORDERED_MAP_TESTS_H_ 
    
