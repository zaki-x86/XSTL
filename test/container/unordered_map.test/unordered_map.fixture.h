
#ifndef _UNORDERED_MAP_FIXTURE_H_

#define _UNORDERED_MAP_FIXTURE_H_


#include "container/unordered_map"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class unordered_map_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


END_NS_ZXX_CORE_CONTAINER_TEST

#endif // !_UNORDERED_MAP_TEST_HPP

