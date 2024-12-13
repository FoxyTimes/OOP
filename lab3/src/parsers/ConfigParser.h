#pragma once
#include <fstream>
#include "vector"
#include "string"
#include "iostream"
#include "queue"
#include "memory"
#include "Instruction.h"

namespace SoundProcessor {
    class ConfigParser {
    public:
        static Instruction parse_string_to_inst(std::ifstream &config);
        static std::queue<std::unique_ptr<BaseArg>> parse_instruction(Instruction inst);
        static std::queue<std::unique_ptr<BaseArg>> parse_config_string(std::ifstream &config);
    };
}

