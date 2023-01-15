
#ifndef _UNORDERED_MULTIMAP_FIXTURE_H_

#define _UNORDERED_MULTIMAP_FIXTURE_H_


#include "container/unordered_multimap"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class unordered_multimap_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


END_NS_ZXX_CORE_CONTAINER_TEST

#endif // !_UNORDERED_MULTIMAP_TEST_HPP

