#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include <string>
#include <vector>

#include <xstl/debug/assertions.h>
#include <type_traits>
#include <xstl/type_traits.hpp>
#include <helpers/generators.h>

_BEGIN_XSTL_TEST

TEST_SUITE("Base Classes Test")
{
    TEST_CASE("xstl::integral_constant test"){
        CHECK(xstl::integral_constant<int, 100>::value == 100);
        CHECK(xstl::integral_constant<int, 100>::type::value == 100);
        CHECK(xstl::bool_constant<true>::value == true);
        CHECK(xstl::bool_constant<false>::value == false);
    }
}

TEST_SUITE("Type Modification Test")
{
    TEST_CASE_TEMPLATE("Test xstl::remove_reference and xstl::remove_reference_t", T, int, int&, int&&)
    {
        CHECK(std::is_same<typename xstl::remove_reference<T>::type, typename std::remove_reference<T>::type>::value);
        CHECK(std::is_same<xstl::remove_reference_t<T>, typename std::remove_reference<T>::type>::value);
    }

    TEST_CASE("Test xstl::add_rvalue_reference") {
        CHECK(std::is_same<typename xstl::add_rvalue_reference<int>::type, int&&>::value);
        CHECK(std::is_same<typename xstl::add_rvalue_reference<int&>::type, int&>::value);
        CHECK(std::is_same<typename xstl::add_rvalue_reference<int&&>::type, int&&>::value);
}

    TEST_CASE("Test xstl::add_rvalue_reference_t") {
        CHECK(std::is_same<xstl::add_rvalue_reference_t<int>, int&&>::value);
        CHECK(std::is_same<xstl::add_rvalue_reference_t<int&>, int&>::value);
        CHECK(std::is_same<xstl::add_rvalue_reference_t<int&&>, int&&>::value);
    }

    TEST_CASE("Test xstl::add_lvalue_reference") {
        CHECK(std::is_same<typename xstl::add_lvalue_reference<int>::type, int&>::value);
        CHECK(std::is_same<typename xstl::add_lvalue_reference<int&>::type, int&>::value);
        CHECK(std::is_same<typename xstl::add_lvalue_reference<int&&>::type, int&>::value);
    }

    TEST_CASE("Test xstl::add_lvalue_reference_t") {
        CHECK(std::is_same<xstl::add_lvalue_reference_t<int>, int&>::value);
        CHECK(std::is_same<xstl::add_lvalue_reference_t<int&>, int&>::value);
        CHECK(std::is_same<xstl::add_lvalue_reference_t<int&&>, int&>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::remove_pointer and xstl::remove_pointer_t", T, int, int*, int* const, int* const volatile)
    {
        CHECK(std::is_same<typename xstl::remove_pointer<T>::type, int>::value);
        CHECK(std::is_same<xstl::remove_pointer_t<T>, int>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::remove_pointer and xstl::remove_pointer_t with void", T, void, void*, void* const, void* const volatile)
    {
        CHECK(std::is_same<typename xstl::remove_pointer<T>::type, void>::value);
        CHECK(std::is_same<xstl::remove_pointer_t<T>, void>::value);
    }

    TEST_CASE("Test xstl::remove_pointer and xstl::remove_pointer_t with custom types")
    {
        struct _test_EmptyClass {};
        CHECK(std::is_same<typename xstl::remove_pointer<_test_EmptyClass*>::type, _test_EmptyClass>::value);

    }

    TEST_CASE_TEMPLATE("Test xstl::remove_const and xstl::remove_const_t", T, int, const int, int const)
    {
        CHECK(std::is_same<typename xstl::remove_const<T>::type, int>::value);
        CHECK(std::is_same<xstl::remove_const_t<T>, int>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::add_pointer and xstl::add_pointer_t", T, int, std::string, double, char, std::vector<int>, std::vector<std::string>)
    {
        CHECK(std::is_same<typename xstl::add_pointer<T>::type, T*>::value);
        CHECK(std::is_same<xstl::add_pointer_t<T>, T*>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::add_pointer and xstl::add_pointer_t with reference types", T, int&, std::string&, double&, char&, std::vector<int>&, std::vector<std::string>&)
    {
        CHECK(std::is_same<typename xstl::add_pointer<T>::type, typename std::add_pointer<T>::type>::value);
        CHECK(std::is_same<xstl::add_pointer_t<T>, typename std::add_pointer<T>::type>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::make_signed and xstl::make_signed_t", T, int, unsigned int, long, unsigned long, long long, unsigned long long)
    {
        CHECK(std::is_same<typename xstl::make_signed<T>::type, typename std::make_signed<T>::type>::value);
        CHECK(std::is_same<xstl::make_signed_t<T>, typename std::make_signed<T>::type>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::make_unsigned and xstl::make_unsigned_t", T, int, unsigned int, long, unsigned long, long long, unsigned long long)
    {
        CHECK(std::is_same<typename xstl::make_unsigned<T>::type, typename std::make_unsigned<T>::type>::value);
        CHECK(std::is_same<xstl::make_unsigned_t<T>, typename std::make_unsigned<T>::type>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::remove_extent and xstl::remove_extent_t", T, int, int[10])
    {
        CHECK(std::is_same<typename xstl::remove_extent<T>::type, int>::value);
        CHECK(std::is_same<xstl::remove_extent_t<T>, int>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::remove_all_extents and xstl::remove_all_extents_t", T, int, int[10], int[10][10], int[10][10][10])
    {
        CHECK(std::is_same<typename xstl::remove_all_extents<T>::type, int>::value);
        CHECK(std::is_same<xstl::remove_all_extents_t<T>, int>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::remove_volatile and xstl::remove_volatile_t", T, int, volatile int, int volatile)
    {
        CHECK(std::is_same<typename xstl::remove_volatile<T>::type, int>::value);
        CHECK(std::is_same<xstl::remove_volatile_t<T>, int>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::remove_cv and xstl::remove_cv_t", T, int, const int, int const, volatile int, int volatile, const volatile int, int const volatile)
    {
        CHECK(std::is_same<typename xstl::remove_cv<T>::type, int>::value);
        CHECK(std::is_same<xstl::remove_cv_t<T>, int>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::add_const and xstl::add_const_t", T, int, const int, int const)
    {
        CHECK(std::is_same<typename xstl::add_const<T>::type, const int>::value);
        CHECK(std::is_same<xstl::add_const_t<T>, const int>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::add_volatile and xstl::add_volatile_t", T, int, volatile int, int volatile)
    {
        CHECK(std::is_same<typename xstl::add_volatile<T>::type, volatile int>::value);
        CHECK(std::is_same<xstl::add_volatile_t<T>, volatile int>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::add_cv and xstl::add_cv_t", T, int, const int, int const, volatile int, int volatile, const volatile int, int const volatile)
    {
        CHECK(std::is_same<typename xstl::add_cv<T>::type, const volatile int>::value);
        CHECK(std::is_same<xstl::add_cv_t<T>, const volatile int>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::remove_cvref and xstl::remove_cvref_t", T, int, const int, int const, volatile int, int volatile, const volatile int, int const volatile, int&, int&&)
    {
        CHECK(std::is_same<typename xstl::remove_cvref<T>::type, int>::value);
        CHECK(std::is_same<xstl::remove_cvref_t<T>, int>::value);
    }

}

TEST_SUITE("Type Transformations Test")
{
    TEST_CASE_TEMPLATE("Test xstl::aligned_storage", T, int) {}

    TEST_CASE_TEMPLATE("Test xstl::aligned_union", T, int) {}

    TEST_CASE_TEMPLATE("Test xstl::common_type", T, int) {}

    TEST_CASE_TEMPLATE("Test xstl::decay and xstl::decay_t", T, int[10], int(&)[10])
    {   
        CHECK(std::is_same<std::decay_t<T>, int*>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::enable_if and xstl::enable_if_t", T, int) {
        CHECK(std::is_same<typename xstl::enable_if<true, T>::type, T>::value);
        CHECK(std::is_same<xstl::enable_if_t<true, T>, T>::value);
    }

    TEST_CASE_TEMPLATE("Test xstl::conditional and xstl::conditional_t", T, int, bool)
    {
        CHECK(std::is_same<typename xstl::conditional<true, T, bool>::type, T>::value);
        CHECK(std::is_same<typename xstl::conditional<false, T, bool>::type, bool>::value);
        CHECK(std::is_same<xstl::conditional_t<true, T, bool>, T>::value);
        CHECK(std::is_same<xstl::conditional_t<false, T, bool>, bool>::value);
    }

    TEST_CASE("Test xstl::common_type and xstl::common_type_t") {}

    TEST_CASE("Test xstl::underlying_type and xstl::underlying_type_t")
    {
        enum class _Test : int {};
        CHECK(std::is_same<typename xstl::underlying_type<_Test>::type, int>::value);
        CHECK(std::is_same<xstl::underlying_type_t<_Test>, int>::value);
    }

}

TEST_SUITE("Type Operations Test")
{
    TEST_CASE("Test xstl::conjunction and xstl::conjunction_v")
    {
        CHECK(xstl::conjunction_v<>);
        CHECK(xstl::conjunction_v<std::is_same<int, int>>);
        CHECK(xstl::conjunction_v<std::is_same<int, int>, std::is_same<int, int>>);
        CHECK(xstl::conjunction_v<std::is_same<int, int>, std::is_same<int, int>, std::is_same<int, int>>);
        CHECK_FALSE(xstl::conjunction_v<std::is_same<int, int>, std::is_same<int, bool>>);
        CHECK_FALSE(xstl::conjunction_v<std::is_same<int, int>, std::is_same<int, bool>, std::is_same<int, int>>);
        CHECK_FALSE(xstl::conjunction_v<std::is_same<int, int>, std::is_same<int, bool>, std::is_same<int, int>, std::is_same<int, bool>>);
    }

    TEST_CASE("Test xstl::disjunction and xstl::disjunction_v")
    {
        CHECK_FALSE(xstl::disjunction_v<>);
        CHECK_FALSE(xstl::disjunction_v<std::is_same<int, bool>>);
        CHECK_FALSE(xstl::disjunction_v<std::is_same<int, bool>, std::is_same<int, bool>>);
        CHECK_FALSE(xstl::disjunction_v<std::is_same<int, bool>, std::is_same<int, bool>, std::is_same<int, bool>>);
        CHECK(xstl::disjunction_v<std::is_same<int, int>>);
        CHECK(xstl::disjunction_v<std::is_same<int, int>, std::is_same<int, bool>>);
        CHECK(xstl::disjunction_v<std::is_same<int, int>, std::is_same<int, bool>, std::is_same<int, int>>);
        CHECK(xstl::disjunction_v<std::is_same<int, int>, std::is_same<int, bool>, std::is_same<int, int>, std::is_same<int, bool>>);
    }

    TEST_CASE("Test xstl::negation and xstl::negation_v")
    {
        CHECK_FALSE(xstl::negation_v<std::is_same<int, int>>);
        CHECK(xstl::negation_v<std::is_same<int, bool>>);
    }

}

TEST_SUITE("Type Relationships Test")
{
    TEST_CASE_TEMPLATE("Test xstl::is_same and xstl::is_same_v", T, int, bool)
    {
        CHECK(xstl::is_same<T, T>::value);
        CHECK(xstl::is_same_v<T, T>);
    }

    TEST_CASE_TEMPLATE("Test xstl::is_base_of and xstl::is_base_of_v", T, int, bool)
    {
        CHECK(xstl::is_base_of<T, T>::value);
        CHECK(xstl::is_base_of_v<T, T>);
    }

    TEST_CASE_TEMPLATE("Test xstl::is_convertible and xstl::is_convertible_v", T, int, bool)
    {
        CHECK(xstl::is_convertible<T, T>::value);
        CHECK(xstl::is_convertible_v<T, T>);
    }

    TEST_CASE_TEMPLATE("Test xstl::is_nothrow_convertible and xstl::is_nothrow_convertible_v", T, int, bool)
    {
        CHECK(xstl::is_nothrow_convertible<T, T>::value);
        CHECK(xstl::is_nothrow_convertible_v<T, T>);
    }

    TEST_CASE("Test xstl::is_invockable")
    {
        
    }

    TEST_CASE("Test xstl::is_invockable_r")
    {
        
    }

    TEST_CASE("Test xstl::is_nothrow_invockable")
    {
        
    }

    TEST_CASE("Test xstl::is_nothrow_invockable_r")
    {
        
    }

    TEST_CASE("Test xstl::is_layout_compatible")
    {

    }

    TEST_CASE("Test xstl::is_pointer_interconvertible_base_of")
    {
        
    }

    TEST_CASE("Test xstl::is_pointer_interconvertible_with_class")
    {
        
    }

    TEST_CASE("Test xstl::is_corresponding_member")
    {

    }

}

TEST_SUITE("Properties Queries Test")
{
    /**
     * Tests the following traits:
     * alignment_of, rank, and extent
    */

   TEST_CASE_TEMPLATE("Test xstl::alignment_of and xstl::alignment_of_v", T, int, bool, char, unsigned char, short, unsigned short, long, unsigned long, long long, unsigned long long, float, double, long double)
   {
       CHECK(xstl::alignment_of<T>::value == alignof(T));
       CHECK(xstl::alignment_of_v<T> == alignof(T));
   }

   TEST_CASE_TEMPLATE("Test xstl::rank and xstl::rank_v of an array type", T, int[10], bool[10], char[10], unsigned char[10], short[10], unsigned short[10], long[10], unsigned long[10], long long[10], unsigned long long[10], float[10], double[10], long double[10])
   {
       CHECK(xstl::rank<T>::value == 1);
       CHECK(xstl::rank_v<T> == 1);
   }
}

TEST_SUITE("Supported Operations Type Test")
{
    /**
     * Tests the following operations:
     * is_constructible, is_trivially_constructible, is_nothrow_constructible, is_default_constructible, is_trivially_default_constructible, is_nothrow_default_constructible, is_copy_constructible, is_trivially_copy_constructible, is_nothrow_copy_constructible, is_move_constructible, is_trivially_move_constructible, is_nothrow_move_constructible, is_assignable, is_trivially_assignable, is_nothrow_assignable, is_copy_assignable, is_trivially_copy_assignable, is_nothrow_copy_assignable, is_move_assignable, is_trivially_move_assignable, is_nothrow_move_assignable, is_destructible, is_trivially_destructible, is_nothrow_destructible, has_virtual_destructor, is_swappable_with, is_swappable, is_nothrow_swappable_with, is_nothrow_swappable
    */

   TEST_CASE_TEMPLATE("Test xstl::is_constructible and xstl::is_constructible_v", T, int, bool, char, unsigned char, short, unsigned short, long, unsigned long, long long, unsigned long long, float, double, long double)
   {
       CHECK(xstl::is_constructible<T>::value);
       CHECK(xstl::is_constructible_v<T>);
   }

   TEST_CASE("Test xstl::is_trivially_constructible and xstl::is_trivially_constructible_v")
   {
       
   }

    TEST_CASE("Test xstl::is_nothrow_constructible and xstl::is_nothrow_constructible_v")
    {
         
    }

    TEST_CASE_TEMPLATE("Test xstl::is_default_constructible and xstl::is_default_constructible_v", T, int, bool, char, unsigned char, short, unsigned short, long, unsigned long, long long, unsigned long long, float, double, long double)
    {
        CHECK(xstl::is_default_constructible<T>::value);
        CHECK(xstl::is_default_constructible_v<T>);
    }

    TEST_CASE("Test xstl::is_trivially_default_constructible and xstl::is_trivially_default_constructible_v")
    {
         
    }

    TEST_CASE("Test xstl::is_nothrow_default_constructible and xstl::is_nothrow_default_constructible_v")
    {
         
    }

    TEST_CASE_TEMPLATE("Test xstl::is_copy_constructible and xstl::is_copy_constructible_v", T, int, bool, char, unsigned char, short, unsigned short, long, unsigned long, long long, unsigned long long, float, double, long double)
    {
        CHECK(xstl::is_copy_constructible<T>::value);
        CHECK(xstl::is_copy_constructible_v<T>);
    }

    TEST_CASE("Test xstl::is_trivially_copy_constructible and xstl::is_trivially_copy_constructible_v")
    {
         
    }

    TEST_CASE("Test xstl::is_nothrow_copy_constructible and xstl::is_nothrow_copy_constructible_v")
    {
         
    }

    TEST_CASE_TEMPLATE("Test xstl::is_move_constructible and xstl::is_move_constructible_v", T, int, bool, char, unsigned char, short, unsigned short, long, unsigned long, long long, unsigned long long, float, double, long double)
    {
        CHECK(xstl::is_move_constructible<T>::value);
        CHECK(xstl::is_move_constructible_v<T>);
    }

    TEST_CASE("Test xstl::is_trivially_move_constructible and xstl::is_trivially_move_constructible_v")
    {
         
    }

    TEST_CASE("Test xstl::is_nothrow_move_constructible and xstl::is_nothrow_move_constructible_v")
    {
         
    }

    TEST_CASE_TEMPLATE("Test xstl::is_assignable and xstl::is_assignable_v", T, int, bool, char, unsigned char, short, unsigned short, long, unsigned long, long long, unsigned long long, float, double, long double)
    {
        CHECK(xstl::is_assignable<T, T>::value);
        CHECK(xstl::is_assignable_v<T, T>);
    }

    TEST_CASE("Test xstl::is_trivially_assignable and xstl::is_trivially_assignable_v")
    {
         
    }

    TEST_CASE("Test xstl::is_nothrow_assignable and xstl::is_nothrow_assignable_v")
    {
         
    }

    TEST_CASE_TEMPLATE("Test xstl::is_copy_assignable and xstl::is_copy_assignable_v", T, int, bool, char, unsigned char, short, unsigned short, long, unsigned long, long long, unsigned long long, float, double, long double)
    {
        CHECK(xstl::is_copy_assignable<T>::value);
        CHECK(xstl::is_copy_assignable_v<T>);
    }

    TEST_CASE("Test xstl::is_trivially_copy_assignable and xstl::is_trivially_copy_assignable_v")
    {
         
    }

    TEST_CASE("Test xstl::is_nothrow_copy_assignable and xstl::is_nothrow_copy_assignable_v")
    {
         
    }

    TEST_CASE_TEMPLATE("Test xstl::is_move_assignable and xstl::is_move_assignable_v", T, int, bool, char, unsigned char, short, unsigned short, long, unsigned long, long long, unsigned long long, float, double, long double)
    {
        CHECK(xstl::is_move_assignable<T>::value);
        CHECK(xstl::is_move_assignable_v<T>);
    }

    TEST_CASE("Test xstl::is_trivially_move_assignable and xstl::is_trivially_move_assignable_v")
    {
         
    }

    TEST_CASE("Test xstl::is_nothrow_move_assignable and xstl::is_nothrow_move_assignable_v")
    {
         
    }

    TEST_CASE_TEMPLATE("Test xstl::is_destructible and xstl::is_destructible_v", T, int, bool, char, unsigned char, short, unsigned short, long, unsigned long, long long, unsigned long long, float, double, long double)
    {
        CHECK(xstl::is_destructible<T>::value);
        CHECK(xstl::is_destructible_v<T>);
    }

    TEST_CASE("Test xstl::is_trivially_destructible and xstl::is_trivially_destructible_v")
    {
         
    }

    TEST_CASE("Test xstl::is_nothrow_destructible and xstl::is_nothrow_destructible_v")
    {
         
    }
    
    TEST_CASE("Test xstl::has_virtual_destructor and xstl::has_virtual_destructor_v")
    {
         
    }

    TEST_CASE("Test xstl::is_swappable_with")
    {

    }

    TEST_CASE("Test xstl::is_swappable")
    {

    }

    TEST_CASE("Test xstl::is_nothrow_swappable_with")
    {

    }

    TEST_CASE("Test xstl::is_nothrow_swappable")
    {

    }

}

TEST_SUITE("Type Properties Test")
{
    /**
     * Tests the following traits:
     * xstl::is_const, xstl::is_const_v, xstl::is_volatile, xstl::is_volatile_v, xstl::is_trivial, xstl::is_trivial_v, xstl::is_standard_layout, xstl::is_standard_layout_v, xstl::is_pod, xstl::is_pod_v, xstl::is_literal_type, xstl::is_literal_type_v, xstl::is_empty, xstl::is_empty_v, xstl::is_polymorphic, xstl::is_polymorphic_v, xstl::is_abstract, xstl::is_abstract_v, xstl::is_signed, xstl::is_signed_v, xstl::is_unsigned, xstl::is_unsigned_v, xstl::is_final, xstl::is_final_v, xstl::is_aggregate, xstl::is_aggregate_v, xstl::is_trivially_copyable, xstl::is_trivially_copyable_v, xstl::has_unique_object_representation, xstl::has_unique_object_representation_v, xstl::is_bounded_array, xstl::is_bounded_array_v, xstl::is_unbounded_array, xstl::is_unbounded_array_v, xstl::is_scoped_enum
    */
   
}

TEST_SUITE("Composite Type Categories Test")
{
    /**
     * Tests the following traits:
     * xstl::is_reference, xstl::is_reference_v, xstl::is_object, xstl::is_object_v, xstl::is_scalar, xstl::is_scalar_v, xstl::is_compound, xstl::is_compound_v, xstl::is_member_pointer, xstl::is_member_pointer_v, xstl::is_member_object_pointer, xstl::is_member_object_pointer_v, xstl::is_member_function_pointer, xstl::is_member_function_pointer_v, xstl::is_fundamental, xstl::is_fundamental_v, xstl::is_arithmetic, xstl::is_arithmetic_v, xstl::is_reference_wrapper, xstl::is_reference_wrapper_v
    */
}

TEST_SUITE("Primary Type Categories Test")
{
	TEST_CASE_TEMPLATE(
		"Test xstl::is_integral and xstl::is_integral_v",
		T,
		bool,
		char,
		unsigned char,
		short,
		unsigned short,
		int,
		unsigned int,
		long,
		unsigned long,
		long long,
		unsigned long long)
	{
		CHECK(xstl::is_integral<T>::value);
		CHECK(xstl::is_integral_v<T>);
	}

	TEST_CASE_TEMPLATE("Test xstl::is_void and xstl::is_void_v", T, void)
	{
		CHECK(xstl::is_void<T>::value);
		CHECK(xstl::is_void_v<T>);
	}

	TEST_CASE_TEMPLATE("Test xstl::is_null_pointer and xstl::is_nullptr_v", T, decltype(nullptr))
	{
		CHECK(xstl::is_null_pointer<T>::value);
		CHECK(xstl::is_null_pointer_v<T>);
	}

	TEST_CASE_TEMPLATE("Test xstl::is_floating_point and xstl::is_floating_point_v", T, float, double, long double)
	{
		CHECK(xstl::is_floating_point<T>::value);
		CHECK(xstl::is_floating_point_v<T>);
	}

	TEST_CASE_TEMPLATE("Test xstl::is_array, xstl::is_array_v", T, int[10], int[20])
	{
		CHECK(xstl::is_array<T>::value);
		CHECK(xstl::is_array_v<T>);
	}	
}

_END_XSTL_TEST