
#ifndef _MULTISET_FIXTURE_H_

#define _MULTISET_FIXTURE_H_


#include "xstl/set"

_BEGIN_XSTL_TEST

    template<typename T>
    class multiset_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif // !_MULTISET_TEST_HPP

