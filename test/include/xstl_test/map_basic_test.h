
#ifndef _MAP_TESTS_H_

#define _MAP_TESTS_H_

#include "xstl_test/map_tester.h"
#include <iostream>
#include <map>

_BEGIN_XSTL_TEST

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
    std::string
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(map_Test, map_test, MapTestTypeParameters);

_END_XSTL_TEST


#endif // !_MAP_TESTS_H_ 
    
