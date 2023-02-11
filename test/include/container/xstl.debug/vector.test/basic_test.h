#ifndef _VECTOR_TESTS_H_

#define _VECTOR_TESTS_H_

#include "xstl.debug/vector.test/vector.debug.h"
#include <vector>

_BEGIN_XSTL_TEST

TYPED_TEST_SUITE_P(vector_test);

// #######################################################
// Testing Standards:
// .................
// - For each unit test `T_n()` belongs to a test suit TS, it comprises of 3 parts:
//      0. initial setup for the objects and mockups in-use.
//      1. checks against API output
//      2. checks against internal behavior 
// - Checks are done on the basis of a comparison between standard library behavior
// and our library behavior
// #######################################################


// ##################
// # Constructor Test
// ##################

TYPED_TEST_P(vector_test, DefaultConstructorWithDefaultAllocatorTest) 
{
    // vector a;
    // assert_true: a.empty() == 0
    // assert_true: a.get_allocator() = default_allocator
    // assert true: container should allocate no storage
    vector<TypeParam> x;
}
// #######################################################
TYPED_TEST_P(vector_test, DefaultConstructorWithCustomAllocatorTest) 
{
    // vector a(m), where m is a custom allocator object
    // assert true: a.empty()
    // assert true: a.get_allocator() = m
}
// #######################################################
TYPED_TEST_P(vector_test, CopyConstructorWithDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, CopyConstructorWithCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, MoveConstructorWithDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, MoveConstructorWithCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, FillConstructorWithDefaultValueAndDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, FillConstructorWithInitValueAndDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, FillConstructorWithDefaultValueAndCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, FillConstructorWithInitValueAndCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, RangeConstructorWithDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, RangeConstructorWithCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, InitializerListConstructorWithDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, InitializerListConstructorWithCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, CopyAssignmentTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, MoveAssignmentTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, InitializerListAssignmentTest) 
{

}
// #######################################################
// #######################################################

// #################
// # API Test
// #################

TYPED_TEST_P(vector_test, EmplaceBackTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, EmplaceTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, PushBackLvTest) 
{

}
// #######################################################
TYPED_TEST_P(vector_test, PushBackRvTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, PopBackTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, InsertLvTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, InsertRvTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, FillInsertTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, RangeInsertTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, InitializerListInsertTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, SingleEraseTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, RangeEraseTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, ClearTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, SwapTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, CapacityTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, SizeTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, MaxSizeTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, EmptyTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, ReserveTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, ShrinkToFitTest)
{
   
}
// #######################################################
TYPED_TEST_P(vector_test, GetAllocatorTest)
{
   
}

// #################
// # Register Tests
// #################

REGISTER_TYPED_TEST_SUITE_P(vector_test, 
    // Construction Unit Tests 
    DefaultConstructorWithDefaultAllocatorTest,
    DefaultConstructorWithCustomAllocatorTest,
    CopyConstructorWithDefaultAllocatorTest,
    CopyConstructorWithCustomAllocatorTest,
    MoveConstructorWithDefaultAllocatorTest,
    MoveConstructorWithCustomAllocatorTest,
    FillConstructorWithDefaultValueAndDefaultAllocatorTest,
    FillConstructorWithInitValueAndDefaultAllocatorTest,
    FillConstructorWithDefaultValueAndCustomAllocatorTest,
    FillConstructorWithInitValueAndCustomAllocatorTest,
    RangeConstructorWithDefaultAllocatorTest,
    RangeConstructorWithCustomAllocatorTest,
    InitializerListConstructorWithDefaultAllocatorTest,
    InitializerListConstructorWithCustomAllocatorTest,

    // Assignment Unit Tests
    CopyAssignmentTest,
    MoveAssignmentTest,
    InitializerListAssignmentTest,

    // Modifiers Unit Tests
    EmplaceBackTest,
    EmplaceTest,
    PushBackLvTest,
    PushBackRvTest,
    PopBackTest,
    InsertLvTest,
    InsertRvTest,
    FillInsertTest,
    RangeInsertTest,
    InitializerListInsertTest,
    SingleEraseTest,
    RangeEraseTest,
    ClearTest,
    SwapTest,

    // Storage and Size Unit Tests
    CapacityTest,
    SizeTest,
    MaxSizeTest,
    EmptyTest,
    ReserveTest,
    ShrinkToFitTest,

    // Observers Unit Tests
    GetAllocatorTest
);

using vectorTestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    // error:vector.imp.h:58:45: error: invalid use of array with unspecified bounds
   // 58 | _m_impl._m_end_of_storage - _m_impl._m_start);
    // char[], error:  
    // int[],  error: 
    int*,
    std::string*, 
    std::string, 
    std::vector<int>
    //std::array<int, 10>
    > ;

INSTANTIATE_TYPED_TEST_SUITE_P(vector_test_, vector_test, vectorTestTypeParameters);

// #######################################################

_END_XSTL_TEST

#endif // !_VECTOR_TESTS_H_
