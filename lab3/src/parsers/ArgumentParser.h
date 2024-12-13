#pragma once
#include "string"
#include "vector"
#include "memory"
#include "types/File.h"
#include "types/Times.h"
#include "types/BaseArg.h"
#include "types/InstName.h"

namespace SoundProcessor {

    class ArgumentParser {
    public:
        static std::unique_ptr<BaseArg> parse_arguments(const std::string&);
        static std::unique_ptr<Times> parse_time(const std::string&);
        static std::unique_ptr<File> parse_file(const std::string&);
        static std::unique_ptr<InstName> parse_instname(const std::string&);
    };

}
