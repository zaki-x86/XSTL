#ifndef _GENERATORS_H_

#define _GENERATORS_H_


#include <iostream>
#include <random>
#include<functional>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>

#ifdef __unix__

#include <unistd.h>

#endif // __unix__


namespace xstl {
/// The structs: RandomGeneratorFunctionFactory, QuickRandomGenerator, RandomContainerGenerator, XSTLRandomGenerator
/// TODO will create c-wrappers for these generators
struct RandomGenerator {
    // TODO
    // More sophisticated random value generator, with more added on customization
    // Its more general and customizable; it is a wrapper of the all other generators
};

struct RandomGeneratorFunctionFactory {
    // TODO
    // group here: CreateRandom[T]GeneratorFunction() and its utils
    // Where T is a type to generate
};

struct QuickRandomGenerator {
    // TODO
    // group here: set_random_test_value() overloads
    // these functions generates a value of type T, where T is a primitive type
    // it does this with the least possible customization
    // s.t. the only parameter needed is the variable that stores the randomly generated value
};


template<typename Container>
struct RandomContainerGenerator {
    // TODO
    // This generator is used to generate dummy objects, where you pass in the container type as a template paramert, you may also need to pass the constructor of that `Container`, and the methods that the random generator will use to push values to that container.
    // For starters this maybe only limited to container objects.
};

}

template<typename RandomEngine = std::default_random_engine,
    typename Distrubution = std::uniform_int_distribution<int>,
    typename Generator = std::mt19937>
    auto CreateRandomIntegerGeneratorFunction(int from = INT32_MIN, int to = INT32_MAX)
    -> decltype(std::bind(Distrubution(), Generator()))
{
    RandomEngine engine;
    Generator generator(engine());
    Distrubution distribution(from, to);
    auto generate = std::bind(distribution, generator);

    return generate;
}


// definitions 

template<typename T>
T generate_numeric(const T, const T);

char generate_char();

std::string generate_string(const size_t);

void set_random_test_value(
    int& var_, 
    int range_from =  INT32_MIN, 
    int range_to = INT32_MAX
    );

void set_random_test_value(
    long& var_,
    long range_from = INT32_MIN,
    long range_to = INT32_MAX
);

void set_random_test_value(
    int*& var_, 
    int range_from =  INT32_MIN,
    int range_to = INT32_MAX
    );

void set_random_test_value(
    char& var_,
    bool
    #if defined(__GNUC__) || defined(__GNUG__)
    __attribute__((unused))
    #endif
literal_only = false
    );

void set_random_test_value(
    char*& var_, 
    size_t size_ = generate_numeric<size_t>(0, 20)
    );

void set_random_test_value(
    std::string& var_, 
    size_t size_ = generate_numeric<size_t>(0, 20)
    );

void set_random_test_values(
    std::vector<int>& vec_,
    int range_from =  INT32_MIN,
    int range_to = INT32_MAX,
    size_t vec_size_ = 10
    );

void set_random_test_values(
    std::vector<int*>& vec_,
    int range_from =  INT32_MIN,
    int range_to = INT32_MAX,
    size_t vec_size_ = 10
    );

void set_random_test_values(
    std::vector<char>& vec_,
    bool
    #if defined(__GNUC__) || defined(__GNUG__)
    __attribute__((unused))
    #endif
literal_only = false,
    size_t vec_size_ = 10
    );

void set_random_test_values(
    std::vector<char*>& vec_,
    size_t str_size = generate_numeric<size_t>(0, 20),
    size_t vec_size_ = 10
    );

void set_random_test_values(
    std::vector<std::string>& vec_, 
    size_t str_size = generate_numeric<size_t>(0, 20),
    size_t vec_size_ = 10
    );


// --- Imp ---

template<typename T>
T generate_numeric(const T from, const T to)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<T> distr(from, to);
    return distr(generator);
}


char generate_char()
{
    
    const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    const size_t max_index = (sizeof(charset) - 1);
    char out = charset[ generate_numeric<int>(0, max_index) ];

    if (out != '\0' && isalnum(out))
        return out;
    
    return 'x';
}


std::string generate_string(const size_t len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string tmp_s;
    tmp_s.reserve(len);

    for (size_t i = 0; i < len; ++i) {
        tmp_s += generate_char();
    }

    if (tmp_s.size() != 0)
        return tmp_s;

    else if (tmp_s.size() == 0)
    {
        tmp_s = "empty";
        return tmp_s;
    }

    else
        return "empty";  
}


void set_random_test_value(
    int& var_, 
    int range_from, 
    int range_to
    )
{
    var_ = generate_numeric<int>(range_from, range_to);
}

void set_random_test_value(
    long& var_,
    long range_from,
    long range_to
)
{
    var_ = generate_numeric<long>(range_from, range_to);
}

void set_random_test_value(
    int*& var_, 
    int range_from,
    int range_to
    )
{
    var_ = new int(generate_numeric<int>(range_from, range_to));
}


void set_random_test_value(
    char& var_,
    bool
    #if defined(__GNUC__) || defined(__GNUG__)
    __attribute__((unused))
    #endif
literal_only
    )
{
    var_ = generate_char();
}


void set_random_test_value(
    char*& var_, 
    size_t size_ 
    )
{
    var_ = strdup(generate_string(size_).c_str());
}


void set_random_test_value(
    std::string& var_, 
    size_t size_ 
    )
{
    var_ = generate_string(size_);
}


void set_random_test_values(
    std::vector<int>& vec_,
    int range_from,
    int range_to,
    size_t vec_size_ 
    )
{
    for (size_t i = 0; i < vec_size_; i++)
        vec_.push_back(generate_numeric<int>(range_from, range_to));
}


void set_random_test_values(
    std::vector<int*>& vec_,
    int range_from ,
    int range_to ,
    size_t vec_size_ 
    )
{
    for (size_t i = 0; i < vec_size_; i++)
            vec_.push_back(new int(generate_numeric<int>(range_from, range_to)));
}


void set_random_test_values(
    std::vector<char>& vec_,
    bool
    #if defined(__GNUC__) || defined(__GNUG__)
    __attribute__((unused))
    #endif
literal_only,
    size_t vec_size_ 
    )
{
    for (size_t i = 0; i < vec_size_; i++)
            vec_.push_back(generate_char());
}


void set_random_test_values(
    std::vector<char*>& vec_,
    size_t str_size,
    size_t vec_size_
    )
{
    for (size_t i = 0; i < vec_size_; i++)
            vec_.push_back(strdup(generate_string(str_size).c_str()));
}


void set_random_test_values(
    std::vector<std::string>& vec_, 
    size_t str_size ,
    size_t vec_size_
    )
{
    for (size_t i = 0; i < vec_size_; i++)
            vec_.push_back(generate_string(str_size));
}

template <typename T>
T generate_random_test_value()
{
    std::shared_ptr<T> val(new T);
    set_random_test_value(*val);

    return *val;
}

template <typename T>
T generate_random_test_values()
{

}

#endif // !_GENERATORS_H_
