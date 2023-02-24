
#ifndef _MULTISET_TESTS_H_

#define _MULTISET_TESTS_H_

#include "xstl_test/multiset_tester.h"
#include <iostream>
#include <set>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(multiset_test);


TYPED_TEST_P(multiset_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(multiset_test,
    DefaultConstructorTest

);

using MultisetTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(multiset_Test, multiset_test, MultisetTestTypeParameters);

_END_XSTL_TEST


#endif // !_MULTISET_TESTS_H_ 
    
