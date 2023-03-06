/**
 * @file traits_fwd.hpp
 * @brief Forward declarations of type traits.
 * @version 0.1
 * @date 2021-01-09
 * 
*/

#ifndef _XSTL_TRAITS_FWD_HPP_
#define _XSTL_TRAITS_FWD_HPP_

#include <cstddef>

#include "xstl/config/config.h"

_BEGIN_XSTL

// ==========================================================================================
// ====== Type Traits Forward Declarations =================================
// ==========================================================================================

// =========== Primary type categories ===========

/**
 * @brief Type trait to check if a type is void.
 *
 * @tparam T Type to check.
 * @return true if T is void.
 * @return false if T is not void.
 */
template<typename>
struct is_void;

/**
 * @brief Type trait to check if a type is null pointer.
 *
 * @tparam T Type to check.
 * @return true if T is null pointer.
 * @return false if T is not null pointer.
 */
template<typename>
struct is_null_pointer;

/**
 * @brief Type trait to check if a type is integral.
 *
 * Checks whether T is an integral type. Provides the member constant value
 * which is equal to true, if T is the type bool, char, char8_t (since C++20),
 * char16_t, char32_t, wchar_t, short, int, long, long long, or any
 * implementation-defined extended integer types, including any signed,
 * unsigned, and cv-qualified variants. Otherwise, value is equal to false.
 *
 * @tparam T Type to check.
 * @return true if T is integral.
 */
template<typename>
struct is_integral;

/**
 * @brief Type trait to check if a type is floating point.
 *
 * Checks whether T is a floating point type. Provides the member constant value
 * which is equal to true, if T is the type float, double, long double, or any
 * implementation-defined extended floating point types, including any
 * cv-qualified variants. Otherwise, value is equal to false.
 *
 * @tparam T Type to check.
 * @return true if T is floating point.
 * @return false if T is not floating point.
 */
template<typename>
struct is_floating_point;

/**
 * @brief Type trait to check if a type is array.
 *
 * Checks whether T is an array type. Provides the member constant value which
 * is equal to true, if T is an array type. Otherwise, value is equal to false.
 *
 * @tparam T Type to check.
 * @return true if T is array.
 * @return false if T is not array.
 */
template<typename>
struct is_array;

/**
 * @brief Type trait to check if a type is enum.
 *
 * Checks whether T is an enumeration type. Provides the member constant value
 * which is equal to true, if T is an enumeration type. Otherwise, value is
 * equal to false.
 *
 * @tparam T Type to check.
 * @return true if T is enum.
 * @return false if T is not enum.
 */
template<typename>
struct is_enum;

/**
 * @brief Type trait to check if a type is union.
 *
 * Checks whether T is a union type. Provides the member constant value which is
 * equal to true, if T is a union type. Otherwise, value is equal to false.
 *
 * @tparam T Type to check.
 * @return true if T is union.
 * @return false if T is not union.
 */
template<typename>
struct is_union;

/**
 * @brief Type trait to check if a type is class.
 *
 * Checks whether T is a class type. Provides the member constant value which is
 * equal to true, if T is a class type. Otherwise, value is equal to false.
 *
 * @tparam T Type to check.
 * @return true if T is class.
 * @return false if T is not class.
 */
template<typename>
struct is_class;

/**
 * @brief Type trait to check if a type is function.
 *
 * Checks whether T is a function type. Provides the member constant value which
 * is equal to true, if T is a function type. Otherwise, value is equal to
 * false.
 *
 * @tparam T Type to check.
 * @return true if T is function.
 * @return false if T is not function.
 */
template<typename>
struct is_function;

/**
 * @brief Type trait to check if a type is pointer
 *
 * Checks whether T is a pointer type. Provides the member constant value which
 * is equal to true, if T is a pointer type. Otherwise, value is equal to false.
 */
template<typename>
struct is_pointer;

/**
 * @brief Type trait to check if a type is lvalue reference.
 *
 * Checks whether T is an lvalue reference type. Provides the member constant
 * value which is equal to true, if T is an lvalue reference type. Otherwise,
 * value is equal to false.
 */
template<typename>
struct is_lvalue_reference;

/**
 * @brief Type trait to check if a type is rvalue reference.
 *
 * Checks whether T is an rvalue reference type. Provides the member constant
 * value which is equal to true, if T is an rvalue reference type. Otherwise,
 * value is equal to false.
 */
template<typename>
struct is_rvalue_reference;

/**
 * @brief Type trait to check if a type is member object pointer.
 *
 * Checks whether T is a member object pointer type. Provides the member
 * constant value which is equal to true, if T is a member object pointer type.
 * Otherwise, value is equal to false.
 */
template<typename>
struct is_member_object_pointer;

