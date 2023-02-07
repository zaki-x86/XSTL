
#ifndef _UNORDERED_SET_FIXTURE_H_

#define _UNORDERED_SET_FIXTURE_H_


#include "container/unordered_set"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class unordered_set_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


END_NS_ZXX_CORE_CONTAINER_TEST

#endif // !_UNORDERED_SET_TEST_HPP

