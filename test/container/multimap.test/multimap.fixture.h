
#ifndef _MULTIMAP_FIXTURE_H_

#define _MULTIMAP_FIXTURE_H_


#include "container/map"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class multimap_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


END_NS_ZXX_CORE_CONTAINER_TEST

#endif // !_MULTIMAP_TEST_HPP

