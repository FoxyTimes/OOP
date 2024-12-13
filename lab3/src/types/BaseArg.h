#pragma once
#include "string"
namespace SoundProcessor {

    class BaseArg {
    public:
        virtual std::string get_name() = 0;
        virtual ~BaseArg() = default;
    };
}