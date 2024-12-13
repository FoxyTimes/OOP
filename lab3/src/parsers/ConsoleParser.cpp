#include "ConsoleParser.h"
#include "Printer.h"

namespace SoundProcessor {
    void SoundProcessor::ConsoleParser::parse_console_command(int argc, char ** argv) {

        std::string our_argument, config;
        FileManager& file_manager = FileManager::getInstance();
        std::vector<std::string> inputs;
        bool is_output_file = false;

        for (int i = 1; i != argc; i++) {
            our_argument = argv[i];
            if (our_argument == "-h") {
                Printer::print_help();
                exit(0);
            }
            else if (our_argument == "-c") {
                try {
                    config = argv[i + 1];
                    file_manager.open_config(config);
                    i++;
                }
                catch(std::exception &e) {
                    throw std::runtime_error("Troubles with config");
                }
                continue;
            }
            else if (!is_output_file&&argc>=5) {
                file_manager.open_output(our_argument);
                is_output_file = true;
                continue;
            }
            else {
                inputs.push_back(our_argument);
            }
        }
        file_manager.open_inputs(inputs);
    }
}
