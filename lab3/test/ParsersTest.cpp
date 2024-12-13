#include <gtest/gtest.h>
#include "parsers/ConfigParser.h"
#include "fileswork/FileManager.h"
#include "queue"
#include "memory"
#include "defines/testfiles.h"

using namespace SoundProcessor;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(pars, config_parser) {
    FileManager& fm = FileManager::getInstance();
    fm.open_config(defconfig);
    while (!fm.get_config().eof()) {
        Instruction our_inst = ConfigParser::parse_string_to_inst(fm.get_config());
        std::queue<std::unique_ptr<BaseArg>> result = ConfigParser::parse_instruction(our_inst);
    }

}
