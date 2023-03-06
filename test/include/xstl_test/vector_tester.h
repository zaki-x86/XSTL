#ifndef _VECTOR_FIXTURE_H_

#define _VECTOR_FIXTURE_H_


#include "xstl/vector.hpp"

_BEGIN_XSTL_TEST

    template<typename T>
    class vector_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    public:
        void assert_correct_instantiation();
    };

_END_XSTL_TEST


#endif // !_vector_TEST_HPP