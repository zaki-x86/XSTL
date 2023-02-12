#ifndef _BASIC_TEST_H_

#define _BASIC_TEST_H_

#include<iostream>
#include<string>
#include <array>
#include<algorithm>
#include "xstl.debug/array.test/array.debug.h"
#include<helpers/generators.h>
#include<helpers/generate_containers.h>


_BEGIN_XSTL_TEST

/// FIXME : warning related to an issue with instantiating the `debugger` object
/// use of undeclared identifier 'debugger'; unqualified lookup into dependent bases of class template ('CanForwardIterateOverArray' , 'CanConstForwardIterateOverArray', .. etc) is a Microsoft extension

template<typename Type>
class ArrayBasicTest : public ::testing::Test {
public:
    static const size_t TESTING_SIZE = 100;

    void SetUp() override {
        DebugUtils::init_cstyle_array<Type, TESTING_SIZE>(c_arr);
        DebugUtils::clone_c_array<Type, TESTING_SIZE>(arr, c_arr);
        debugger = Debug_array<Type, TESTING_SIZE>(arr, c_arr);
    }

    void TearDown() override {
    }

    xstl::array<Type, TESTING_SIZE> arr;
    Type c_arr[TESTING_SIZE];
    Debug_array<Type, TESTING_SIZE> debugger;
};

using PimitiveTypes = ::testing::Types<
    // boring types
    int,
    //long, // int64_t random generator is not supported (yet)
    char,
    std::string
>;
using PointerTypes = ::testing::Types<
    // pointers
    int*,
    long*,
    const char*,
    std::string*
>;

using STLContaineTypes = ::testing::Types<
    std::array<int, 5>
    //std::vector<int>,
    //std::deque<int>,
    //std::forward_list<int>,
    //std::list<int>,
    //std::set<int>,
    //std::unordered_set<int>,
    //std::map<int>,
    //std::unordered_map<int>,
    //std::stack<int>,
    //std::queue<int>
>;

//using ExoticTypes = ::testing::Types<
//    // custom types and containers of containers
//    
//>;

TYPED_TEST_SUITE_P(ArrayBasicTest);


TYPED_TEST_P(ArrayBasicTest, CanForwardIterateOverArray) 
{
    debugger.test_forward_iteration();
}

TYPED_TEST_P(ArrayBasicTest, CanConstForwardIterateOverArray)
{
    debugger.test_const_forward_iteration();
}

TYPED_TEST_P(ArrayBasicTest, CanReverseIterateOverArray)
{
    debugger.test_reverse_iteration();
}

TYPED_TEST_P(ArrayBasicTest, CanConstReverseIterateOverArray)
{
    debugger.test_const_reverse_iteration();
}

TYPED_TEST_P(ArrayBasicTest, CanGetStorageInfoFromArray)
{
    debugger.perform_storage_checks();
}

TYPED_TEST_P(ArrayBasicTest, CanAccessArrayUsingAccessOperator)
{
    debugger.test_access_via_operator();
}

TYPED_TEST_P(ArrayBasicTest, CanAccessArrayUsingAt)
{
    debugger.test_access_via_at();
}

TYPED_TEST_P(ArrayBasicTest, CanGetFrontAndBackElementsOfArray)
{
    debugger.test_front_and_back_access();
}

TYPED_TEST_P(ArrayBasicTest, CanGetWrappedCArray)
{
    debugger.test_generated_c_array();
}

TYPED_TEST_P(ArrayBasicTest, CanFillArrayWithRandomValue)
{
    debugger.test_fill();
}

TYPED_TEST_P(ArrayBasicTest, CanSwapArrayWithAnotherArray)
{
    debugger.test_swap();
}

TYPED_TEST_P(ArrayBasicTest, CanPeformRelationalOpsOnArray)
{
    debugger.perform_relational_ops_checks();
}

TYPED_TEST_P(ArrayBasicTest, CanPrintArrayElements)
{

}

REGISTER_TYPED_TEST_SUITE_P(ArrayBasicTest,
    CanForwardIterateOverArray,
    CanConstForwardIterateOverArray,
    CanReverseIterateOverArray,
    CanConstReverseIterateOverArray,
    CanGetStorageInfoFromArray,
    CanAccessArrayUsingAccessOperator,
    CanAccessArrayUsingAt,
    CanGetFrontAndBackElementsOfArray,
    CanGetWrappedCArray,
    CanFillArrayWithRandomValue,
    CanSwapArrayWithAnotherArray,
    CanPeformRelationalOpsOnArray,
    CanPrintArrayElements

);

INSTANTIATE_TYPED_TEST_SUITE_P(ArrayTestWithPrimitiveTypes, ArrayBasicTest, PimitiveTypes);
//INSTANTIATE_TYPED_TEST_SUITE_P(ArrayTestWithPointerTypes, ArrayBasicTest, PointerTypes);
//INSTANTIATE_TYPED_TEST_SUITE_P(ArrayTestWithExoticTypes, ArrayBasicTest, ExoticTypes);

_END_XSTL_TEST


#endif // !_BASIC_TEST_H_