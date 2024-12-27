#pragma once

#include <tuple>
#include <string>
#include <vector>

template <typename T>
T ConvertFromString(const std::string& str) {
    throw std::runtime_error("none-type");
}

template<>
int ConvertFromString(const std::string& str) {
    try {
        return std::stoi(str);
    }
    catch (std::exception e) {
        throw std::runtime_error("stoi error");
    }
}

template<>
float ConvertFromString(const std::string& str) {
    try {
        return std::stof(str);
    }
    catch (std::exception e) {
        throw std::runtime_error("stof error");
    }
}

template<>
std::string ConvertFromString(const std::string& str) {
    return str;
}

template<typename T, unsigned N, unsigned Size>
class RecursiveConverterToTuple {
public:
    static void transformation(T &tup, const std::vector<std::string>& v) {
        std::get<N>(tup) = ConvertFromString<typename std::tuple_element<N, T>::type>(v[N]);
        RecursiveConverterToTuple<T, N+1, Size>::transformation(tup, v);
    }
};

template<typename T, unsigned Size>
class RecursiveConverterToTuple<T, Size, Size> {
public:
    static void transformation(T &tup, const std::vector<std::string>& v) {
        std::get<Size>(tup) = ConvertFromString<typename std::tuple_element<Size, T>::type>(v[Size]);
    }
};

template<typename T, unsigned N>
class RecursiveConverterToTuple<T, N, 0> {
public:
    static void transformation(T &tup, const std::vector<std::string>& v) {
   }
};

template <typename... Args>
std::tuple<Args...> vector_to_tuple(const std::vector<std::string>& v) {
    std::tuple<Args...> tup;
    RecursiveConverterToTuple<std::tuple<Args...>, 0, sizeof...(Args)-1>::transformation(tup, v);
    return tup;
}



