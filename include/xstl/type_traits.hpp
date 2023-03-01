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

/**
 * 
*/



#ifndef _TYPE_TRAITS_HPP_
#define _TYPE_TRAITS_HPP_

#include "xstl/config/config.h"

_BEGIN_XSTL

template<typename T>
struct remove_reference
{
    typedef T type;
};

template<typename T>
struct remove_reference<T&>
{
    typedef T type;
};

template<typename T>
struct remove_reference<T&&>
{
    typedef T type;
};

template<typename T>
struct remove_const
{
    typedef T type;
};

template<typename T>
struct remove_const<const T>
{
    typedef T type;
};

template<typename T>
struct remove_volatile
{
    typedef T type;
};

template<typename T>
struct remove_volatile<volatile T>
{
    typedef T type;
};

template<typename T>
struct remove_cv
{
    typedef typename remove_volatile<typename remove_const<T>::type>::type type;
};

template<typename T>
struct is_const
{
    static constexpr bool value = false;
};

template<typename T>
struct is_const<const T>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_volatile
{
    static constexpr bool value = false;
};

template<typename T>
struct is_volatile<volatile T>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_pointer
{
    static constexpr bool value = false;
};

template<typename T>
struct is_pointer<T*>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_array
{
    static constexpr bool value = false;
};

template<typename T, std::size_t N>
struct is_array<T[N]>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_reference
{
    static constexpr bool value = false;
};

template<typename T>
struct is_reference<T&>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_reference<T&&>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_lvalue_reference
{
    static constexpr bool value = false;
};

template<typename T>
struct is_lvalue_reference<T&>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_rvalue_reference
{
    static constexpr bool value = false;
};

template<typename T>
struct is_rvalue_reference<T&&>
{
    static constexpr bool value = true;
};

template<typename T>
struct is_void
{
    static constexpr bool value = false;
};

// template<>
// struct is_void<void>
// {
//     static constexpr

_END_XSTL


#endif // !_TYPE_TRAITS_HPP_