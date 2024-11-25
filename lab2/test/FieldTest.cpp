#include <gtest/gtest.h>
#include "Field.h"

using namespace LifeGame;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(fld, field_print_console) {
    Field test_field(10, 10);

    Field test_field2(20, 5);
}