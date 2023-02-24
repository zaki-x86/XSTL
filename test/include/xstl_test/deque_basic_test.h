#ifndef _DEQUE_TESTS_H_

#define _DEQUE_TESTS_H_

#include "xstl_test/deque_tester.h"
#include <iostream>
#include <deque>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(deque_test);


TYPED_TEST_P(deque_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(deque_test,
    DefaultConstructorTest

);

using DequeTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string, 
    std::deque<int>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(deque_test, deque_test, DequeTestTypeParameters);

_END_XSTL_TEST


#endif // !_ARRAY_TESTS_H_