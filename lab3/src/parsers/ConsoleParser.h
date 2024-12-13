#pragma once

#include "memory"
#include "fileswork/FileManager.h"

namespace SoundProcessor {

    class ConsoleParser {
    public:
        static void parse_console_command(int argc, char ** argv);
    };
}