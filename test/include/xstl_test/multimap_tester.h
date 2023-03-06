
#ifndef _MULTIMAP_FIXTURE_H_

#define _MULTIMAP_FIXTURE_H_


#include "xstl/map.hpp"

_BEGIN_XSTL_TEST

    template<typename T>
    class multimap_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif // !_MULTIMAP_TEST_HPP

