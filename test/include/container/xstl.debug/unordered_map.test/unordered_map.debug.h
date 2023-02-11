
#ifndef _UNORDERED_MAP_FIXTURE_H_

#define _UNORDERED_MAP_FIXTURE_H_


#include "xstl/unordered_map"

_BEGIN_XSTL_TEST

    template<typename T>
    class unordered_map_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif // !_UNORDERED_MAP_TEST_HPP

