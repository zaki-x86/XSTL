
#ifndef _UNORDERED_MULTIMAP_TESTS_H_

#define _UNORDERED_MULTIMAP_TESTS_H_

#include "container/unordered_multimap.test/unordered_multimap.fixture.h"
#include <iostream>
<<<<<<< HEAD:test/include/container/unordered_multimap.test/unordered_multimap.tests.h
#include <unordered_map>
=======
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/unordered_multimap.test/unordered_multimap.tests.h

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

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
<<<<<<< HEAD:test/include/container/unordered_multimap.test/unordered_multimap.tests.h
    std::string, 
    std::unordered_multimap<std::string, int>
=======
    std::string
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/unordered_multimap.test/unordered_multimap.tests.h
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_multimap_Test, unordered_multimap_test, UnorderedMultimapTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_UNORDERED_MULTIMAP_TESTS_H_ 
    