/**
 * @brief Type trait to check if a type is member function pointer.
 *
 * Checks whether T is a member function pointer type. Provides the member
 * constant value which is equal to true, if T is a member function pointer
 * type. Otherwise, value is equal to false.
 */
template<typename>
struct is_member_function_pointer;

// ============================================================================

// ============= Composite type categories =============

/**
 * @brief Type trait to check if a type is fundamental.
 *
 * Checks whether T is a fundamental type. Provides the member constant value
 * which is equal to true, if T is integral, floating point, void, or null
 * pointer. Otherwise, value is equal to false.
 */
template<typename>
struct is_fundamental;

/**
 * @brief Type trait to check if a type is arithmetic.
 *
 * Checks whether T is an arithmetic type. Provides the member constant value
 * which is equal to true, if T is integral or floating point. Otherwise, value
 * is equal to false.
 */
template<typename>
struct is_arithmetic;

/**
 * @brief Type trait to check if a type is scalar.
 *
 * Checks whether T is a scalar type. Provides the member constant value which
 * is equal to true, if T is arithmetic, pointer, or enumeration. Otherwise,
 * value is equal to false.
 */
template<typename>
struct is_scalar;
/**
 * @brief Type trait to check if a type is object.
 *
 * Checks whether T is an object type. Provides the member constant value which
 * is equal to true, if T is a non-reference, non-function, non-void type.
 * Otherwise, value is equal to false.
 */
template<typename>
struct is_object;
/**
 * @brief Type trait to check if a type is compound.
 *
 * Checks whether T is a compound type. Provides the member constant value which
 * is equal to true, if T is an array, function, pointer, reference, or member
 * pointer type. Otherwise, value is equal to false.
 */
template<typename>
struct is_compound;
/**
 * @brief Type trait to check if a type is reference.
 *
 * Checks whether T is a reference type. Provides the member constant value
 * which is equal to true, if T is an lvalue or rvalue reference type.
 * Otherwise, value is equal to false.
 */
template<typename>
struct is_reference;
/**
 * @brief Type trait to check if a type is member pointer.
 *
 * Checks whether T is a member pointer type. Provides the member constant value
 * which is equal to true, if T is a member object pointer or member function
 * pointer type. Otherwise, value is equal to false.
 */
template<typename>
struct is_member_pointer;

// ============================================================================

// ============= Type properties ==================

/**
 * @brief Type trait to check if a type is const-qualified.
 */
template<typename>
struct is_const;

/**
 * @brief Type trait to check if a type is volatile-qualified.
 *
 * Checks whether T is a volatile-qualified type. Provides the member constant
 * value which is equal to true, if T is a volatile-qualified type. Otherwise,
 * value is equal to false.
 */
template<typename>
struct is_volatile;

/**
 * @brief Type trait to check if a type is trivial.
 *
 * Checks whether T is a trivial type. Provides the member constant value which
 * is equal to true, if T is a trivial type. Otherwise, value is equal to false.
 *
 * a trivial type is a class type that has no non-trivial special member
 * functions (constructors, copy/move assignment operators, or destructors), no
 * non-trivial default constructors, and no virtual functions (since C++11).
 */
template<typename>
struct is_trivial;

/**
 * @brief Type trait to check if a type is trivially copyable.
 *
 * Checks whether T is a trivially copyable type. Provides the member constant
 * value which is equal to true, if T is a trivially copyable type. Otherwise,
 * value is equal to false.
 *
 * a tryvially copyable type is a class type that has no non-trivial special
 * member functions (constructors, copy/move assignment operators, or
 * destructors), no non-trivial default constructors, and no virtual functions
 * (since C++11).
 */
template<typename>
struct is_trivially_copyable;

/**
 * @brief Type trait to check if a type is standard layout.
 *
 * Checks whether T is a standard layout type. Provides the member constant
 * value which is equal to true, if T is a standard layout type. Otherwise,
 * value is equal to false.
 *
 * standard layout class is a class (defined with class, struct or union) that
 * has no non-static data members of type non-standard-layout class or union, no
 * virtual functions, no virtual base classes, and no base classes of type
 * non-standard-layout class or union. has the same access control (public,
 * protected, or private) for all non-static data members and base classes.
 */
template<typename>
struct is_standard_layout;

/**
 * @brief Type trait to check if a type is POD.
 *
 * Checks whether T is a POD type. Provides the member constant value which is
 * equal to true, if T is a POD type. Otherwise, value is equal to false.
 *
 * A POD class (Plain Old Class) is a type that is a type whose characteristics
 * are supported by a data type in the C language, either cv-qualified or not.
 * This includes scalar types, POD classes and arrays of any such types. POD is
 * both trivial (can only be statically initialized) and standard-layout (has a
 * simple data structure), and thus is mostly restricted to the characteristics
 * of a class that are compatible with those of a C data structure declared with
 * struct or union in that language, even though the expanded C++ grammar can be
 * used in their declaration and can have member functions.
 */
