#ifndef _GENERATORS_H_

#define _GENERATORS_H_

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <memory>
#include <random>
#include <string>

#ifdef __unix__

#include <unistd.h>

#endif // __unix__

#include "xstl/config/config.h"


// --- Random Generators ---

template<typename _Int>
class _IsIntegerNumber {
public:
    static constexpr bool value = std::is_same<_Int, short>::value ||
                        std::is_same<_Int, int>::value ||
                        std::is_same<_Int, unsigned int>::value ||
                        std::is_same<_Int, long>::value ||
                        std::is_same<_Int, unsigned long>::value ||
                        std::is_same<_Int, long long>::value ||
                        std::is_same<_Int, unsigned long long>::value;
};



// double, float, long double
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
get_random_number(const T from = std::numeric_limits<T>::min(),
                  const T to = std::numeric_limits<T>::max()) {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_real_distribution<T> distr(from, to);
  return distr(generator);
}

// int, long, short, unsigned int, unsigned long, unsigned short
template <typename T>
typename std::enable_if<_IsIntegerNumber<T>::value, T>::type
get_random_number(const T from = std::numeric_limits<T>::min(),
                  const T to = std::numeric_limits<T>::max()) {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<T> distr(from, to);
  return distr(generator);
}

// char
char get_random_char() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-127, 127);
    return static_cast<char>(dis(gen));
}

// unsigned char
unsigned char get_random_uchar() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 127);
    return static_cast<unsigned char>(dis(gen));
}

// std::string
std::string get_random_string() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    std::string result;
    for (int i = 0; i < dis(gen); ++i) {
        result.push_back(get_random_char());
    }
    return result;
}

// const char*
const char* get_random_cstring() {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    static char str[11];
    for (int i = 0; i < dis(gen); ++i) {
        str[i] = alphanum[get_random_uchar() % (sizeof(alphanum) - 1)];
    }
    str[dis(gen)] = 0;
    return str;
}

#if __cplusplus >= 201703L
template <typename T>
T generate_random_value() {
    if constexpr (std::is_same<T, char>::value) {
        return get_random_char();
    } else if constexpr (std::is_same<T, std::string>::value) {
        return get_random_string();
    } else if constexpr (std::is_same<T, const char*>::value) {
        return get_random_cstring();
    } else if constexpr (std::is_same<T, std::nullptr_t>::value) {
        return nullptr;
    } else if constexpr (std::is_same<T, bool>::value) {
        return get_random_number<short>(0, 1);
    } else if constexpr (std::is_floating_point<T>::value) {
        return get_random_number<T>();
    } else if constexpr (std::is_arithmetic<T>::value && !std::is_same<T, char>::value && !std::is_same<T, unsigned char>::value && !std::is_same<T, bool>::value && !std::is_floating_point<T>::value) {
        return get_random_number<T>();
    } else {
        return T();
    }
}
#else
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value && !std::is_same<T, char>::value, T>::type
generate_random_value() {
    return get_random_number<T>();
}
    
template <typename T>
typename std::enable_if<std::is_same<T, char>::value, T>::type
generate_random_value() {
    return get_random_char();
}

template <typename T>
typename std::enable_if<std::is_same<T, std::string>::value, T>::type
generate_random_value() {
    return get_random_string();
}

template <typename T>
typename std::enable_if<std::is_pointer<T>::value && std::is_same<T, char>::value, T>::type
generate_random_value() {
    return get_random_cstring();
}

#endif // __cplusplus >= 201703L

#endif // _GENERATORS_H_