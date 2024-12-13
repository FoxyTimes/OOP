#include "FileManager.h"
#include "string"

namespace SoundProcessor {
    FileManager FileManager::instance;

    void FileManager::open_config(const std::string& name_of_config) {
        if (name_of_config.empty()) {
            throw std::runtime_error("NONE NAME OF CONFIG");
        }
        config.open(name_of_config);
        if (!config.is_open()) {
            throw std::runtime_error("CANT OPEN THE CONFIG FILE $" + name_of_config);
        }
    }

    std::ifstream& FileManager::get_config() {
        return config;
    }

    void FileManager::open_inputs(const std::vector<std::string>& names_of_input) {
        if (names_of_input.empty()) {
            throw std::runtime_error("NONE OF INPUT FILES");
        }
        for (int i=0; i!=names_of_input.size(); i++) {
            if (names_of_input[i].empty()) {
                throw std::runtime_error("NONE NAME OF INPUTS $" + std::to_string(i));
            }
            std::fstream input;
            input.open(names_of_input[i], std::ios::binary | std::ios::in | std::ios::out);
            inputs.push_back(std::move(input));
            if (!inputs[i].is_open()) {
                throw std::runtime_error("CANT OPEN THE INPUT FILE $" + names_of_input[i]);
            }
        }
    }

    std::vector<std::fstream>& FileManager::get_inputs() {
        return inputs;
    }

    void FileManager::open_output(const std::string& name_of_output) {
        if (name_of_output.empty()) {
            throw std::runtime_error("NONE NAME OF OUTPUT");
        }
        output.open(name_of_output,std::ios::out | std::ios::trunc | std::ios::binary | std::ios::in);
        if (!output.is_open()) {
            throw std::runtime_error("CANT OPEN THE OUTPUT FILE $" + name_of_output);
        }
    }

    std::fstream& FileManager::get_output() {
        return output;
    }

    FileManager& FileManager::getInstance() {
        return instance;
    }

    FileManager::~FileManager() {
        if (config.is_open()) {
            config.close();
        }
        for (auto& input : inputs) {
            if (input.is_open()) {
                input.close();
            }
        }
        if (output.is_open()) {
            output.close();
        }
    }

    void FileManager::copy_input1_to_output() {

        const size_t buffer_size = 4096;
        char buffer[buffer_size];

        while (inputs[0].read(buffer, buffer_size)) {
            output.write(buffer, inputs[0].gcount());
        }

        if (inputs[0].gcount() > 0) {
            output.write(buffer, inputs[0].gcount());
        }

        inputs[0].clear();

        count_blocks();

    }

    long long int FileManager::count_blocks() {
        std::fstream& output = get_output();
        if (!output.is_open()) {
            throw std::runtime_error("Output file is not open.");
        }

        const size_t block_size = 44100 * sizeof(short);

        output.seekp(0, std::ios::end);
        size_t file_size = output.tellp();

        blocks = file_size / block_size;
        return blocks;
    }

    long long int FileManager::get_blocks() const {
        return blocks;
    }


}