template<typename>
struct is_pod;

/**
 * @brief Type trait to check if a type is literal.
 *
 * Checks whether T is a literal type. Provides the member constant value which
 * is equal to true, if T is a literal type. Otherwise, value is equal to false.
 *
 * A literal type is a class that qualifies as a `constxpr`. This is true for
 * scalar types, arrays of literal types, references and classes with only
 * static data members of literal types.
 *
 * A class that is a literal type is a class (defined with class, struct or
 * union) that: has a trivial destructor, every constructor call and any
 * non-static data member that has brace- or equal- initializers is a constant
 * expression, is an aggregate type, or has at least one constexpr constructor
 * or constructor template that is not a copy or move constructor, and has all
 * non-static data members and base classes of literal types
 */
template<typename>
struct is_literal_type;

/**
 * @brief Type trait to check if a type is empty.
 *
 * Checks whether T is an empty type. Provides the member constant value which
 * is equal to true, if T is an empty type. Otherwise, value is equal to false.
 *
 * An empty class is a class type that has no non-static data members other than
 * bit-fields (since C++11), no virtual functions, no virtual base classes, and
 * no base classes of type non-empty class (since C++11).
 */
template<typename>
struct is_empty;

/**
 * @brief Type trait to check if a type is polymorphic.
 *
 * Checks whether T is a polymorphic type. Provides the member constant value
 * which is equal to true, if T is a polymorphic type. Otherwise, value is equal
 * to false.
 *
 * A polymorphic class is a class that has at least one virtual function or
 * virtual base class.
 */
template<typename>
struct is_polymorphic;

/**
 * @brief Type trait to check if a type is abstract.
 *
 * Checks whether T is an abstract type. Provides the member constant value
 * which is equal to true, if T is an abstract type. Otherwise, value is equal
 * to false.
 *
 * An abstract class is a class that has at least one pure virtual function.
 */
template<typename>
struct is_abstract;

/**
 * @brief Type trait to check if a type is signed.
 *
 * Checks whether T is a signed type. Provides the member constant value which
 * is equal to true, if T is a signed type. Otherwise, value is equal to false.
 *
 * A signed type is a type that is either a signed integer type or a
 * floating-point type.
 */
template<typename>
struct is_signed;

/**
 * @brief Type trait to check if a type is unsigned.
 *
 * Checks whether T is an unsigned type. Provides the member constant value
 * which is equal to true, if T is an unsigned type. Otherwise, value is equal
 * to false.
 *
 * An unsigned type is a type that is either an unsigned integer type or a
 * floating-point type.
 */
template<typename>
struct is_unsigned;

/**
 * @brief Type trait to check if a type is a bounded array.
 *
 * Checks whether T is a bounded array type. Provides the member constant value
 * which is equal to true, if T is a bounded array type. Otherwise, value is
 * equal to false.
 *
 * A bounded array type is an array type with a known bound.
 */
template<typename>
struct is_bounded_array;

/**
 * @brief Type trait to check if a type is an unbounded array.
 *
 * Checks whether T is an unbounded array type. Provides the member constant
 * value which is equal to true, if T is an unbounded array type. Otherwise,
 * value is equal to false.
 *
 * An unbounded array type is an array type with an unknown bound.
 */
template<typename>
struct is_unbounded_array;

/**
 * @brief Type trait to check if a type is a scoped enum.
 *
 * Checks whether T is a scoped enum type. Provides the member constant value
 * which is equal to true, if T is a scoped enum type. Otherwise, value is equal
 * to false.
 *
 * A scoped enum type is an enum type that is not declared with the `enum`
 * keyword.
 */
template<typename>
struct is_scoped_enum;

/**
 * @brief Type trait to check if a type is final.
 *
 * Checks whether T is a final type. Provides the member constant value which is
 * equal to true, if T is a final type. Otherwise, value is equal to false.
 *
 * A final class is a class that is declared with the `final` specifier.
 */
template<typename>
struct is_final;

/**
 * @brief Type trait to check if a type is an aggregate.
 *
 * Checks whether T is an aggregate type. Provides the member constant value
 * which is equal to true, if T is an aggregate type. Otherwise, value is equal
 * to false.
 *
 * An aggregate type is a class type that has no user-declared constructors, no
 * private or protected non-static data members, no base classes, and no virtual
 * functions (since C++11).
 */
template<typename>
struct is_aggregate;

