//
// Created by qawwa on 30.11.2024.
//

#include "InstName.h"

#include <utility>

SoundProcessor::InstName::InstName(std::string name_of_inst) : name_of_inst(std::move(name_of_inst)) {}

std::string SoundProcessor::InstName::get_name() {
    return "InstName";
}

std::string SoundProcessor::InstName::get_name_inst() {
    return name_of_inst;
}
