#ifndef _DEQUE_TESTS_H_

#define _DEQUE_TESTS_H_

#include "container/deque.test/deque.fixture.h"
#include <iostream>
#include <deque>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(deque_test);


TYPED_TEST_P(deque_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(deque_test,
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
    std::deque<int>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(deque_test, deque_test, TestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_ARRAY_TESTS_H_