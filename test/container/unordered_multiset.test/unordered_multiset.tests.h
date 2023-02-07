
#ifndef _UNORDERED_MULTISET_TESTS_H_

#define _UNORDERED_MULTISET_TESTS_H_

#include "container/unordered_multiset.test/unordered_multiset.fixture.h"
#include <iostream>
<<<<<<< HEAD:test/include/container/unordered_multiset.test/unordered_multiset.tests.h
#include <unordered_set>
=======
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/unordered_multiset.test/unordered_multiset.tests.h

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

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
<<<<<<< HEAD:test/include/container/unordered_multiset.test/unordered_multiset.tests.h
    std::string, 
    std::unordered_multiset<int>
=======
    std::string
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/unordered_multiset.test/unordered_multiset.tests.h
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_multiset_Test, unordered_multiset_test, UnorderedMultisetTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_UNORDERED_MULTISET_TESTS_H_ 
    
