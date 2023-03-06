/**
 * @file    type_traits.hpp@gmail.com)
 * @author  M Zaki (zaki.x
 * @brief   Type traits for C++ types.
 * @version 0.1
 * @date    2023-01-09
 * @copyright Copyright (c) 2023
 *
 * License: MIT
 *
 */

#ifndef _TYPE_TRAITS_HPP_
#define _TYPE_TRAITS_HPP_

#include "xstl/parts/metaprogramming/traits_internal.hpp"
#include "xstl/config/config.h"

/**
 * @brief Type traits for C++ types.
 *
 * The header contains:
 * Helper classes: Standard classes to assist in creating compile-time
 * constants. Type traits: Classes to obtain characteristics of types in the
 * form of compile-time constant values. Type transformations: Classes to obtain
 * new types by applying specific transformations to existing types.
 */

_BEGIN_XSTL

// ==========================================================================================
// ====== Base Classes =============================================
// ==========================================================================================

template<typename _Ty, _Ty _Val>
struct integral_constant
{
	static constexpr _Ty value = _Val;
	using value_type = _Ty;
	using type = integral_constant<_Ty, _Val>;
	explicit constexpr operator value_type() const noexcept { return value; }

#ifdef XSTL_CXX17
	constexpr value_type
	operator()() const noexcept
	{
		return value;
	}
#endif
};

#if ! __cpp_inline_variables
  template<typename _Ty, _Ty _Val>
    constexpr _Ty integral_constant<_Ty, _Val>::value;
#endif

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

// ==========================================================================================
// ====== Type Modification =============================================
// ==========================================================================================

// ===== remove_reference =====
template<typename _Ty>
struct remove_reference
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_reference<_Ty&>
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_reference<_Ty&&>
{
  using type = _Ty;
};

template<typename _Ty>
using remove_reference_t = typename remove_reference<_Ty>::type;

// ===== add_rvalue_reference =====
template<typename _Ty>
struct add_rvalue_reference
{
  using type = _Ty&&;
};

template<typename _Ty>
struct add_rvalue_reference<_Ty&>
{
  using type = _Ty&;
};

template<typename _Ty>
struct add_rvalue_reference<_Ty&&>
{
  using type = _Ty&&;
};

template<typename _Ty>
using add_rvalue_reference_t = typename add_rvalue_reference<_Ty>::type;

// ===== add_lvalue_reference =====
template<typename _Ty>
struct add_lvalue_reference
{
  using type = _Ty&;
};

template<typename _Ty>
struct add_lvalue_reference<_Ty&>
{
  using type = _Ty&;
};

template<typename _Ty>
struct add_lvalue_reference<_Ty&&>
{
  using type = _Ty&;
};

template<typename _Ty>
using add_lvalue_reference_t = typename add_lvalue_reference<_Ty>::type;

// ===== remove_pointer =====
template<typename _Ty>
struct remove_pointer
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_pointer<_Ty*>
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_pointer<_Ty* const>
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_pointer<_Ty* volatile>
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_pointer<_Ty* const volatile>
{
  using type = _Ty;
};

template<typename _Ty>
using remove_pointer_t = typename remove_pointer<_Ty>::type;

// ===== add_pointer =====
template<typename _Ty>
struct add_pointer
{
  using type = typename remove_reference<_Ty>::type*;
};

template<typename _Ty>
using add_pointer_t = typename add_pointer<_Ty>::type;

// ===== make_signed =====

// TODO : Add support for cv-qualifiers
// Check work in progress for _make_signed in traits_internal.hpp
template<typename _Ty>
struct make_signed
{
  using type = _Ty;
};

template<>
struct make_signed<unsigned char>
{
  using type = signed char;
};

template<>
struct make_signed<unsigned short>
{
  using type = signed short;
};

template<>
struct make_signed<unsigned int>
{
  using type = signed int;
};

template<>
struct make_signed<unsigned long>
{
  using type = signed long;
};