/**
 * @brief Type trait to check if a type has a unique object representation.
 *
 * Checks whether T has a unique object representation. Provides the member
 * constant value which is equal to true, if T has a unique object
 * representation. Otherwise, value is equal to false.
 *
 * A type has a unique object representation if it is a scalar type, a reference
 * type, a class type with no non-static data members other than bit-fields
 * (since C++11), a class type with no base classes and no virtual functions
 * (since C++11).
 */
template<typename>
struct has_unique_object_representations;

#if __cplusplus > 202003L
/**
 * @brief Type trait to check if a type is implicit lifetime.
 *
 * Checks whether T is an implicit lifetime type. Provides the member constant
 * value which is equal to true, if T is an implicit lifetime type. Otherwise,
 * value is equal to false.
 *
 */
template<typename>
struct is_implicit_lifetime;
#endif
// ==========================================================================================

// =============== Supported Operations ==============

/**
 * @brief Type trait to check if a type is constructible.
 *
 * Checks whether T is constructible from the given arguments. Provides the
 * member constant value which is equal to true, if T is constructible from the
 * given arguments. Otherwise, value is equal to false.
 *
 * A type is constructible if the expression `new T(std::declval<Args>()...)` is
 * well-formed and has no effects that would require the destruction of an
 * object.
 */
template<typename, typename>
struct is_constructible;

/**
 * @brief Type trait to check if a type is nothrow constructible.
 *
 * Checks whether T is nothrow constructible from the given arguments. Provides
 * the member constant value which is equal to true, if T is nothrow
 * constructible from the given arguments. Otherwise, value is equal to false.
 *
 * A type is nothrow constructible if it is constructible and the expression
 * `new T(std::declval<Args>()...)` is well-formed and has no effects that would
 * require the destruction of an object.
 */
template<typename, typename>
struct is_nothrow_constructible;

/**
 * @brief Type trait to check if a type is trivially constructible.
 *
 * Checks whether T is trivially constructible from the given arguments.
 * Provides the member constant value which is equal to true, if T is trivially
 * constructible from the given arguments. Otherwise, value is equal to false.
 *
 * A type is trivially constructible if it is constructible and the expression
 * `new T(std::declval<Args>()...)` is well-formed and has no effects that would
 * require the destruction of an object.
 */
template<typename, typename>
struct is_trivially_constructible;

/**
 * @brief Type trait to check if a type is default constructible.
 *
 * Checks whether T is default constructible. Provides the member constant value
 * which is equal to true, if T is default constructible. Otherwise, value is
 * equal to false.
 *
 * A type is default constructible if it is constructible and the expression
 * `new T()` is well-formed and has no effects that would require the
 * destruction of an object.
 */
template<typename>
struct is_default_constructible;

/**
 * @brief Type trait to check if a type is nothrow default constructible.
 *
 * Checks whether T is nothrow default constructible. Provides the member
 * constant value which is equal to true, if T is nothrow default constructible.
 * Otherwise, value is equal to false.
 *
 * A type is nothrow default constructible if it is default constructible and
 * the expression `new T()` is well-formed and has no effects that would require
 * the destruction of an object.
 */
template<typename>
struct is_nothrow_default_constructible;

/**
 * @brief Type trait to check if a type is trivially default constructible.
 *
 * Checks whether T is trivially default constructible. Provides the member
 * constant value which is equal to true, if T is trivially default
 * constructible. Otherwise, value is equal to false.
 *
 * A type is trivially default constructible if it is default constructible and
 * the expression `new T()` is well-formed and has no effects that would require
 * the destruction of an object.
 */
template<typename>
struct is_trivially_default_constructible;

/**
 * @brief Type trait to check if a type is move constructible.
 *
 * Checks whether T is move constructible. Provides the member constant value
 * which is equal to true, if T is move constructible. Otherwise, value is equal
 * to false.
 *
 * A type is move constructible if it is constructible and the expression `new
 * T(std::move(std::declval<Args>()...))` is well-formed and has no effects that
 * would require the destruction of an object.
 */
template<typename>
struct is_move_constructible;

/**
 * @brief Type trait to check if a type is nothrow move constructible.
 *
 * Checks whether T is nothrow move constructible. Provides the member constant
 * value which is equal to true, if T is nothrow move constructible. Otherwise,
 * value is equal to false.
 *
 * A type is nothrow move constructible if it is constructible and the
 * expression `new T(std::move(std::declval<Args>()...))` is well-formed and has
 * no effects that would require the destruction of an object.
 */
template<typename>
struct is_nothrow_move_constructible;

/**
 * @brief Type trait to check if a type is trivially move constructible.
 *
 * Checks whether T is trivially move constructible. Provides the member
 * constant value which is equal to true, if T is trivially move constructible.
 * Otherwise, value is equal to false.
 *
 * A type is trivially move constructible if it is constructible and the
 * expression `new T(std::move(std::declval<Args>()...))` is well-formed and has
 * no effects that would require the destruction of an object.
 */
