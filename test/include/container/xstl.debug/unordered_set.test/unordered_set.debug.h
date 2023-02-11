
#ifndef _UNORDERED_SET_FIXTURE_H_

#define _UNORDERED_SET_FIXTURE_H_


#include "xstl/unordered_set"

_BEGIN_XSTL_TEST

    template<typename T>
    class unordered_set_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif // !_UNORDERED_SET_TEST_HPP

