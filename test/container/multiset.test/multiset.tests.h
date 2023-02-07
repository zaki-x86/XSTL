
#ifndef _MULTISET_TESTS_H_

#define _MULTISET_TESTS_H_

#include "container/multiset.test/multiset.fixture.h"
#include <iostream>
#include <set>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

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
<<<<<<< HEAD:test/include/container/multiset.test/multiset.tests.h
    std::string, 
    std::multiset<int>
=======
    std::string
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/multiset.test/multiset.tests.h
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(multiset_Test, multiset_test, MultisetTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_MULTISET_TESTS_H_ 
    
