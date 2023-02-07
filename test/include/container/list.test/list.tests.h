#ifndef _LIST_TESTS_H_

#define _LIST_TESTS_H_

#include "container/list.test/list.fixture.h"
#include <iostream>
#include <list>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

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

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_ARRAY_TESTS_H_