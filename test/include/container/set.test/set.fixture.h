
#ifndef _SET_FIXTURE_H_

#define _SET_FIXTURE_H_


#include "container/set"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class set_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


END_NS_ZXX_CORE_CONTAINER_TEST

#endif // !_SET_TEST_HPP

