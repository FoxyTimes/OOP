#include <gtest/gtest.h>
#include "Game.h"

using namespace LifeGame;

TEST(gme, read_the_file) {
    Game the_game;

    the_game.get_printer().print_field_to_console();

    cout << endl;

    the_game.read_the_file(R"(C:\Users\qawwa\CLionProjects\lab2\src\file.txt)");

    the_game.get_printer().update_printer_field(the_game.get_field());

    the_game.get_printer().print_field_to_console();
}

TEST(gme, recount_the_neighbors_for_one) {
    Game the_game;
    the_game.read_the_file(R"(C:\Users\qawwa\CLionProjects\lab2\src\file.txt)");
    the_game.get_field().recount_the_neighbors_for_all();

}

TEST(gme, new_generation) {
    Game the_game;
    the_game.read_the_file(R"(C:\Users\qawwa\CLionProjects\lab2\src\file.txt)");
    the_game.one_game_cycle();
    the_game.one_game_cycle();
}


TEST(gme, run_offline) {
    Game the_game;
    the_game.read_the_file(R"(C:\Users\qawwa\CLionProjects\lab2\src\file.txt)");
    the_game.run_offline(20, "o.txt");
}
