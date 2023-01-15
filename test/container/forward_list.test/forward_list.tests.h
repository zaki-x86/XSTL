#ifndef _FORWARD_LIST_TESTS_H_

#define _FORWARD_LIST_TESTS_H_

#include "container/forward_list.test/forward_list.fixture.h"
#include <iostream>
#include <forward_list>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(forward_list_test);


TYPED_TEST_P(forward_list_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(forward_list_test,
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
    std::forward_list<int>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(forward_list_test, forward_list_test, TestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_ARRAY_TESTS_H_