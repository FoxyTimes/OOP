#pragma once

#include "BaseArg.h"
#include "string"

namespace SoundProcessor {
    class InstName : public BaseArg {
    private:
        std::string name_of_inst;
    public:
        explicit InstName(std::string name_of_inst);
        std::string get_name() override;
        std::string get_name_inst();
    };
}
