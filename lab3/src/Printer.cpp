
#include "Printer.h"
#include "iostream"

namespace SoundProcessor {

    void SoundProcessor::Printer::print_help() {
        std::cout << "Console: sound_processor [-h] [-c config.txt output.wav input1.wav input2.wav ...]\n\nConfig:\n command [argument1] [argument2]...\n command [argument1] [argument2]...\n...\n\n\n Commands:\nmix [$number_of_file] [time_from_mix]\nmute [time_from_mute] [time_to_mute]\nprune [$number_of_file] [time_from_prune]\n";
    }
}
