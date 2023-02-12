#ifndef _ARRAY_DEBUG_H_

#define _ARRAY_DEBUG_H_

#include<algorithm>
#include<random>
#include<array>
#include<vector>

#include "xstl/array"

#define XSTL_ASSERT(cond, fail_msg) EXPECT_TRUE(cond) << (fail_msg)

_BEGIN_XSTL_TEST

    // Groups together all utility functions that an Array debugger needs
    /// Can also be useful within testing context
    struct DebugUtils
    {
        template<typename _Ty, size_t _Size>
        static void clone_c_array(xstl::array<_Ty, _Size>& _arr, _Ty* _c_arr) {
            size_t i = 0;
            for (auto& elem : _arr)
            {
                elem = _c_arr[i];
                ++i;
            }
        }
    
        template<typename _Ty, size_t _Size>
        static void init_xstl_array(xstl::array<_Ty, _Size>& _arr)
        {
            for (auto& _e : _arr)
                set_random_test_value(_e);
        }
        
        template<typename _Ty, size_t _Size>
        static void init_cstyle_array(_Ty* _arr)   
        {
            for (size_t i = 0; i < _Size; i++)
            {
                set_random_test_value(_arr[i]);
            }
        }
    };

    /// FIXME : Getting a warning for all _verify_*_ok() functions 
    /// use of member '_verify_*_ok' found via unqualified lookup into dependent bases of class templates is a Microsoft extension
    /// for all functionions _verify_*_ok()
    /// Issue is originated from the fact, for some compilers and c++ standards, the class `Debug_array` is not able to find  `_verify_*_ok` because it is declared within the scope of a member function, and it didn't look for it within the super class context. 
    /// Suggtested fix is to add `this->_verify_*_ok()` to tell the compiler that these functions are members of the base class and therefore members of the child class as well. 

    /// _Debug_arr
    // A debugging interface for xstl::array
    // _Ty is stored type within the array, _Size is the size of the array, _arr is the array to debug
    // _ref is a c-style array to use as a reference to debug xstl::array
    // _arr is a clone of _ref, and we used _ref as a "reference container" to debug _arr
    template<typename _Ty, std::size_t _Size>
    struct XSTL_INTERNAL _Debug_array
    {
    protected:
        _Debug_array() = default;
        _Debug_array(const xstl::array<_Ty, _Size>& arr, _Ty* ref)
        {
            for (std::size_t i = 0; i < _Size; ++i)
            {
                *(_ref + i) = *(ref + i);
                _arr[i] = arr[i];
            }
        }
       
        void _verify_iter_ok() {
            // test: begin() and end()

            for (struct { size_t i; typename xstl::array<_Ty, _Size>::iterator _it; } loop = { 0, _arr.begin() }; loop._it != _arr.end(); ++loop._it, ++loop.i)
            {
                XSTL_ASSERT(*(loop._it) == _ref[loop.i], "iterator functions failed!");
                //EXPECT_TRUE(*(loop._it) == _ref[loop.i]) << "iterator functions failed!";
            }

            xstl::array<_Ty, _Size> _carr{};
            std::copy(_ref, _ref + _Size, _carr.begin());
            _carr = static_cast<const xstl::array<_Ty, _Size>>(_carr);

            // test const overloads of: begin() const and end() const
            
            for (struct{ size_t i; typename xstl::array<_Ty, _Size>::const_iterator _it; } loop = { 0, _carr.begin()}; loop._it != _carr.end(); ++loop._it, ++loop.i)
            {
                XSTL_ASSERT(*(loop._it) == _ref[loop.i], "constant overloads of iterator functions failed!");
            }
        }

        void _verify_citer_ok() {
            xstl::array<_Ty, _Size> _carr{};
            std::copy(_ref, _ref + _Size, _carr.begin());
            _carr = static_cast<const xstl::array<_Ty, _Size>>(_carr);

            // test of: cbegin() const and cend() const
            for (struct{ size_t i; typename xstl::array<_Ty, _Size>::const_iterator _it; } loop = { 0, _carr.begin() }; loop._it != _carr.end(); ++loop._it, ++loop.i)
            {
                XSTL_ASSERT(*(loop._it) == _ref[loop.i], "constant overloads of iterator functions failed!");
            }
        }

        void _verify_riter_ok() {
            // Test rbegin and rend

            for (struct{ size_t i; typename xstl::array<_Ty, _Size>::reverse_iterator _it; } loop = { _Size - 1, _arr.rbegin() }; loop._it != _arr.rend(); ++loop._it, --loop.i)
            {
                XSTL_ASSERT(*(loop._it) == _ref[loop.i], "reverse iterator functions failed!");
            }

            xstl::array<_Ty, _Size> _carr{};
            std::copy(_ref, _ref + _Size, _carr.begin());
            _carr = static_cast<const xstl::array<_Ty, _Size>>(_carr);

            // test const overloads of: rbegin() const and rend() const

            for (struct { size_t i; typename xstl::array<_Ty, _Size>::const_reverse_iterator _it; } loop = { _Size - 1, _carr.crbegin() }; loop._it != _carr.rend(); ++loop._it, --loop.i)
            {
                XSTL_ASSERT(*(loop._it) == _ref[loop.i], "constant overloads of reverse iterator functions failed!");
            }
        }

        void _verify_criter_ok() {
            xstl::array<_Ty, _Size> _carr{};
            std::copy(_ref, _ref + _Size, _carr.begin());
            _carr = static_cast<const xstl::array<_Ty, _Size>>(_carr);

            // Test: crbegin() and crend()

            for (struct{ size_t i ; typename xstl::array<_Ty, _Size>::const_reverse_iterator _it; } loop = { _Size - 1, _carr.crbegin() }; loop._it != _carr.crend(); ++loop._it, --loop.i)
            {
                XSTL_ASSERT(*(loop._it) == _ref[loop.i], "constant overloads of reverse iterator functions failed!");
            }
        }

        bool _verify_size_ok() {
            auto _ref_size = sizeof(_ref) / sizeof(_Ty);

            XSTL_ASSERT(_arr.size() == _ref_size, "size() failed");
            return _arr.size() == _ref_size;
        }

        bool _verify_max_size_ok() {
            auto _ref_size = sizeof(_ref) / sizeof(_Ty);

            XSTL_ASSERT(_arr.max_size() == _ref_size, "max_size() failed");
            return _arr.max_size() == _ref_size;
        }

        bool _verify_empty_ok() {
            if (_Size == 0) {
                XSTL_ASSERT(_arr.empty(), "empty() failed");
                return _arr.empty();
            }
            XSTL_ASSERT(!_arr.empty(), "empty() failed");
            return !_arr.empty();
        }

        void _verify_access_operator_ok() {
            xstl::array<_Ty, _Size> _carr{};
            std::copy(_ref, _ref + _Size, _carr.begin());
            _carr = static_cast<const xstl::array<_Ty, _Size>>(_carr);

            for (size_t i = 0; i < _Size; i++)
            {
                XSTL_ASSERT(_arr[i] == _ref[i], "operator[](size_t) failed");
                XSTL_ASSERT(_carr[i] == _ref[i], "operator[](size_t) const overload failed");
            }
        }

        void _verify_at_ok() {
            xstl::array<_Ty, _Size> _carr{};
            std::copy(_ref, _ref + _Size, _carr.begin());
            _carr = static_cast<const xstl::array<_Ty, _Size>>(_carr);

            for (size_t i = 0; i < _Size; i++)
            {
                XSTL_ASSERT(_arr.at(i) == _ref[i],  "at(size_t) failed");
                XSTL_ASSERT(_carr.at(i) == _ref[i], "at(size_t) const overload failed");
            }
        }

        void _verify_front_ok() {
            xstl::array<_Ty, _Size> _carr{};
            std::copy(_ref, _ref + _Size, _carr.begin());
            _carr = static_cast<const xstl::array<_Ty, _Size>>(_carr);

            // Test: front() and front() const overload
            XSTL_ASSERT(_arr.front() == _ref[0], "front() failed");
            XSTL_ASSERT(_carr.front() == _ref[0], "front() const overload failed");
        }

        void _verify_back_ok() {
            xstl::array<_Ty, _Size> _carr{};
            std::copy(_ref, _ref + _Size, _carr.begin());
            _carr = static_cast<const xstl::array<_Ty, _Size>>(_carr);

            // Test: back() and back() const overload
            XSTL_ASSERT(_arr.back() == _ref[_Size - 1], "back() failed");
            XSTL_ASSERT(_carr.back() == _ref[_Size - 1], "back() const overload failed");
        }

        void _verify_data_ok() {
            xstl::array<_Ty, _Size> _carr;
            std::copy(_ref, _ref + _Size, _carr.begin());
            _carr = static_cast<const xstl::array<_Ty, _Size>> (_carr);

            // Test: data() and data() const overload
            _Ty* _arr_data = _arr.data();
            const _Ty* _carr_data = _carr.data();

            _array_assert(_arr_data, _ref, _Size, [](_Ty x, _Ty y) {
                XSTL_ASSERT(x == y, "data() failed");
                });
            _array_assert(_carr_data, _ref, _Size, [](_Ty x, _Ty y) {
                XSTL_ASSERT(x == y, "data() const overload failed");
                });
        }

        void _verify_fill_ok() {
            // fill _new_arr with value 5
            _Ty _new_arr[_Size];
            _Ty val;
            set_random_test_value(val);
            std::fill(_new_arr, _new_arr + _Size, val);
            // fill _arr with same value 
            _arr.fill(val);

            // compare: _arr, _new_arr
            _array_assert(_arr, _new_arr, _Size, [](_Ty x, _Ty y){
                XSTL_ASSERT(x == y, "fill(const_reference) failed");
            });
        }

        void _verify_swap_ok() {

            // init _new_arr and fill it with a random value `val`
            xstl::array<_Ty, _Size> _new_arr;
            _Ty val;
            set_random_test_value(val);
            _new_arr.fill(val);

            // swap _arr with _new_arr
            // after swapping, _new_arr should contain the same elements exist in _ref
            _arr.swap(_new_arr);

            // verify x in _arr is equal to (y + y) for y in _ref  
            _array_assert(_new_arr, _ref, _Size, [](_Ty x, _Ty y){
                XSTL_ASSERT(x == y,"swap() failed");
            });
            
            for (auto &e : _arr)
            {
                XSTL_ASSERT(e == val, "swap() failed");
            }
            
        }

    protected:
        xstl::array<_Ty, _Size> _arr;
        _Ty _ref[_Size];
        
        // Declared two template params: _Arr1 and _Arr2 to support any array type comparison whether it's 
        // a c-style array or std::array or xstl::array or any custom array type that supports access via [].
        template<typename _Arr1, typename _Arr2, typename Assertion> 
        void _array_assert(_Arr1 _arr1, _Arr2 _arr2, std::size_t _N, Assertion assert_function) {
            for (size_t i = 0; i< _N; ++i)
            {
                assert_function(_arr1[i], _arr2[i]);
            }
        }
    };

    template<typename _Ty, std::size_t _Size>
    struct XSTL_API Debug_array : protected _Debug_array<_Ty, _Size>
    {
        using _Base = _Debug_array<_Ty, _Size>;

        Debug_array() : _Base() {}
        Debug_array(const xstl::array<_Ty, _Size>& arr, _Ty* ref) : _Base(arr, ref) {}

        void test_forward_iteration();
        void test_const_forward_iteration();
        void test_reverse_iteration();
        void test_const_reverse_iteration();

        void test_access_via_operator();
        void test_access_via_at();
        void test_generated_c_array();
        void test_front_and_back_access();
        void test_fill();
        void test_swap();

        void perform_iterator_checks();
        void perform_storage_checks();
        void perform_accessors_checks();
        void perform_modifiers_checks();
        void perform_relational_ops_checks();
        void perform_stream_ops_checks();
        void perform_nonmember_ops_checks();
        void perform_all_initial_checks();
    };

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_forward_iteration()
    {
        this->_verify_iter_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_const_forward_iteration()
    {
        this->_verify_citer_ok();
    }
    
    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_reverse_iteration()
    {
        this->_verify_riter_ok();
    }
    
    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_const_reverse_iteration()
    {
        this->_verify_criter_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_access_via_operator()
    {
        this->_verify_access_operator_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_access_via_at()
    {
        this->_verify_at_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_generated_c_array()
    {
        this->_verify_data_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_front_and_back_access()
    {
        this->_verify_front_ok();
        this->_verify_back_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_fill()
    {
        this->_verify_fill_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::test_swap()
    {
        this->_verify_swap_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::perform_storage_checks()
    {
        this->_verify_size_ok();
        this->_verify_max_size_ok();
        this->_verify_empty_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::perform_accessors_checks()
    {
        this->_verify_access_operator_ok();
        this->_verify_at_ok();
        this->_verify_front_ok();
        this->_verify_back_ok();
        this->_verify_data_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::perform_modifiers_checks()
    {
        this->_verify_fill_ok();
        this->_verify_swap_ok();
    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::perform_relational_ops_checks() {

    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::perform_stream_ops_checks() {

    }

    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::perform_nonmember_ops_checks() {

    }
    
    template<typename _Ty, std::size_t _Size>
    void Debug_array<_Ty, _Size>::perform_all_initial_checks()
    {
        perform_iterator_checks();
        perform_storage_checks();
        perform_accessors_checks();
        perform_modifiers_checks();
    }


    template<typename Type>
    bool CanCreateAnArrayOfZeroSizeTest() {

    }

    template<typename Type>
    void CanCreateAnArrayOfSmallSizeTest() {        
        
    }

    template<typename Type>
    bool CanCreateAnArrayOfLargeSizeTest() {
        
    }

_END_XSTL_TEST

#endif // !_ARRAY_DEBUG_H_