template<>
struct make_signed<unsigned long long>
{
  using type = signed long long;
};

template<typename _Ty>
using make_signed_t = typename make_signed<_Ty>::type;

// ===== make_unsigned =====
template<typename _Ty>
struct make_unsigned
{
  using type = _Ty;
};

template<>
struct make_unsigned<signed char>
{
  using type = unsigned char;
};

template<>
struct make_unsigned<signed short>
{
  using type = unsigned short;
};

template<>
struct make_unsigned<signed int>
{
  using type = unsigned int;
};

template<>
struct make_unsigned<signed long>
{
  using type = unsigned long;
};

template<>
struct make_unsigned<signed long long>
{
  using type = unsigned long long;
};

template<typename _Ty>
using make_unsigned_t = typename make_unsigned<_Ty>::type;

// ===== remove_extent =====
template<typename _Ty>
struct remove_extent
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_extent<_Ty[]>
{
  using type = _Ty;
};

template<typename _Ty, size_t _Size>
struct remove_extent<_Ty[_Size]>
{
  using type = _Ty;
};

template<typename _Ty>
using remove_extent_t = typename remove_extent<_Ty>::type;

// ===== remove_all_extents =====
template<typename _Ty>
struct remove_all_extents
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_all_extents<_Ty[]>
{
  using type = typename remove_all_extents<_Ty>::type;
};

template<typename _Ty, size_t _Size>
struct remove_all_extents<_Ty[_Size]>
{
  using type = typename remove_all_extents<_Ty>::type;
};

template<typename _Ty>
using remove_all_extents_t = typename remove_all_extents<_Ty>::type;

// ===== remove_const =====
template<typename _Ty>
struct remove_const
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_const<const _Ty>
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_const<const _Ty[]>
{
  using type = _Ty[];
};

template<typename _Ty>
using remove_const_t = typename remove_const<_Ty>::type;

// ===== remove_volatile =====
template<typename _Ty>
struct remove_volatile
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_volatile<volatile _Ty>
{
  using type = _Ty;
};

template<typename _Ty>
struct remove_volatile<volatile _Ty[]>
{
  using type = _Ty[];
};

template<typename _Ty>
using remove_volatile_t = typename remove_volatile<_Ty>::type;

// ===== remove_cv =====
template<typename _Ty>
struct remove_cv
{
  using type = typename remove_volatile<typename remove_const<_Ty>::type>::type;
};

template<typename _Ty>
using remove_cv_t = typename remove_cv<_Ty>::type;

// ===== add_const =====
template<typename _Ty>
struct add_const
{
  using type = const _Ty;
};

template<typename _Ty>
struct add_const<_Ty[]>
{
  using type = const _Ty[];
};

template<typename _Ty, size_t _Size>
struct add_const<_Ty[_Size]>
{
  using type = const _Ty[_Size];
};

template<typename _Ty>
using add_const_t = typename add_const<_Ty>::type;

// ===== add_volatile =====
template<typename _Ty>
struct add_volatile
{
  using type = volatile _Ty;
};

template<typename _Ty>
struct add_volatile<_Ty[]>
{
  using type = volatile _Ty[];
};

template<typename _Ty, size_t _Size>
struct add_volatile<_Ty[_Size]>
{
  using type = volatile _Ty[_Size];
};

template<typename _Ty>
using add_volatile_t = typename add_volatile<_Ty>::type;

// ===== add_cv =====
template<typename _Ty>
struct add_cv
{
  using type = typename add_volatile<typename add_const<_Ty>::type>::type;
};

template<typename _Ty>
using add_cv_t = typename add_cv<_Ty>::type;

// ===== remove_cvref =====
template<typename _Ty>
struct remove_cvref
{
  using type = typename remove_cv<typename remove_reference<_Ty>::type>::type;
};

template<typename _Ty>
using remove_cvref_t = typename remove_cvref<_Ty>::type;


// ==========================================================================================
// ====== Type Transformations =======================================
// ==========================================================================================

// ===== aligned_storage =====

