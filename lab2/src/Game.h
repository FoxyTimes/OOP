#include "string"
#include "Field.h"
#include "Printer.h"
#include "Config.h"
#include <atomic>
#include "memory"

using namespace std;


namespace LifeGame {
    class Game {
    private:
        long int iteration = 0;
        Field game_field;
        std::unique_ptr<Printer> printer;
        Config cfg;
        vector<int> previous_console_size;
        atomic<bool> exit_flag{false};
        atomic<bool> pause_flag{false};
    public:
        Game();

        ~Game();

        void run_the_game();
        void run_offline(int iterations, const string& name_output);
        void pause_the_game();
        void exit_the_game();

        void game_input();

        void next_iteration();
        void new_generation();

        void read_the_file(const string& name_of_file);
        bool load_to_file (const string& name_of_file);

        Printer &get_printer();
        Field &get_field();

        void one_game_cycle();
    };
}