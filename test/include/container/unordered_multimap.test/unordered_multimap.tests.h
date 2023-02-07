
#ifndef _UNORDERED_MULTIMAP_TESTS_H_

#define _UNORDERED_MULTIMAP_TESTS_H_

#include "container/unordered_multimap.test/unordered_multimap.fixture.h"
#include <iostream>
#include <unordered_map>

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
    std::string
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(unordered_multimap_Test, unordered_multimap_test, UnorderedMultimapTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_UNORDERED_MULTIMAP_TESTS_H_ 
    