template<typename>
struct is_trivially_move_constructible;

/**
 * @brief Type trait to check if a type is copy constructible.
 *
 * Checks whether T is copy constructible. Provides the member constant value
 * which is equal to true, if T is copy constructible. Otherwise, value is equal
 * to false.
 */
template<typename>
struct is_copy_constructible;

/**
 * @brief Type trait to check if a type is nothrow copy constructible.
 *
 * Checks whether T is nothrow copy constructible. Provides the member constant
 * value which is equal to true, if T is nothrow copy constructible. Otherwise,
 * value is equal to false.
 */
template<typename>
struct is_nothrow_copy_constructible;

/**
 * @brief Type trait to check if a type is trivially copy constructible.
 *
 * Checks whether T is trivially copy constructible. Provides the member
 * constant value which is equal to true, if T is trivially copy constructible.
 * Otherwise, value is equal to false.
 */
template<typename>
struct is_trivially_copy_constructible;

/**
 * @brief Type trait to check if a type is assignable.
 *
 * Checks whether T is assignable from the given arguments. Provides the member
 * constant value which is equal to true, if T is assignable from the given
 * arguments. Otherwise, value is equal to false.
 */
template<typename>
struct is_assignable;

/**
 * @brief Type trait to check if a type is nothrow assignable.
 *
 * Checks whether T is nothrow assignable from the given arguments. Provides
 * the member constant value which is equal to true, if T is nothrow assignable
 */
template<typename>
struct is_nothrow_assignable;

/**
 * @brief Type trait to check if a type is trivially assignable.
 *
 * Checks whether T is trivially assignable from the given arguments. Provides
 * the member constant value which is equal to true, if T is trivially assignable
 */
template<typename>
struct is_trivially_assignable;

/**
 * @brief Type trait to check if a type is copy assignable.
 *
 * Checks whether T is copy assignable. Provides the member constant value which
 * is equal to true, if T is copy assignable. Otherwise, value is equal to false.
 */
template<typename>
struct is_copy_assignable;

/**
 * @brief Type trait to check if a type is nothrow copy assignable.
 *
 * Checks whether T is nothrow copy assignable. Provides the member constant
 *
 * value which is equal to true, if T is nothrow copy assignable.
 */
template<typename>
struct is_nothrow_copy_assignable;

/**
 * @brief Type trait to check if a type is trivially copy assignable.
 *
 * Checks whether T is trivially copy assignable. Provides the member constant
 * value which is equal to true, if T is trivially copy assignable.
 */
template<typename>
struct is_trivially_copy_assignable;

/**
 * @brief Type trait to check if a type is move assignable.
 *
 * Checks whether T is move assignable. Provides the member constant value which
 * is equal to true, if T is move assignable. Otherwise, value is equal to false.
 */
template<typename>
struct is_move_assignable;

/**
 * @brief Type trait to check if a type is nothrow move assignable.
 *
 * Checks whether T is nothrow move assignable. Provides the member constant
 * value which is equal to true, if T is nothrow move assignable.
 */
template<typename>
struct is_nothrow_move_assignable;

/**
 * @brief Type trait to check if a type is trivially move assignable.
 *
 * Checks whether T is trivially move assignable. Provides the member constant
 * value which is equal to true, if T is trivially move assignable.
 */
template<typename>
struct is_trivially_move_assignable;

/**
 * @brief Type trait to check if a type is destructible.
 *
 * Checks whether T is destructible. Provides the member constant value which is
 * equal to true, if T is destructible. Otherwise, value is equal to false.
 */
template<typename>
struct is_destructible;

/**
 * @brief Type trait to check if a type is nothrow destructible.
 *
 * Checks whether T is nothrow destructible. Provides the member constant value
 *
 * which is equal to true, if T is nothrow destructible.
 */
template<typename>
struct is_nothrow_destructible;

/**
 * @brief Type trait to check if a type is trivially destructible.
 *
 * Checks whether T is trivially destructible. Provides the member constant
 *
 * value which is equal to true, if T is trivially destructible.
 */
template<typename>
struct is_trivially_destructible;

/**
 * @brief Type trait to check if a type has a virtual destructor.
 *
 * Checks whether T has a virtual destructor. Provides the member constant value which is
 * equal to true, if T has a virtual destructor. Otherwise, value is equal to false.
 */
template<typename>
struct has_virtual_destructor;

/**
 * @brief Type trait to check if a type is swappable with another type.
 *
 * Checks whether T is swappable with U. Provides the member constant value which is
 * equal to true, if T is swappable with U. Otherwise, value is equal to false.
 */
template<typename, typename>
struct is_swapppable_with;

