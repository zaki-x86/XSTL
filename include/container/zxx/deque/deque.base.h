#ifndef _DEQUE_BASE_H_

#define _DEQUE_BASE_H_

/**
 * inline size_t __deque_buf_size(size_t __size)
 * 
 * this function appears to determine the size of the buffer that the deque should use, based on the size of the elements stored in the deque.
 * 
 * It takes a single parameter, __size, which is the size of the elements stored in the deque.
 * 
 * The function defines two cases based on the comparison of __size and _GLIBCXX_DEQUE_BUF_SIZE.
 * 
 * If __size is less than _GLIBCXX_DEQUE_BUF_SIZE, the function returns _GLIBCXX_DEQUE_BUF_SIZE / __size .
 * 
 * If __size is greater than or equal to _GLIBCXX_DEQUE_BUF_SIZE, the function returns 1.
 * 
 * The buffer size is determined by dividing the fixed constant _GLIBCXX_DEQUE_BUF_SIZE (520) by the size of the elements, this will allow to store more elements if the size of elements is smaller.
 * 
 * So, this function is responsible for determining the number of elements that will be stored in the buffer using the constant defined by the library and the size of the elements stored in the deque.
 */


template<typename T, typename Allocator>
struct _Deque_base
{

};

#endif // !_DEQUE_BASE_H_