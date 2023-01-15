
#ifndef _MULTIMAP_TESTS_H_

#define _MULTIMAP_TESTS_H_

#include "container/multimap.test/multimap.fixture.h"
#include <iostream>
#include <multimap>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(multimap_test);


TYPED_TEST_P(multimap_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(multimap_test,
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
    std::multimap<int, 10>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(multimap_Test, multimap_test, TestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_MULTIMAP_TESTS_H_ 
    