/**
 * @brief Type trait to check if a type is swappable.
 *
 * Checks whether T is swappable. Provides the member constant value which is
 * equal to true, if T is swappable. Otherwise, value is equal to false.
 */
template<typename>
struct is_swappable;

/**
 * @brief Type trait to check if a type is nothrow swappable.
 *
 * Checks whether T is nothrow swappable. Provides the member constant value which is
 * equal to true, if T is nothrow swappable. Otherwise, value is equal to false.
 */
template<typename>
struct is_nothrow_swappable;

// ==========================================================================================

// ============== Properties queries =============

/**
 * @brief Type trait to check type alignment.
 *
 * Checks the alignment of T. Provides the member constant value which is equal
 * to the alignment of T.
 */
template<typename>
struct alignment_of;

/**
 * @brief Type trait to obtain the number of dimensions of an array type.
 *
 * Provides the member constant value which is equal to the number of dimensions
 * of T. If T is not an array type, value is equal to 0.
 */
template<typename>
struct rank;

/**
 * @brief Type trait to obtain the extent of an array type.
 *
 * Provides the member constant value which is equal to the extent of T in the
 * specified dimension. If T is not an array type, value is equal to 0. If T is
 * an array type and N is greater than the number of dimensions of T, value is
 * equal to 0.
 */
template<typename, unsigned = 0>
struct extent;

// ==========================================================================================

// ============== Type Relationships =============

/**
 * @brief Type trait to check if a type is same as another type.
 *
 * Checks whether T and U name the same type. Provides the member constant
 * value which is equal to true, if T and U name the same type. Otherwise,
 */
template<typename, typename>
struct is_same;

/**
 * @brief Type trait to check if a type is derived from another type.
 *
 * Checks whether T is derived from U. Provides the member constant value which
 * is equal to true, if T is derived from U. Otherwise, value is equal to false.
 */
template<typename, typename>
struct is_base_of;

/**
 * @brief Type trait to check if a type is convertible to another type.
 *
 * Checks whether T is convertible to U. Provides the member constant value which
 * is equal to true, if T is convertible to U. Otherwise, value is equal to false.
 */
template<typename, typename>
struct is_convertible;

/**
 * @brief Type trait to check if a type is nothrow convertible to another type.
 *
 * Checks whether T is nothrow convertible to U. Provides the member constant
 * value which is equal to true, if T is nothrow convertible to U. Otherwise,
 * value is equal to false.
 */
template<typename, typename>
struct is_nothrow_convertible;

/**
 * @brief Type trait to check if a type can be invoked (as if by xstl::invoke) with the given argument types.
 *
  * `is_invocable` is a type trait that determines whether a type can be invoked (as if by xstl::invoke) with the given argument types.
  * `is_invocable_r` is a type trait that determines whether a type can be invoked (as if by xstl::invoke) with the given argument types and returns a result that is convertible to a given type.
  * `is_nothrow_invocable` is a type trait that determines whether a type can be invoked (as if by xstl::invoke) with the given argument types and does not throw an exception.
  * `is_nothrow_invocable_r` is a type trait that determines whether a type can be invoked (as if by xstl::invoke) with the given argument types and returns a result that is convertible to a given type and does not throw an exception.
 */
template<typename, typename...> struct is_invocable;
template<typename, typename...> struct is_invocable_r;
template<typename, typename...> struct is_nothrow_invocable;
template<typename, typename...> struct is_nothrow_invocable_r;

#ifdef XSTL_CXX23
template<typename, typename...> struct reference_constructs_from_temporary;
template<typename, typename...> struct reference_converts_from_temporary;
#endif

// cxx20

template<typename, typename> struct is_layout_compatible;
template<typename, typename> struct is_pointer_interconvertible_base_of;
template<typename, typename> struct is_pointer_interconvertible_with_class;
template<typename, typename> struct is_corresponding_member;

// ==========================================================================================

// ============== Operations on Traits =============

/**
 * @brief variadic logic AND operator.
 * 
 * Checks whether all types in the parameter pack are true. Provides the member constant
 * value which is equal to true, if all types in the parameter pack are true. Otherwise,
 * value is equal to false.
 */
template<typename...>
struct conjunction;

/**
 * @brief variadic logic OR operator.
 * 
 * Checks whether any type in the parameter pack is true. Provides the member constant
 * value which is equal to true, if any type in the parameter pack is true. Otherwise,
 * value is equal to false.
 */
template<typename...>
struct disjunction;

/**
 * @brief variadic logic NOT operator.
 * 
 * Checks whether the type is false. Provides the member constant
 * value which is equal to true, if the type is false. Otherwise,
 * value is equal to false.
 */
template<typename>
struct negation;

// ==========================================================================================

// ============== Base Classes =============

