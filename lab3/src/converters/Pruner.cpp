#include "Times.h"
#include "File.h"
#include "Head.h"
#include "Pruner.h"
#include "SampleBlock.h"
#include "WavManager.h"

namespace SoundProcessor {

    Pruner::Pruner(std::queue<std::unique_ptr<BaseArg>> queue_of_args) : queue_of_args(std::move(queue_of_args)) {}

    void Pruner::convert() {
        if (!(queue_of_args.front()->get_name()=="File")) {
            throw std::runtime_error("Not file in config at prune");
        }
        std::unique_ptr<BaseArg> basePtr1 = std::move(queue_of_args.front());
        std::unique_ptr<File> file_to_prune = std::unique_ptr<File>(dynamic_cast<File*>(basePtr1.release()));
        queue_of_args.pop();
        if (!(queue_of_args.front()->get_name()=="Times")) {
            throw std::runtime_error("Not time in config at prune");
        }
        std::unique_ptr<BaseArg> basePtr2 = std::move(queue_of_args.front());
        std::unique_ptr<Times> point = std::unique_ptr<Times>(dynamic_cast<Times*>(basePtr2.release()));
        queue_of_args.pop();

        Head head_2(*file_to_prune);

        File output(0);

        for (long long int i=point->get_time();;i++) {
            SampleBlock sample_block_1(i, output);
            SampleBlock sample_block_2(i, *file_to_prune);
            sample_block_1.get_block()=sample_block_2.get_block();
            if (sample_block_1.get_block().size()<44100||sample_block_2.get_block().size()<44100) {
                break;
            }
            WavManager::load_sample_block(sample_block_1, ABSOLUTE_OFFSET);
        }
    }

    std::queue<std::unique_ptr<BaseArg>> Pruner::get_args() {
        return std::move(queue_of_args);
    }
}