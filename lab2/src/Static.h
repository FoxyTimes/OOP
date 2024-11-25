#pragma once
#include "vector"
#include "string"

enum ConsoleColor
{
    Black         = 0,
    Blue          = 1,
    Green         = 2,
    Cyan          = 3,
    Red           = 4,
    Magenta       = 5,
    Brown         = 6,
    LightGray     = 7,
    DarkGray      = 8,
    LightBlue     = 9,
    LightGreen    = 10,
    LightCyan     = 11,
    LightRed      = 12,
    LightMagenta  = 13,
    Yellow        = 14,
    White         = 15
};

namespace LifeGame {
    class Static {
    public:
        static int count_the_true_index(int index, int border);
        static std::string copy_str(std::string str, int from_index, int to_index);
        static std::vector<std::string> split_str(std::string str, std::string delim);
        static std::vector<int> from_number_to_digit(int number);
        static void set_console_color(ConsoleColor text, ConsoleColor background);
        static void move_console_to_zero();
        static void clear_console();
        static std::vector<std::string> parse_args(int argc, char ** argv);
        static void hide_cursor();
        static void make_cursor_visible();
        static void make_console_standart();
        static std::vector<int> check_console_size();
    };
}