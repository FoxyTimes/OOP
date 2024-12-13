#include "SampleBlock.h"
#include "FileManager.h"
#include "memory"

namespace SoundProcessor {

    SampleBlock::SampleBlock(long long int number_of_block, const File& file) : number_of_block(number_of_block) {
        FileManager& file_manager = FileManager::getInstance();

        std::fstream& input_file = (file.get_number_of_file() != 0)
                                   ? file_manager.get_inputs()[file.get_number_of_file()-1]
                                   : file_manager.get_output();

        if (!input_file.is_open()) {
            throw std::runtime_error("Error with opening input file while loading sample blocks");
        }

        input_file.seekg(44, std::ios::beg);
        int block_size = 44100;
        long long int offset = number_of_block * block_size * sizeof(short);
        input_file.seekg(44 + offset, std::ios::beg);

        std::vector<char> buffer(block_size * sizeof(short));
        input_file.read(buffer.data(), buffer.size());

        size_t bytes_read = input_file.gcount();
        if (bytes_read < buffer.size()) {
            buffer.resize(bytes_read);
        }

        if (input_file.fail() && !input_file.eof()) {
            throw std::runtime_error("Error reading data for block");
        }

        size_t num_shorts = buffer.size() / sizeof(short);
        sample_block.resize(num_shorts);

        for (size_t i = 0; i < num_shorts; ++i) {
            memcpy(&sample_block[i], &buffer[i * sizeof(short)], sizeof(short));
        }

        if (bytes_read % sizeof(short) != 0) {
            sample_block.resize(bytes_read / sizeof(short));
        }
    }

    std::vector<short>& SampleBlock::get_block() {
        return sample_block;
    }

    SampleBlock::SampleBlock(long long int number_of_block) : number_of_block(number_of_block) {
        sample_block.resize(44100, 0);
    }

    long long int SampleBlock::get_position(int offset) const {
        int block_size = 44100;
        return number_of_block * block_size * sizeof(short) + offset;
    }

    long long int SampleBlock::get_number() const {
        return number_of_block;
    }
}
