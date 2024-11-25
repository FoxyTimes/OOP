#pragma once

#include "Field.h"
#include "atomic"
#include "Config.h"




namespace LifeGame {

    class Printer {
    private:
        Field printer_field;
        Config cfg;
        string user_command;
        string condition;
        atomic<bool> is_printing{false};
    public:
        explicit Printer(Field &printer_field_new);

        void update_config(Config &cfg_new);

        void print_field_to_console();
        void update_printer_field(const Field& the_field);

        void print_game_cycle(const Field& the_field);

        void add_char_to_command (char ch);
        void zero_command();
        void remove_char_from_command();

        void set_condition(string cond);

        void print_standart_endl();
    };

}
