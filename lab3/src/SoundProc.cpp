
#include "SoundProc.h"
#include "FileManager.h"
#include "memory"
#include "parsers/ConsoleParser.h"
#include "parsers/ConfigParser.h"
#include "queue"
#include "Head.h"
#include "converters/Factory.h"

namespace SoundProcessor {

    void SoundProc::run(int argc, char **argv) {
        ConsoleParser::parse_console_command(argc, argv);
        FileManager& file_manager = FileManager::getInstance();
        std::queue<std::unique_ptr<BaseArg>> queue_of_arguments;
        file_manager.copy_input1_to_output();

        File file(0);
        Head head(file);

        while (!file_manager.get_config().eof()) {
            queue_of_arguments = ConfigParser::parse_config_string(file_manager.get_config());
            if (!queue_of_arguments.empty()) {
                std::unique_ptr<Converter> converter = Factory::create_converter(std::move(queue_of_arguments));
                converter->convert();
            }
        }
    }
}