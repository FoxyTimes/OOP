//
// Created by qawwa on 27.11.2024.
//

#include "Instruction.h"
namespace SoundProcessor {
    Instruction::Instruction(bool is_comment, std::vector<std::string> instruction)
            : instruction(std::move(instruction)), is_comment(is_comment) {}

    bool Instruction::get_is_comment() const {
        return is_comment;
    }

    std::vector<std::string> &Instruction::get_instruction() {
        return instruction;
    }

    std::string Instruction::get_name() {
        return "Instruction";
    }
}