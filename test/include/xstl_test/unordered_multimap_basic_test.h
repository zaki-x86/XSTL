
#ifndef _UNORDERED_MULTIMAP_TESTS_H_

#define _UNORDERED_MULTIMAP_TESTS_H_

#include "xstl_test/unordered_multimap_tester.h"
#include <iostream>
#include <unordered_map>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(unordered_multimap_test);


TYPED_TEST_P(unordered_multimap_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(unordered_multimap_test,
    DefaultConstructorTest

);

using UnorderedMultimapTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_multimap_Test, unordered_multimap_test, UnorderedMultimapTestTypeParameters);

_END_XSTL_TEST


#endif // !_UNORDERED_MULTIMAP_TESTS_H_ 
    
