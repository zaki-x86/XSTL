
#ifndef _SET_TESTS_H_

#define _SET_TESTS_H_

#include "xstl_test/set_tester.h"
#include <iostream>
#include <set>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(set_test);


TYPED_TEST_P(set_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(set_test,
    DefaultConstructorTest

);

using SetTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string
	>;

INSTANTIATE_TYPED_TEST_SUITE_P(set_Test, set_test, SetTestTypeParameters);

_END_XSTL_TEST


#endif // !_SET_TESTS_H_ 
    
