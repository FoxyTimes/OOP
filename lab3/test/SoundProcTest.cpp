#include <gtest/gtest.h>
#include "SoundProc.h"
#include "defines/testfiles.h"


using namespace SoundProcessor;

TEST(sp, run) {
    try {
        SoundProc sp;
        char* argv[] = {"program_name", "-c"};
        sp.run(6, argv);
    }
    catch (std::exception &e) {
        std::cerr << std::endl <<std::endl << "!!!!!!Error: " << e.what() << "!!!!!!" << std::endl << std::endl;
    }
}