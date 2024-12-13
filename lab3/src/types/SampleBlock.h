#pragma once
#include "vector"
#include "types/File.h"
#include "memory"

namespace SoundProcessor {
    class SampleBlock {
    private:
        std::vector<short> sample_block;
        long long int number_of_block;
    public:
        explicit SampleBlock(long long int number_of_block);
        explicit SampleBlock(long long int number_of_block, const File& file);
        long long int get_number() const;
        std::vector<short>& get_block();
        [[nodiscard]] long long int get_position(int offset) const;
    };

}
