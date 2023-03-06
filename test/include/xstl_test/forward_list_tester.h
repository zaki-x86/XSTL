#ifndef _FORWARD_LIST_FIXTURE_H_

#define _FORWARD_LIST_FIXTURE_H_


#include "xstl/forward_list.hpp"

_BEGIN_XSTL_TEST

    template<typename T>
    class forward_list_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif //