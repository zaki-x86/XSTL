
#ifndef _MULTIMAP_TESTS_H_

#define _MULTIMAP_TESTS_H_

#include "xstl_test/multimap_tester.h"
#include <iostream>
#include <map>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(multimap_test);


TYPED_TEST_P(multimap_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(multimap_test,
    DefaultConstructorTest

);

using MultimapTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(multimap_Test, multimap_test, MultimapTestTypeParameters);

_END_XSTL_TEST


#endif // !_MULTIMAP_TESTS_H_ 
    
