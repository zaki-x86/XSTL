
#ifndef _MAP_TESTS_H_

#define _MAP_TESTS_H_

#include "container/map.test/map.fixture.h"
#include <iostream>
#include <map>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(map_test);


TYPED_TEST_P(map_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(map_test,
    DefaultConstructorTest

);

using MapTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
<<<<<<< HEAD:test/include/container/map.test/map.tests.h
    std::string, 
    std::map<std::string, int>
=======
    std::string
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/map.test/map.tests.h
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(map_Test, map_test, MapTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_MAP_TESTS_H_ 
    
