#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include <string>

#include <xstl/debug/assertions.h>
#include <xstl/array.hpp>
#include <xstl_test/array_tester.h>

static const size_t TESTING_SIZE = 100;    

_BEGIN_XSTL_TEST

#if __cplusplus >= 201103L
MESSAGE("C++11 or higher detected");
#elif __cplusplus >= 201403L
MESSAGE("C++14 or higher detected");
#elif __cplusplus >= 201703L
MESSAGE("C++17 or higher detected");
#elif __cplusplus >= 202002L
MESSAGE("C++20 or higher detected");
#endif

TEST_SUITE("Container Library - Array Tests")
{
    TEST_CASE_TEMPLATE_DEFINE("Basic Array Operations Tests Against Primitive Types", Type, TEST_PRIMITIVE_TYPES)
    {
        xstl::array<Type, TESTING_SIZE> arr;
        Type c_arr[TESTING_SIZE];
        ArrayTesterUtils::init_cstyle_array<Type, TESTING_SIZE>(c_arr);
        ArrayTesterUtils::clone_c_array<Type, TESTING_SIZE>(arr, c_arr);
        ArrayTester<Type, TESTING_SIZE> tester(arr, c_arr);
        ArrayTester<Type, 0> empty_arr_tester;

        SUBCASE("Can iterate over array elements using range-based for loop")
        {
            tester.perform_iterator_checks();
            empty_arr_tester.perform_iterator_checks();
        }

        SUBCASE("Can get storage info")
        {
            tester.perform_storage_checks();
            empty_arr_tester.perform_storage_checks();
        }

        SUBCASE("Can access array elements using [] operator")
        {
            tester.test_access_operator();
            empty_arr_tester.test_access_operator();
        }

        SUBCASE("Can access array elements using at() method")
        {
            tester.test_at();
            empty_arr_tester.test_at();
        }

        SUBCASE("Can access array elements using front() method")
        {
            tester.test_front();
            empty_arr_tester.test_front();
        }

        SUBCASE("Can access array elements using back() method")
        {
            tester.test_back();
            empty_arr_tester.test_back();
        }

        SUBCASE("Can access array elements using data() method")
        {
            tester.test_generated_c_array();
            empty_arr_tester.test_generated_c_array();
        }

        SUBCASE("Can swap two arrays")
        {
            tester.test_swap();
            empty_arr_tester.test_swap();
        }

        SUBCASE("Can fill array with a value")
        {
            tester.test_fill();
            empty_arr_tester.test_fill();
        }

        SUBCASE("Verify if equality operators work properly")
        {
            tester.perform_relational_ops_checks();
            empty_arr_tester.perform_relational_ops_checks();
        }
        
        SUBCASE("Verify if stream operator works properly")
        {
            tester.test_print();
            empty_arr_tester.test_print();
        }
    }
    
    TEST_CASE_TEMPLATE_INVOKE(TEST_PRIMITIVE_TYPES, int, char, float, double, long, long long, unsigned int, unsigned long, unsigned long long, std::string);
}

_END_XSTL_TEST