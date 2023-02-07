
#ifndef _MULTIMAP_TESTS_H_

#define _MULTIMAP_TESTS_H_

#include "container/multimap.test/multimap.fixture.h"
#include <iostream>
#include <map>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(multimap_test);


TYPED_TEST_P(multimap_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(multimap_test,
    DefaultConstructorTest

);

using MultimapTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
<<<<<<< HEAD:test/include/container/multimap.test/multimap.tests.h
    std::string, 
    std::multimap<std::string, int>
=======
    std::string
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/multimap.test/multimap.tests.h
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(multimap_Test, multimap_test, MultimapTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_MULTIMAP_TESTS_H_ 
    
