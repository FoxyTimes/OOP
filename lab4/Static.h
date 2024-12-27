#include "vector"
#include "string"

#pragma once


class Static {
public:
    static std::vector<std::string> split_str(const std::string &str, char delim, char escape);
};


