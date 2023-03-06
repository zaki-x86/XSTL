
#ifndef _SET_FIXTURE_H_

#define _SET_FIXTURE_H_


#include "xstl/set.hpp"

_BEGIN_XSTL_TEST

    template<typename T>
    class set_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif // !_SET_TEST_HPP

