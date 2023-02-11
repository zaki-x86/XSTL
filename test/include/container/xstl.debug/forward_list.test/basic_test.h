#ifndef _FORWARD_LIST_TESTS_H_

#define _FORWARD_LIST_TESTS_H_

#include "xstl.debug/forward_list.test/forward_list.debug.h"
#include <iostream>
#include <forward_list>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(forward_list_test);


TYPED_TEST_P(forward_list_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(forward_list_test,
    DefaultConstructorTest

);

using ForwardListTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string, 
    std::forward_list<int>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(forward_list_test, forward_list_test, ForwardListTestTypeParameters);

_END_XSTL_TEST


#endif // !_ARRAY_TESTS_H_