#include "thread"
#include "iostream"
#include "Static.h"
#include "Game.h"
#include <csignal>

using namespace LifeGame;
using namespace std;

#define help_input "wrong_input \n online mod:\n    <app> <filename.txt> <--pause>\n\n offline mod:\n    <app> <filename.txt> <--iterations=x> <--output=out.txt>\n\n\n\n\n FILE STRUCTURE: \n#N name\n#C comment\n#S height width\n#R B{to_born}/S{to_survive}\nlife\nx y\n\n\n\nEXAMPLE:\n#N example\n#C example\n#S 10 10\n#R B3/S23\n4 3\n2 4\n4 4\n3 5\n4 5\n"

Game the_game; // ИГРА


//ctrl+c signal

void handle_sigint(int signal) {
    the_game.exit_the_game();
}

int main(int argc, char** argv)
{
    try {
        Static::clear_console();
        signal(SIGINT, handle_sigint);

        if (argc == 1) {
            the_game.read_the_file("");
        }
        else if (argc == 2) {
            the_game.read_the_file(argv[1]);
        }
        else {
            the_game.read_the_file(argv[1]);
            vector<string> args = Static::parse_args(argc, argv);
            if (stoi(args[2])==1) {
                the_game.pause_the_game();
            }
            else {
                the_game.run_offline(stoi(args[0]), args[1]);
                return 0;
            }
        }

        //потоки

        thread thread1 = thread(&Game::game_input, &the_game);
        thread thread2 = thread(&Game::run_the_game, &the_game);

        thread1.join();
        thread2.join();
    }
    catch (exception) {
        cout << help_input;
    }

    return 0;
}