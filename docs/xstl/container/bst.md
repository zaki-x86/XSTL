# Binary Search Tree

**Defined in header file**: `<...>`

```cpp
// Signature
```

**A brief description of the purpose of the class/function.**

## Description

A brief description of the purpose of the function/class/method.

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