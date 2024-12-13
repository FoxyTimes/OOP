#pragma once

#define ABSOLUTE_OFFSET 1000

#include "ConfigParser.h"

namespace SoundProcessor {
    class Converter {
    public:
        virtual void convert() = 0;
        virtual std::queue<std::unique_ptr<BaseArg>> get_args()=0;
        virtual ~Converter() = default;
    };

}