
#ifndef _UNORDERED_SET_TESTS_H_

#define _UNORDERED_SET_TESTS_H_

#include "xstl_test/unordered_set_tester.h"
#include <iostream>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(unordered_set_test);


TYPED_TEST_P(unordered_set_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(unordered_set_test,
    DefaultConstructorTest

);

using UnorderedSetTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_set_Test, unordered_set_test, UnorderedSetTestTypeParameters);

_END_XSTL_TEST


#endif // !_UNORDERED_SET_TESTS_H_ 
    
