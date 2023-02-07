#ifndef _DEQUE_FIXTURE_H_

#define _DEQUE_FIXTURE_H_


#include "container/deque"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class deque_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


END_NS_ZXX_CORE_CONTAINER_TEST

#endif //