#pragma once
#include "vector"
#include "string"
#include "BaseArg.h"
namespace SoundProcessor {
    class Instruction : public BaseArg {
    public:
        Instruction(bool is_comment, std::vector<std::string> instruction);

        [[nodiscard]] bool get_is_comment() const;

        std::vector<std::string> &get_instruction();

        std::string get_name() override;

    private:
        std::vector<std::string> instruction;
        bool is_comment = false;
    };
}