// TODO

// ===== aligned_union =====

// TODO

// ===== decay =====
template<typename _Ty>
struct decay {
private:
    using U = typename xstl::remove_reference<_Ty>::type;
public:
    using type = typename xstl::conditional<xstl::is_array<U>::value, typename xstl::add_pointer<typename xstl::remove_extent<U>::type>::type, typename xstl::conditional<xstl::is_function<U>::value, typename xstl::add_pointer<U>::type, typename xstl::remove_cv<U>::type>::type>::type;
};

template<typename _Ty>
using decay_t = typename decay<_Ty>::type;

// ===== enable_if =====
template<bool, typename _Ty>
struct enable_if
{};

// Partial specialization for `enable_if` when first template arg is `true`
template<typename _Ty>
struct enable_if<true, _Ty>
{
	using type = _Ty;
};


// Alias template for extracting the `type` member from `enable_if`
template<bool _Cond, typename _Ty = void>
using enable_if_t = typename enable_if<_Cond, _Ty>::type;

// ===== conditional =====
template<bool _Cond, typename _Ty1, typename _Ty2>
struct conditional
{
  using type = _Ty1;
};

template<typename _Ty1, typename _Ty2>
struct conditional<false, _Ty1, _Ty2>
{
  using type = _Ty2;
};

template<bool _Cond, typename _Ty1, typename _Ty2>
using conditional_t = typename conditional<_Cond, _Ty1, _Ty2>::type;

// ===== common_type =====
template<typename... _Types>
struct common_type {
  // TODO
};

// ===== common_reference =====
template<typename... _Types>
struct common_reference {
  // TODO
};

// ===== basic_common_reference =====
template<typename... _Tys>
struct basic_common_reference {
  // TODO
};

// ===== underlying_type =====
template <typename _Ty, typename = void>
struct underlying_type_impl {};

template <typename _Ty>
struct underlying_type_impl<_Ty, std::enable_if_t<std::is_enum<_Ty>::value>> {
  using type = __underlying_type(_Ty);
};

template <typename _Ty>
struct underlying_type : underlying_type_impl<_Ty> {};

template <typename _Ty>
using underlying_type_t = typename underlying_type_impl<_Ty>::type;

// ===== result_of =====
template<typename _Fn, typename... _Args>
struct result_of {
  // TODO
};

// ===== invoke_result =====
template<typename _Fn, typename... _Args>
struct invoke_result {
  // TODO
};

// ===== type_identity =====
template<typename _Ty>
struct type_identity {
  using type = _Ty;
};

template<typename _Ty>
using type_identity_t = typename type_identity<_Ty>::type;

// ==========================================================================================
// ====== Operations on Traits =======================================
// ==========================================================================================
template<typename... _Bs>
struct conjunction : true_type
{};

template<typename _B1>
struct conjunction<_B1> : _B1
{};

template<typename _B1, typename... _Bn>
struct conjunction<_B1, _Bn...> : conditional_t<bool(_B1::value), conjunction<_Bn...>, _B1>
{};

#ifdef __cpp_inline_variables
// Helper variable template
template<typename... _Bs>
XSTL_INLINE_VAR constexpr bool conjunction_v = conjunction<_Bs...>::value;
#else
// Helper variable template
template<typename... _Bs>
constexpr bool conjunction_v = conjunction<_Bs...>::value;
#endif

template<typename... _Bs>
struct disjunction : false_type
{};

template<typename _B1>
struct disjunction<_B1> : _B1
{};

template<typename _B1, typename... _Bn>
struct disjunction<_B1, _Bn...> : conditional_t<bool(_B1::value), _B1, disjunction<_Bn...>>
{};

#ifdef __cpp_inline_variables
// Helper variable template
template<typename... _Bs>
XSTL_INLINE_VAR constexpr bool disjunction_v = disjunction<_Bs...>::value;
#else
// Helper variable template
template<typename... _Bs>
constexpr bool disjunction_v = disjunction<_Bs...>::value;
#endif

