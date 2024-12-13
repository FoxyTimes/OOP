#pragma once
#include "memory"
#include "Converter.h"


namespace SoundProcessor {
    class Factory {
    public:
        static std::unique_ptr<Converter> create_converter(std::queue<std::unique_ptr<BaseArg>>);
    };
}