/**
 * @brief Base class for all type traits.
 *
 * Provides a member typedef type which is the type for which the type trait
 * is defined. Provides a member constant value which is the value of the
 * type trait.
 */
template<typename _Ty, _Ty _Val>
struct integral_constant;


/**
 * @brief Base class for all type traits that represent a boolean value.
 *
 * Provides a member constant value which is the value of the type trait.
 */
template<bool _Val>
using bool_constant = integral_constant<bool, _Val>;

/**
 * @brief Type trait for boolean true.
 *
 * Provides the member constant value which is equal to true.
 */
using true_type = bool_constant<true>;

/**
 * @brief Type trait for boolean false.
 *
 * Provides the member constant value which is equal to false.
 */
using false_type = bool_constant<false>;

// ==========================================================================================

// ============== Type Modification =============

/**
 * @brief Type trait to remove reference.
 *
 * Removes reference from a type. Provides the member typedef type which is the
 * type T with reference removed.
 */
template<typename>
struct remove_reference;


/**
 * @brief adds an rvalue reference to a type.
*/
template<typename>
struct add_rvalue_reference;

/**
 * @brief adds an lvalue reference to a type.
*/
template<typename>
struct add_lvalue_reference;

/**
 * @brief removes pointer from a type
*/
template<typename>
struct remove_pointer;

/**
 * @brief adds pointer to a type
*/
template<typename>
struct add_pointer;

/**
 * @brief make a type signed
*/
template<typename>
struct make_signed;

/**
 * @brief make a type unsigned
*/
template<typename>
struct make_unsigned;

/**
 * @brief remove one extent from an array type
*/
template<typename>
struct remove_extent;

/**
 * @brief remove all extents from an array type
*/
template<typename>
struct remove_all_extents;

/**
 * @brief remove const from a type
*/
template<typename>
struct remove_const;

/**
 * @brief remove volatile from a type
*/
template<typename>
struct remove_volatile;

/**
 * @brief remove const and volatile from a type
*/
template<typename>
struct remove_cv;

/**
 * @brief add const to a type
*/
template<typename>
struct add_const;

/**
 * @brief add volatile to a type
*/
template<typename>
struct add_volatile;

/**
 * @brief add const and volatile to a type
*/
template<typename>
struct add_cv;

/**
 * @brief remove reference and cv-qualifiers from a type
*/
template<typename>
struct remove_cvref;

/**
 * @brief defines the type suitable for use as uninitialized storage for types of given size
 * 
 * The member typedef type is an array type of size _Size and alignment _Align, suitable for
 * use as uninitialized storage for objects of any type whose size is at most _Size and whose
 * alignment is at most _Align.
 */
template<size_t _Size, size_t _Align = alignof(max_align_t)>
struct aligned_storage;

template<size_t _Size, size_t _Align = alignof(max_align_t)>
using aligned_storage_t = typename aligned_storage<_Size, _Align>::type;

/**
 * @brief defines the type suitable for use as uninitialized storage for all given types
 * 
 * The member typedef type is an array type of size _Size and alignment _Align, suitable for
 * use as uninitialized storage for objects of any type whose size is at most _Size and whose
 * alignment is at most _Align.
 */
template<size_t _Size, typename... _Types>
struct aligned_union;

/**
 * @brief applies type transformations as when passing a function argument by value
 * 
 * The member typedef type is the type that would be used to pass an object of type _Ty as an
 * argument to a function by value. This type is defined as follows: If _Ty is an array type,
 * the member type is an array of the same extent and element type as _Ty, except that the
 * element type is transformed as if by remove_reference. If _Ty is a function type, the
 * member type is a function type with the same return type and parameter types as _Ty, except
 * that each parameter type is transformed as if by remove_reference. If _Ty is a reference
 * type, the member type is the type referred to by _Ty. Otherwise, the member type is _Ty.
 */
template<typename _Ty>
struct decay;

/**
 * @brief conditionally removes a function overload or a template specialization from overload resolution
 * 
 * The member typedef type is defined as follows: If _Cond is true, the member type is _Ty. If
 * _Cond is false, the member type is void.
 */
template<bool, typename = void>
struct enable_if;

/**
 * @brief chooses one type or another based on compile-time boolean
 * 
 * The member typedef type is defined as follows: If _Cond is true, the member type is _Iftrue.
 * If _Cond is false, the member type is _Iffalse.
 */
template<bool _Cond, typename _Iftrue, typename _Iffalse>
struct conditional;

/**
 * @brief determines the common type of a group of types
 * 
 * The member typedef type is the common type of the types in the parameter pack _Types. If
 * there is no common type, the member type is not defined.
 */
template<typename... _Types>
struct common_type;

template<typename... _Types>
using common_type_t = typename common_type<_Types...>::type;

