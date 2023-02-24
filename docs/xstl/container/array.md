**Table of Contents**

- [Array](#array)
  - [Array Class](#array-class)
  - [Container Properties](#container-properties)
    - [Sequence](#sequence)
    - [Contiguous storage](#contiguous-storage)
    - [Fixed-size aggregate](#fixed-size-aggregate)
  - [Template Parameters](#template-parameters)
  - [Member Types](#member-types)
  - [Member Functions](#member-functions)
    - [Iterators](#iterators)
    - [Capacity](#capacity)
    - [Element Access](#element-access)
    - [Modifiers](#modifiers)
  - [Non-member Functions](#non-member-functions)
  - [Non-member Class Specializations](#non-member-class-specializations)
# Array #

**Header file**: `<array>`

**Arrays are fixed-size sequence containers: they hold a specific number of elements ordered in a strict linear sequence.**

**Classes**:

- array

**Class Templates**:

```cpp
template < class T, size_t N > class array;
```

## Array Class ##

Internally, an array does not keep any data other than the elements it contains (not even its size, which is a template parameter, fixed on compile time). It is as efficient in terms of storage size as an ordinary array declared with the language's bracket syntax ([]). This class merely adds a layer of member and global functions to it, so that arrays can be used as standard containers.

Unlike the other standard containers, arrays have a fixed size and do not manage the allocation of its elements through an allocator: they are an aggregate type encapsulating a fixed-size array of elements. Therefore, they cannot be expanded or contracted dynamically (see [vector]() for a similar container that can be expanded).

Zero-sized arrays are valid, but they should not be dereferenced (members [front](), [back](), and [data]()).

Unlike with the other containers in the Standard Library, swapping two array containers is a linear operation that involves swapping all the elements in the ranges individually, which generally is a considerably less efficient operation. On the other side, this allows the iterators to elements in both containers to keep their original container association.

Another unique feature of array containers is that they can be treated as [tuple]() objects: The `<array>` header overloads the [get]() function to access the elements of the array as if it was a [tuple](), as well as specialized [tuple_size]() and [tuple_element]() types.

## Container Properties ##

### Sequence ###

Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.

### Contiguous storage ##

The elements are stored in contiguous memory locations, allowing constant time random access to elements. Pointers to an element can be offset to access other elements.

### Fixed-size aggregate ##

The container uses implicit constructors and destructors to allocate the required space statically. Its size is compile-time constant. No memory or time overhead.

## Template Parameters ##

```cpp
T
```

&nbsp;&nbsp;&nbsp;&nbsp;Type of the elements contained.

&nbsp;&nbsp;&nbsp;&nbsp;Aliased as member type `array::value_type`.

```cpp
N
```

&nbsp;&nbsp;&nbsp;&nbsp;Size of the array, in terms of number of elements.

## Member Types ##

| Type        |  Definition | Notes       |
| ----------- | ----------- | ----------- |
| `value_type`| The first template parameter `T`  |
| `reference`   | `value_type&` |
| `const_reference`   | `const value_type&` |
| `pointer`   | `value_type*` |
| `const_pointer`   | `const value_type*` |
| `iterator`   | a [random access iterator]() to `value_type`|
| `const_iterator`   | a [random access iterator]() to `const value_type` |
| `reverse_iterator`   | `reverse_iterator<iterator>` |
| `const_reverse_iterator`   | `reverse_iterator<const_iterator>` |
| `size_type`   | `size_t` |
| `difference_type`   | `ptrdiff_t` |

## Member Functions ##

### Iterators ###

| Function   | Description |
| ----------- | ----------  |
| [`begin`]() | Return iterator to beginning
| [`end`]() | Return iterator to end
| [`rbegin`]() | Return reverse iterator to reverse beginning
| [`rend`]() | Return reverse iterator to reverse end
| [`cbegin`]() | Return const_iterator to beginning
| [`cend`]() | Return const_iterator to end
| [`crbegin`]() | Return const_reverse_iterator to reverse beginning
| [`crend`]() | Return const_reverse_iterator to reverse end

### Capacity ###

| Function   | Description |
| ----------- | ----------  |
| [`size`]()| Return size
| [`max_size`]()| Return maximum size
| [`empty`]()| Test whether array is empty

### Element Access ###

| Function   | Description |
| ----------- | ----------  |
| [`at`]() | Access element
| [`front`]() | Access first element
| [`back`]() | Access last element
| [`data`]() | Get pointer to data

### Modifiers ###

| Function   | Description |
| ----------- | ----------  |
| [`fill`]() | Fill array with value
| [`swap`]() | Swap content

## Non-member Functions ##

| Function   | Description |
| ----------- | ----------  |
| [`get (array)`]() | Get element (tuple interface)
| [`relational operators (array)`]() | Relational operators for array

## Non-member Class Specializations ##

| Function   | Description |
| ----------- | ----------  |
| [`tuple_element<array>`]() | Tuple element type for array
| [`tuple_size<array>`]() | Tuple size traits for array
