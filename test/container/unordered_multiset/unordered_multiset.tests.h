
#ifndef _UNORDERED_MULTISET_TESTS_H_

#define _UNORDERED_MULTISET_TESTS_H_

#include "container/unordered_multiset.test/unordered_multiset.fixture.h"
#include <iostream>
#include <unordered_multiset>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(unordered_multiset_test);


TYPED_TEST_P(unordered_multiset_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(unordered_multiset_test,
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
    std::unordered_multiset<int, 10>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_multiset_Test, unordered_multiset_test, TestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_UNORDERED_MULTISET_TESTS_H_ 
    
