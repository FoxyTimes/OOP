#include "WavManager.h"
#include "FileManager.h"
#include <stdexcept>

namespace SoundProcessor {

    void SoundProcessor::WavManager::load_sample_block(SampleBlock sampleblock, int offset) {
        FileManager& file_manager = FileManager::getInstance();
        std::fstream& output = file_manager.get_output();

        if (!output.is_open()) {
            throw std::runtime_error("Error opening output file.");
        }

        if(sampleblock.get_number()>file_manager.get_blocks()) {
            throw std::runtime_error("out of range");
        }

        long long int position = sampleblock.get_position(offset);
        output.seekp(position, std::ios::beg);

        std::vector<short>& data = sampleblock.get_block();
        output.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(short));

        output.clear();
        output.seekg(0);
        output.seekp(0);
    }
}
