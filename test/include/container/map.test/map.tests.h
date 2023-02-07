
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
    std::string, 
    std::map<std::string, int>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(map_Test, map_test, MapTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_MAP_TESTS_H_ 
    
