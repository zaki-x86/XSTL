#ifndef _LIST_FIXTURE_H_

#define _LIST_FIXTURE_H_


#include "xstl/list"

_BEGIN_XSTL_TEST

    template<typename T>
    class list_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif //