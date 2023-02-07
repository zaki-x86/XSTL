
#ifndef _SET_TESTS_H_

#define _SET_TESTS_H_

#include "container/set.test/set.fixture.h"
#include <iostream>
#include <set>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(set_test);


TYPED_TEST_P(set_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(set_test,
    DefaultConstructorTest

);

using SetTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
<<<<<<< HEAD:test/include/container/set.test/set.tests.h
    std::string, 
    std::set<int>
    >;
=======
    std::string
	>;
>>>>>>> a570bd30f98418cde5146e11e4bf53f55c2a1cd6:test/container/set.test/set.tests.h

INSTANTIATE_TYPED_TEST_SUITE_P(set_Test, set_test, SetTestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_SET_TESTS_H_ 
    
