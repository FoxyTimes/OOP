#pragma once
#include "types/BaseArg.h"
#include "queue"
#include "memory"
#include "Converter.h"

namespace SoundProcessor {
    class Mixer : public Converter {
    private:
        std::queue<std::unique_ptr<BaseArg>> queue_of_args;
    public:
        explicit Mixer(std::queue<std::unique_ptr<BaseArg>> queue_of_args);
        void convert() override;
        std::queue<std::unique_ptr<BaseArg>> get_args() override;
    };
}

