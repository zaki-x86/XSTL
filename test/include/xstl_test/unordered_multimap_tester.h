
#ifndef _UNORDERED_MULTIMAP_FIXTURE_H_

#define _UNORDERED_MULTIMAP_FIXTURE_H_


#include "xstl/unordered_map.hpp"

_BEGIN_XSTL_TEST

    template<typename T>
    class unordered_multimap_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif // !_UNORDERED_MULTIMAP_TEST_HPP

