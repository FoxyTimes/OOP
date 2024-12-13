#pragma once
#include "Converter.h"

namespace SoundProcessor {
    class Muter : public Converter {
    private:
        std::queue<std::unique_ptr<BaseArg>> queue_of_args;
    public:
        explicit Muter(std::queue<std::unique_ptr<BaseArg>> queue_of_args);
        void convert() override;
        std::queue<std::unique_ptr<BaseArg>> get_args() override;
    };
}

