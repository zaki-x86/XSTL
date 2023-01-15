#ifndef _FORWARD_LIST_FIXTURE_H_

#define _FORWARD_LIST_FIXTURE_H_


#include "container/forward_list"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class forward_list_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


END_NS_ZXX_CORE_CONTAINER_TEST

#endif //