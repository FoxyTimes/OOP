#include <gtest/gtest.h>
#include "Config.h"

using namespace LifeGame;

TEST(cfg, get_normal_size) {
    Config cfg;
    string first = "#S #S ## S143# 122123#";

    cfg.resizec(first);

    int height = cfg.get_size()[0];
    int width = cfg.get_size()[1];

    ASSERT_EQ(height, 143);
    ASSERT_EQ(width, 122123);
}