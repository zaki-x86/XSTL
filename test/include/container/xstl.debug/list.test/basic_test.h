#ifndef _LIST_TESTS_H_

#define _LIST_TESTS_H_

#include "xstl.debug/list.test/list.debug.h"
#include <iostream>
#include <list>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(list_test);


TYPED_TEST_P(list_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(list_test,
    DefaultConstructorTest

);

using ListTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string, 
    std::list<int>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(list_test, list_test, ListTestTypeParameters);

_END_XSTL_TEST


#endif // !_ARRAY_TESTS_H_