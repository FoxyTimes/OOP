#include "Muter.h"
#include <utility>
#include "types/Times.h"
#include "memory"
#include "types/SampleBlock.h"
#include "iostream"
#include "wavmanager/WavManager.h"
#include "types/Head.h"
namespace SoundProcessor {
    void Muter::convert() {
        if (!(queue_of_args.front()->get_name()=="Times")) {
            throw std::runtime_error("Not time in config at mute");
        }
        std::unique_ptr<BaseArg> basePtr1 = std::move(queue_of_args.front());
        std::unique_ptr<Times> from = std::unique_ptr<Times>(dynamic_cast<Times*>(basePtr1.release()));
        queue_of_args.pop();
        if (!(queue_of_args.front()->get_name()=="Times")) {
            throw std::runtime_error("Not time in config at mute");
        }
        std::unique_ptr<BaseArg> basePtr2 = std::move(queue_of_args.front());
        std::unique_ptr<Times> to = std::unique_ptr<Times>(dynamic_cast<Times*>(basePtr2.release()));
        queue_of_args.pop();

        for (long long int i=from->get_time(); i!=to->get_time(); i++) {
            SampleBlock sample_block(i);
            WavManager::load_sample_block(sample_block, ABSOLUTE_OFFSET);
        }
    }

    Muter::Muter(std::queue<std::unique_ptr<BaseArg>> queue_of_args) : queue_of_args(std::move(queue_of_args)) {}

    std::queue<std::unique_ptr<BaseArg>> Muter::get_args() {
        return std::move(queue_of_args);
    }
}