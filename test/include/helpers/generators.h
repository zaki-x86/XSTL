#ifndef _GENERATORS_H_

#define _GENERATORS_H_

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <string>

#ifdef __unix__

#include <unistd.h>

#endif // __unix__

#include "xstl/config/config.h"

// --- Quick Generators ---

#if defined(__MINGW32__) || defined(__MINGW64__)
namespace std {
    template<typename T>
    constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

    template<typename T>
    constexpr bool is_floating_point_v = is_floating_point<T>::value;

    template<typename T, typename U>
    constexpr bool is_same_v = is_same<T, U>::value;
}
#endif


template <typename T>
typename std::enable_if_t<std::is_floating_point<T>::value, T>
get_random_number(const T from = std::numeric_limits<T>::min(),
                  const T to = std::numeric_limits<T>::max()) {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_real_distribution<T> distr(from, to);
  return distr(generator);
}

template <typename T>
typename std::enable_if_t<std::is_arithmetic_v<T> && !std::is_floating_point_v<T> && !std::is_same_v<T, char> && !std::is_same_v<T, unsigned char>, T>
get_random_number(const T from = std::numeric_limits<T>::min(),
                  const T to = std::numeric_limits<T>::max()) {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<T> distr(from, to);
  return distr(generator);
}

char get_random_char() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-127, 127);
    return static_cast<char>(dis(gen));
}

unsigned char get_random_uchar() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 127);
    return static_cast<unsigned char>(dis(gen));
}

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
    if constexpr (std::is_same_v<T, char>) {
        return get_random_char();
    } else if constexpr (std::is_same_v<T, std::string>) {
        return get_random_string();
    } else if constexpr (std::is_same_v<T, const char*>) {
        return get_random_cstring();
    } else if constexpr (std::is_same_v<T, std::nullptr_t>) {
        return nullptr;
    } else if constexpr (std::is_same_v<T, bool>) {
        return get_random_number<short>(0, 1);
    } else {
        static_assert(std::is_arithmetic_v<T>, "Type must be arithmetic or char, std::string, or const char*");
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<T> dis(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
        return dis(gen);
    }
}
#else
template <typename T>
typename std::enable_if_t<std::is_arithmetic<T>::value && !std::is_same<T, char>::value, T>
generate_random_value() {
    return get_random_number<T>();
}
    
template <typename T>
typename std::enable_if_t<std::is_same<T, char>::value, T>
generate_random_value() {
    return get_random_char();
}

template <typename T>
typename std::enable_if_t<std::is_same<T, std::string>::value, T>
generate_random_value() {
    return get_random_string();
}

template <typename T>
typename std::enable_if_t<std::is_pointer<T>::value && std::is_same<T, char>::value, T>
generate_random_value() {
    return get_random_cstring();
}

#endif // __cplusplus >= 201703L

#endif // _GENERATORS_H_