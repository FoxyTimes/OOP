#pragma once

#include <fstream>
#include <vector>
#include "memory"

namespace SoundProcessor {
    class FileManager {
    private:
        static FileManager instance;
        std::ifstream config;
        std::vector<std::fstream> inputs;
        std::fstream output;

        long long int blocks=0;

        FileManager() = default;
        FileManager(const FileManager&) = delete;
        FileManager& operator=(const FileManager&) = delete;


    public:
        static FileManager& getInstance();

        ~FileManager();

        void open_config(const std::string& name_of_config);
        void open_inputs(const std::vector<std::string>& names_of_input);
        void open_output(const std::string& name_of_output);
        std::ifstream& get_config();
        std::vector<std::fstream>& get_inputs();
        std::fstream& get_output();
        long long int count_blocks();

        void copy_input1_to_output();

        long long int get_blocks() const;
    };
}