
#ifndef _UNORDERED_MULTISET_FIXTURE_H_

#define _UNORDERED_MULTISET_FIXTURE_H_


#include "xstl/unordered_set.hpp"

_BEGIN_XSTL_TEST

    template<typename T>
    class unordered_multiset_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif // !_UNORDERED_MULTISET_TEST_HPP

