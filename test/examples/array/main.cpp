#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <xstl/array.hpp>
#include <helpers/generators.h>

void access_empty_array() {
    xstl::array<int, 0> arr;
    arr[0] = 1;
}

void access_array_with_index_within_range()
{
    // Acess array with index within range
    xstl::array<std::string, 2> arr;
    arr[0] = get_random_string();
    arr[1] = get_random_string();

    std::cout << "arr[0]: " << arr.at(0) << "\n";
    std::cout << "arr[1]: " << arr.at(1) << "\n";
}

void access_array_with_index_out_of_range() {
    xstl::array<std::string, 5> arr;
    std::string _val = get_random_string();
    arr.fill(_val);

    try
    {
        arr.at(5) = _val;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception raised: " << e.what() << '\n';
    }
}

void swap_two_arrays()
{
    // Swap two arrays

    xstl::array<int, 5> arr1;
    xstl::array<int, 5> arr2;

    arr1.fill(get_random_number<int>(0, INT32_MAX));
    arr2.fill(get_random_number<int>(0, INT32_MAX));

    std::swap(arr1, arr2);

    std::cout << "arr1: " << arr1 << "\n";
}

template <typename _Ty, size_t _Size>
void array_equality()
{
    xstl::array<_Ty, _Size> arr3;
    xstl::array<_Ty, _Size> arr4;
    xstl::array<_Ty, _Size> arr5;
    xstl::array<_Ty, _Size> arr6;
    _Ty val = generate_random_value<_Ty>();
    _Ty val2 = generate_random_value<_Ty>();

    arr3.fill(val);
    arr4.fill(val);
    arr5.fill(val2);

    for (auto &i : arr6)
    {
        i = generate_random_value<_Ty>();
    }

    if (arr3 == arr4)
    {
        std::cout << " CORRECT arr1 == arr2\n";
    }
    else
    {
        std::cout << " ERROR arr3 and arr4 should be equal\n";
    }

    if (arr3 != arr5)
    {
        std::cout << " CORRECT arr3 != arr5\n";
    }
    else
    {
        std::cout << " ERROR arr3 and arr5 shouldn't be equal\n";
        std::cout << "arr3: " << arr3 << "\n";
        std::cout << "arr5: " << arr5 << "\n";
    }
}

int main(void) {

    access_array_with_index_within_range();
    access_array_with_index_out_of_range();
    swap_two_arrays();
    array_equality<std::string, 5>();

    return 0;
}