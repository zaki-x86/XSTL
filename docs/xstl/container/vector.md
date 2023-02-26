# Vector (Dynamic Array)

**Defined in header file**: `<vector>`

```cpp
template <class T, class Allocator = allocator<T>>
class vector;
```

**A brief description of the purpose of the class/function.**

## Description

A `vector` is a sequence container that encapsulates dynamic size arrays. Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container.

Instead, vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size).

Accessing elements in a vector by an offset on a regular pointer, just like with arrays, is a constant operation, O(1). Inserting or erasing elements in the middle of the vector however causes the container to shift all the elements after the insertion point by one. This is also linear in the number of elements that have to be moved.

Vectors are very similar to arrays, but have some important differences. First, vectors are dynamically allocated. Second, vectors are guaranteed to live in contiguous memory. Third, vectors can be resized. Fourth, vectors have a lot of built-in functions to help you manipulate them. Fifth, vectors are very easy to use. And lastly, vectors are very similar to arrays, so if you know how to use arrays, you already know how to use vectors.

## Container Properties

### prop1

brief details

### prop2

...

## Template Parameters

```cpp
T
```

&nbsp;&nbsp;&nbsp;&nbsp;Type of the elements contained.

&nbsp;&nbsp;&nbsp;&nbsp;Aliased as member type `array::value_type`.

```cpp
Allocator
```

&nbsp;&nbsp;&nbsp;&nbsp;Allocator type used to allocate the storage. The default allocator is `std::allocator` which provides all the element types that a vector can hold. If the user wishes to store elements that are not copy constructible or not destructible, or to get better performance with a particular kind of storage allocation model, a user-defined allocator may be supplied.

&nbsp;&nbsp;&nbsp;&nbsp;Aliased as member type `vector::allocator_type`.

## Specializations

provide a link to the specialized class template

## Iterator Validation

| operation | invalidated |
| --------- | ----------- |
| name      | when?       |

## Member Types

| Type        |  Definition |
| ----------- | ----------- |
| `value_type`| The first template parameter `T`
| `reference`   | `value_type&`
| `const_reference`   | `const value_type&`
| `pointer`   | `value_type*`
| `const_pointer`   | `const value_type*`
| `iterator`   | a [random access iterator]() to `value_type`
| `const_iterator`   | a [random access iterator]() to `const value_type`
| `reverse_iterator`   | `reverse_iterator<iterator>`
| `const_reverse_iterator`   | `reverse_iterator<const_iterator>`
| `size_type`   | `size_t`
| `difference_type`   | `ptrdiff_t`

## Member Functions ##

| Operation | Desciption |
| --------- | ---------- |
| [Constructors]() | 
| [Destructor]() |
| [Assignment]() |

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

### Obervers ###

| Function   | Description |
| ----------- | ----------  |
| [`data`]() | Get pointer to data
| [`get_allocator`]() | returns the associated allocator


### Modifiers ###

| Function   | Description |
| ----------- | ----------  |
| [`fill`]() | Fill array with value
| [`swap`]() | Swap content

## Non-member Functions ##

| Function   | Description |
| ----------- | ----------  |
| [`relational operators (array)`]() | Relational operators for the container
| [`swap`]() | specializes the [`xstl::swap`]() algorithm

## Examples

```cpp
//Code example that demonstrates the usage of the function/class/method.
```

## See also

A list of related functions/classes/methods.

## Notes

Any relevant notes or additional information.