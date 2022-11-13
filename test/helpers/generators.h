#pragma once

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

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
    int*& var_, 
    int range_from =  INT32_MIN,
    int range_to = INT32_MAX
    );

void set_random_test_value(
    char& var_,
    bool literal_only = false
    );

void set_random_test_value(
    char*& var_, 
    long size_ = generate_numeric<int>(0, 20)
    );

void set_random_test_value(
    std::string& var_, 
    long size_ = generate_numeric<int>(0, 20)
    );

void set_random_test_values(
    std::vector<int>& vec_,
    int range_from =  INT32_MIN,
    int range_to = INT32_MAX,
    long vec_size_ = 10
    );

void set_random_test_values(
    std::vector<int*>& vec_,
    int range_from =  INT32_MIN,
    int range_to = INT32_MAX,
    long vec_size_ = 10
    );

void set_random_test_values(
    std::vector<char>& vec_,
    bool literal_only = false,
    long vec_size_ = 10
    );

void set_random_test_values(
    std::vector<char*>& vec_,
    long str_size = generate_numeric<int>(0, 20),
    long vec_size_ = 10
    );

void set_random_test_values(
    std::vector<std::string>& vec_, 
    long str_size = generate_numeric<int>(0, 20),
    long vec_size_ = 10
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

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
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
    var_ = generate_numeric(range_from, range_to);
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
    bool literal_only
    )
{
    var_ = generate_char();
}


void set_random_test_value(
    char*& var_, 
    long size_ 
    )
{
    var_ = strdup(generate_string(size_).c_str());
}


void set_random_test_value(
    std::string& var_, 
    long size_ 
    )
{
    var_ = generate_string(size_);
}


void set_random_test_values(
    std::vector<int>& vec_,
    int range_from,
    int range_to,
    long vec_size_ 
    )
{
    for (size_t i = 0; i < vec_size_; i++)
        vec_.push_back(generate_numeric(range_from, range_to));
}


void set_random_test_values(
    std::vector<int*>& vec_,
    int range_from ,
    int range_to ,
    long vec_size_ 
    )
{
    for (size_t i = 0; i < vec_size_; i++)
            vec_.push_back(new int(generate_numeric<int>(range_from, range_to)));
}


void set_random_test_values(
    std::vector<char>& vec_,
    bool literal_only,
    long vec_size_ 
    )
{
    for (size_t i = 0; i < vec_size_; i++)
            vec_.push_back(generate_char());
}


void set_random_test_values(
    std::vector<char*>& vec_,
    long str_size,
    long vec_size_
    )
{
    for (size_t i = 0; i < vec_size_; i++)
            vec_.push_back(strdup(generate_string(str_size).c_str()));
}


void set_random_test_values(
    std::vector<std::string>& vec_, 
    long str_size ,
    long vec_size_
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