//
// Created by qawwa on 28.11.2024.
//

#include "Times.h"
namespace SoundProcessor {
    std::string Times::get_name() {
        return "Times";
    }

    int Times::get_time() const {
        return seconds;
    }

    Times::Times(int seconds) : seconds(seconds) {}
}