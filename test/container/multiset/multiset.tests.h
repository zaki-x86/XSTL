
#ifndef _MULTISET_TESTS_H_

#define _MULTISET_TESTS_H_

#include "container/multiset.test/multiset.fixture.h"
#include <iostream>
#include <multiset>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(multiset_test);


TYPED_TEST_P(multiset_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(multiset_test,
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
    std::multiset<int, 10>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(multiset_Test, multiset_test, TestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_MULTISET_TESTS_H_ 
    
