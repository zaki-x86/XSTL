#ifndef _LIST_FIXTURE_H_

#define _LIST_FIXTURE_H_


#include "container/list.h"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class list_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


END_NS_ZXX_CORE_CONTAINER_TEST

#endif //