
#ifndef _UNORDERED_SET_TESTS_H_

#define _UNORDERED_SET_TESTS_H_

#include "container/unordered_set.test/unordered_set.fixture.h"
#include <iostream>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(unordered_set_test);


TYPED_TEST_P(unordered_set_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(unordered_set_test,
    DefaultConstructorTest

);

using UnorderedSetTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
<<<<<<< HEAD:test/include/container/unordered_set.test/unordered_set.tests.h
    std::string, 
    std::unordered_set<int>
=======
    std::string
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/unordered_set.test/unordered_set.tests.h
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_set_Test, unordered_set_test, UnorderedSetTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_UNORDERED_SET_TESTS_H_ 
    
