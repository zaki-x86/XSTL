
#ifndef _UNORDERED_SET_TESTS_H_

#define _UNORDERED_SET_TESTS_H_

#include "container/unordered_set.test/unordered_set.fixture.h"
#include <iostream>
#include <unordered_set>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(unordered_set_test);


TYPED_TEST_P(unordered_set_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(unordered_set_test,
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
    std::unordered_set<int, 10>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_set_Test, unordered_set_test, TestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_UNORDERED_SET_TESTS_H_ 
    
