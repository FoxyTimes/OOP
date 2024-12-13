//
// Created by qawwa on 27.11.2024.
//

#include "File.h"
namespace SoundProcessor {

    int File::get_number_of_file() const {
        return number_of_file;
    }

    std::string File::get_name() {
        return "File";
    }

    File::File(int number_of_file) : number_of_file(number_of_file) {}
}
