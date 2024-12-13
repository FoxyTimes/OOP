#pragma once
#include "fileswork/FileManager.h"
#include "types/SampleBlock.h"
namespace SoundProcessor {

    class WavManager {
    public :
        static void load_sample_block(SampleBlock sampleblock, int offset);
    };

}
