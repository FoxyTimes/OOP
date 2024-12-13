#include "Mixer.h"
#include "types/Times.h"
#include "types/File.h"
#include "types/Head.h"
#include "SampleBlock.h"
#include "WavManager.h"

namespace SoundProcessor {

    Mixer::Mixer(std::queue<std::unique_ptr<BaseArg>> queue_of_args) : queue_of_args(std::move(queue_of_args)) {

    }

    void Mixer::convert() {
        if (!(queue_of_args.front()->get_name()=="File")) {
            throw std::runtime_error("Not file in config at mix");
        }
        std::unique_ptr<BaseArg> basePtr1 = std::move(queue_of_args.front());
        std::unique_ptr<File> file_to_mix = std::unique_ptr<File>(dynamic_cast<File*>(basePtr1.release()));
        queue_of_args.pop();
        if (!(queue_of_args.front()->get_name()=="Times")) {
            throw std::runtime_error("Not time in config at mix");
        }
        std::unique_ptr<BaseArg> basePtr2 = std::move(queue_of_args.front());
        std::unique_ptr<Times> from = std::unique_ptr<Times>(dynamic_cast<Times*>(basePtr2.release()));
        queue_of_args.pop();

        Head head_2(*file_to_mix);
        File output(0);

        for (long long int i=from->get_time();;i++) {
            SampleBlock sample_block_1(i, output);
            SampleBlock sample_block_2(i, *file_to_mix);
            if (sample_block_1.get_block().size()<44100||sample_block_2.get_block().size()<44100) {
                break;
            }
            for (int j=0; j!=44100; j++) {
                int mixed_sample = sample_block_1.get_block()[j] + sample_block_2.get_block()[j];
                mixed_sample = std::max(-32768, std::min(32767, mixed_sample));
                sample_block_1.get_block()[j] = mixed_sample / 2;
            }
            WavManager::load_sample_block(sample_block_1, ABSOLUTE_OFFSET);
        }
    }

    std::queue<std::unique_ptr<BaseArg>> Mixer::get_args() {
        return std::move(queue_of_args);
    }
}
