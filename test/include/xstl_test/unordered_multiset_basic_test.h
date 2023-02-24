
#ifndef _UNORDERED_MULTISET_TESTS_H_

#define _UNORDERED_MULTISET_TESTS_H_

#include "xstl_test/unordered_multiset_tester.h"
#include <iostream>
#include <unordered_set>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(unordered_multiset_test);


TYPED_TEST_P(unordered_multiset_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(unordered_multiset_test,
    DefaultConstructorTest

);

using UnorderedMultisetTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_multiset_Test, unordered_multiset_test, UnorderedMultisetTestTypeParameters);

_END_XSTL_TEST


#endif // !_UNORDERED_MULTISET_TESTS_H_ 
    
