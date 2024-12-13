#include "vector"
#include "string"

#pragma once

namespace SoundProcessor {

    class Static {
    public:
        static std::string copy_str(std::string str, int from_index, int to_index);

        static std::vector<std::string> split_str(std::string str, std::string delim);
    };
}