template<typename _B>
struct negation : bool_constant<!bool(_B::value)>
{};

#ifdef __cpp_inline_variables
// Helper variable template
template<typename _B>
XSTL_INLINE_VAR constexpr bool negation_v = negation<_B>::value;
#else
// Helper variable template
template<typename _B>
constexpr bool negation_v = negation<_B>::value;
#endif

// ==========================================================================================
// ====== Primary Type Categories =======================================
// ==========================================================================================
template<typename _Ty>
struct is_void : false_type
{};

template<>
struct is_void<void> : true_type
{};

template<>
struct is_void<const void> : true_type
{};

template<>
struct is_void<volatile void> : true_type
{};

// Helper variable template
#ifdef __cpp_inline_variables
template<typename _Ty>
XSTL_INLINE_VAR constexpr bool is_void_v = is_void<_Ty>::value;
#else
template<typename _Ty>
constexpr bool is_void_v = is_void<_Ty>::value;
#endif

// ==========================================================================================

template<typename _Ty>
struct is_null_pointer : false_type
{};

template<>
struct is_null_pointer<std::nullptr_t> : true_type
{};

// Helper variable template
#ifdef __cpp_inline_variables
template<typename _Ty>
XSTL_INLINE_VAR constexpr bool is_null_pointer_v = is_null_pointer<_Ty>::value;
#else
template<typename _Ty>
constexpr bool is_null_pointer_v = is_null_pointer<_Ty>::value;
#endif

// ==========================================================================================

template<typename _Ty>
struct is_integral : false_type
{};

template<>
struct is_integral<bool> : true_type
{};

template<>
struct is_integral<char> : true_type
{};

template<>
struct is_integral<signed char> : true_type
{};

template<>
struct is_integral<unsigned char> : true_type
{};

template<>
struct is_integral<wchar_t> : true_type
{};

template<>
struct is_integral<char16_t> : true_type
{};

template<>
struct is_integral<char32_t> : true_type
{};

template<>
struct is_integral<short> : true_type
{};

template<>
struct is_integral<unsigned short> : true_type
{};

template<>
struct is_integral<int> : true_type
{};

template<>
struct is_integral<unsigned int> : true_type
{};

template<>
struct is_integral<long> : true_type
{};

template<>
struct is_integral<unsigned long> : true_type
{};

template<>
struct is_integral<long long> : true_type
{};

template<>
struct is_integral<unsigned long long> : true_type
{};

// Helper variable template
#ifdef __cpp_inline_variables
template<typename _Ty>
XSTL_INLINE_VAR constexpr bool is_integral_v = is_integral<_Ty>::value;
#else
template<typename _Ty>
constexpr bool is_integral_v = is_integral<_Ty>::value;
#endif

// ==========================================================================================
template<typename _Ty>
struct is_floating_point : false_type
{};

template<>
struct is_floating_point<float> : true_type
{};

template<>
struct is_floating_point<double> : true_type
{};

template<>
struct is_floating_point<long double> : true_type
{};

// Helper variable template
#ifdef __cpp_inline_variables
template<typename _Ty>
XSTL_INLINE_VAR constexpr bool is_floating_point_v = is_floating_point<_Ty>::value;
#else
template<typename _Ty>
constexpr bool is_floating_point_v = is_floating_point<_Ty>::value;
#endif

// ==========================================================================================

template<typename _Ty>
struct is_array : false_type
{};

template<typename _Ty, size_t _Size>
struct is_array<_Ty[_Size]> : true_type
{};

template<typename _Ty>
struct is_array<_Ty[]> : true_type
{};

// Helper variable template
#ifdef __cpp_inline_variables
template<typename _Ty>
XSTL_INLINE_VAR constexpr bool is_array_v = is_array<_Ty>::value;
#else
template<typename _Ty>
constexpr bool is_array_v = is_array<_Ty>::value;
#endif

_END_XSTL

#endif // !_TYPE_TRAITS_HPP_