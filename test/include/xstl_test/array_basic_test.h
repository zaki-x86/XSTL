#ifndef _BASIC_TEST_H_

#define _BASIC_TEST_H_

#include<iostream>
#include<string>
#include <array>
#include<algorithm>
#include "array_tester.h"
#include<helpers/generators.h>
#include<helpers/generate_containers.h>


_BEGIN_XSTL_TEST

template<typename Type>
class ArrayBasicTest : public ::testing::Test {
public:
    static const size_t TESTING_SIZE = 100;    

    void SetUp() override {
        ArrayTesterUtils::init_cstyle_array<Type, TESTING_SIZE>(c_arr);
        ArrayTesterUtils::clone_c_array<Type, TESTING_SIZE>(arr, c_arr);
        tester = ArrayTester<Type, TESTING_SIZE>(arr, c_arr);
    }

    xstl::array<Type, TESTING_SIZE> arr;
    Type c_arr[TESTING_SIZE];
    ArrayTester<Type, TESTING_SIZE> tester;
    ArrayTester<Type, 0> empty_arr_tester;
};

using PimitiveTypes = ::testing::Types<
// 1. Numerical Primitives
    //int16_t,
    //int32_t,
    //int64_t,
    int,
    //float,
    //double,
    //long, // long type random generator is not supported (yet)
    //long,

// 2. char and string primitives
    char,
    //const char*,
    std::string
>;
using PointerTypes = ::testing::Types<
    int*,
    long*,
    const char*,
    std::string*
>;

using STLContainerTypes = ::testing::Types<
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


TYPED_TEST_P(ArrayBasicTest, CanIterateOverArray) 
{
    this->tester.perform_iterator_checks();
    this->empty_arr_tester.perform_iterator_checks();
}


TYPED_TEST_P(ArrayBasicTest, CanGetStorageInfoFromArray)
{
    this->tester.perform_storage_checks();
    this->empty_arr_tester.perform_storage_checks();
}

TYPED_TEST_P(ArrayBasicTest, CanAccessArrayElementsViaOperator)
{
    this->tester.test_access_operator();
    this->empty_arr_tester.test_access_operator();
}

TYPED_TEST_P(ArrayBasicTest, CanAccessArrayElementsViaAt)
{
    this->tester.test_at();
    this->empty_arr_tester.test_at();
}

TYPED_TEST_P(ArrayBasicTest, CanAccessFrontAndBackElements)
{
    this->tester.test_front();
    this->empty_arr_tester.test_front();
    this->tester.test_back();
    this->empty_arr_tester.test_back();
}

TYPED_TEST_P(ArrayBasicTest, CanAccessCArray)
{
    this->tester.test_generated_c_array();
    this->empty_arr_tester.test_generated_c_array();
}

TYPED_TEST_P(ArrayBasicTest, CanFillArrayWithRandomValue)
{
    this->tester.test_fill();
    this->empty_arr_tester.test_fill();
}

TYPED_TEST_P(ArrayBasicTest, CanSwapArraysWithMemberFunction)
{
    this->tester.test_swap();
    this->empty_arr_tester.test_swap();
}


TYPED_TEST_P(ArrayBasicTest, CanPeformRelationalOpsOnArray)
{
    this->tester.perform_relational_ops_checks();
    this->empty_arr_tester.perform_relational_ops_checks();
}

TYPED_TEST_P(ArrayBasicTest, CanPrintArrayElements)
{
    this->tester.test_print();
    this->empty_arr_tester.test_print();
}

REGISTER_TYPED_TEST_SUITE_P(ArrayBasicTest,
    CanIterateOverArray,
    CanGetStorageInfoFromArray,
    CanAccessArrayElementsViaOperator,
    CanAccessArrayElementsViaAt,
    CanAccessFrontAndBackElements,
    CanAccessCArray,
    CanFillArrayWithRandomValue,
    CanSwapArraysWithMemberFunction,
    CanPeformRelationalOpsOnArray,
    CanPrintArrayElements
);

INSTANTIATE_TYPED_TEST_SUITE_P(ArrayTestWithPrimitiveTypes, ArrayBasicTest, PimitiveTypes);
//INSTANTIATE_TYPED_TEST_SUITE_P(ArrayTestWithPointerTypes, ArrayBasicTest, PointerTypes);
//INSTANTIATE_TYPED_TEST_SUITE_P(ArrayTestWithExoticTypes, ArrayBasicTest, ExoticTypes);

_END_XSTL_TEST


#endif // !_BASIC_TEST_H_