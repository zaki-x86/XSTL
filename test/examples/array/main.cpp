#include <iostream>
#include <array>
#include <xstl/array.hpp>


int main(void) {

    try
    {
        xstl::array<int, 0> arr0;
        arr0[0] = 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception raised:" << e.what() << '\n';
    }
    

    xstl::array<int, 5> arr1;
    std::array<int, 5> arr2;

    arr1.fill(1);
    arr2.fill(2);




    return 0;
}