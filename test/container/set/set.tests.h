
#ifndef _SET_TESTS_H_

#define _SET_TESTS_H_

#include "container/set.test/set.fixture.h"
#include <iostream>
#include <set>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(set_test);


TYPED_TEST_P(set_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(set_test,
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
    std::set<int, 10>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(set_Test, set_test, TestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_SET_TESTS_H_ 
    