/**
 * @brief determines the common reference type of a group of types
 * 
 * The member typedef type is the common reference type of the types in the parameter pack
 * _Types. If there is no common reference type, the member type is not defined.
 */
template<typename... _Types>
struct common_reference;

template<typename...>
struct basic_common_reference;

/**
 * @brief determines the underlying type of an enumeration
 * 
 * The member typedef type is the underlying type of the enumeration type _Ty. If _Ty is not
 * an enumeration type, the member type is not defined.
*/
template<typename>
struct underlying_type;

/**
 * @brief determines the type of the result of applying a function to a set of arguments
 * 
 * The member typedef type is the type of the result of applying the function type _Fn to the
 * argument types _Args. If the function type _Fn is not a function type, the member type is
 * not defined.
 */
template<typename _Fn, typename... _Args>
struct result_of;

/**
 * @brief determines the type of the result of applying a function to a set of arguments
 * 
 * The member typedef type is the type of the result of applying the function type _Fn to the
 * argument types _Args. If the function type _Fn is not a function type, the member type is
 * not defined.
 */
template<typename _Fn, typename... _Args>
struct invoke_result;

/**
 * @brief void variadic alias template
 * 
 * The member typedef type is void.
 */
template<typename... _Types>
using void_t = void;

/**
 * @brief returns the type argument unchanged
*/
template<typename _Ty>
struct type_identity;


template<typename, typename...>
struct integer_sequence;

template<size_t... _Idx>
struct index_sequence;


// ======================================================================================
// ===================== Internal Use Only ====================
// ======================================================================================

_BEGIN_INTERNAL


template<bool>
struct _conditional
{
	template<typename _Tp, typename>
	using type = _Tp;
};

template<>
struct _conditional<false>
{
	template<typename, typename _Up>
	using type = _Up;
};

// More efficient version of xstl::conditional_t for internal use (and C++11)
template<bool _Cond, typename _If, typename _Else>
using _conditional_t = typename _conditional<_Cond>::template type<_If, _Else>;

template<typename _Type>
struct _type_identity
{
	using type = _Type;
};

template<typename _Tp>
using _type_identity_t = typename _type_identity<_Tp>::type;

template <typename _From, typename _To>
struct _xstl_match_cv_qualifiers
{
    using _type = _To;
};

template <typename _From, typename _To>
struct _xstl_match_cv_qualifiers<const _From, _To>
{
    using _type = const typename _xstl_match_cv_qualifiers<_From, _To>::_type;
};

template <typename _From, typename _To>
struct _xstl_match_cv_qualifiers<volatile _From, _To>
{
    typedef volatile typename _xstl_match_cv_qualifiers<_From, _To>::_type _type;
};

template <typename _From, typename _To>
struct _xstl_match_cv_qualifiers<const volatile _From, _To>
{
    typedef const volatile typename _xstl_match_cv_qualifiers<_From, _To>::_type _type;
};


// Utility for finding the signed versions of unsigned integral types.
template<typename _Ty>
struct _xstl_make_signed
{
  using _type = _Ty;
};

template<>
struct _xstl_make_signed<char>
{
  using _type = signed char;
};

template<>
struct _xstl_make_signed<unsigned char>
{
  using _type = signed char;
};

template<>
struct _xstl_make_signed<unsigned short>
{
  using _type = signed short;
};

template<>
struct _xstl_make_signed<unsigned int>
{
  using _type = signed int;
};

template<>
struct _xstl_make_signed<unsigned long>
{
  using _type = signed long;
};

template<>
struct _xstl_make_signed<unsigned long long>
{
  using _type = signed long long;
};

template<>
struct _xstl_make_signed<char16_t>
{
  using _type = char16_t;
};

template<>
struct _xstl_make_signed<char32_t>
{
  using _type = char32_t;
};

template<>
struct _xstl_make_signed<wchar_t>
{
  using _type = wchar_t;
};

// make signed selector

template<typename _Ty,
	bool _IsInt = is_integral<_Ty>::value,
	bool _IsEnum = is_enum<_Ty>::value
>
struct _xstl_make_signed_selector;

template<typename _Ty>
class _xstl_make_signed_selector<_Ty, true, false>
{
	using _signed_t = _xstl_make_signed<typename remove_cv<_Ty>::type>;
	using _signed_type = typename _signed_t::_type;
	using _cv_singed = _xstl_match_cv_qualifiers<_Ty, _signed_type>;
	
public:
	using type = typename _cv_singed::_type;
};

template<typename _Ty>
struct _xstl_make_signed_selector<_Ty, false, true>
{
	// MAYFAIL - _make_signed may fail with enum types
	using type = typename _xstl_make_signed<decay<_Ty>>::type;
};



_END_INTERNAL


_END_XSTL

#endif // !_XSTL_TRAITS_FWD_HPP_