
#ifndef _MAP_FIXTURE_H_

#define _MAP_FIXTURE_H_


#include "xstl/map"

_BEGIN_XSTL_TEST

    template<typename T>
    class map_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


_END_XSTL_TEST

#endif // !_MAP_TEST_HPP

