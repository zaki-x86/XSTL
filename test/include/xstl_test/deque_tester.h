#ifndef _DEQUE_FIXTURE_H_

#define _DEQUE_FIXTURE_H_


#include "xstl/deque.hpp"

_BEGIN_XSTL_TEST

    template<typename T>
    class deque_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif //