#include "Static.h"
#include "string"
#include <windows.h>
#include <utility>
#include "vector"
#include "iostream"
#include "unistd.h"


namespace LifeGame {
    int Static::count_the_true_index(int index, int border) {
        int new_index = index%border;
        if (index<0) {
            new_index = index+border;
        }
        return new_index;
    }

    void Static::clear_console() {
        system("cls");
    }

    std::string Static::copy_str(std::string str, int from_index, int to_index) {
        std::string to;
        for (int i=from_index; i!=to_index; i++) {
            to.push_back(str[i]);
        }
        return to;
    }
    std::vector<std::string> Static::split_str(std::string str, std::string delim) {
        std::vector<std::string> result(10000);
        int index_in_result=0, the_previous_index=0, the_new_index=0;
        for (int i=0; i!=str.length(); i++, the_new_index=i) {
            for (int j=0; j!=delim.length(); j++) {
                if (str[i]==delim[j]) {
                    result[index_in_result] = copy_str(str, the_previous_index, i);
                    if (the_previous_index!=i) {
                        index_in_result++;
                    }
                    the_previous_index=i+1;
                    break;
                }
            }
        }
        result[index_in_result] = copy_str(str, the_previous_index, the_new_index);
        return result;
    }


    std::vector<int> Static::from_number_to_digit(int number) {
        std::vector<int> digits;
        digits.resize(1000);
        for(int i=0; number!=0; i++) {
            digits[i] = number % 10;
            number /= 10;
        }
        return digits;
    }

    void Static::make_console_standart() {
        Static::make_cursor_visible();
        Static::set_console_color(White, Black);
        Static::clear_console();
    }

    void Static::move_console_to_zero() {
        COORD position = {0,0}; //позиция x и y
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsole, position);
    }
    void Static::set_console_color(ConsoleColor text, ConsoleColor background)
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }

    std::vector<std::string> Static::parse_args(int argc, char ** argv) {
        std::string iterations;
        std::string output_name;
        std::string pause_flag;
        for (int i=0; i!=argc; i++) {
            std::string temp_argv = argv[i];
            if (temp_argv == "-o") {
                output_name = argv[i+1];
            }
            if (temp_argv == "-i") {
                iterations = argv[i+1];
            }
            if (temp_argv == "-p") {
                pause_flag='1';
            }
            if (temp_argv.find("--output=")!=std::string::npos) {
                std::vector<std::string> splited_str = split_str(temp_argv, "=");
                output_name = splited_str[1];
            }
            if (temp_argv.find("--iterations=")!=std::string::npos) {
                std::vector<std::string> splited_str = split_str(temp_argv, "=");
                iterations = splited_str[1];
            }
            if (temp_argv.find("--pause")!=std::string::npos) {
                pause_flag='1';
            }
        }
        std::vector<std::string> result = {iterations, output_name, pause_flag};
        return result;
    }

    void Static::hide_cursor() {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
    }

    void Static::make_cursor_visible() {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 1;
        info.bVisible = 4;
        SetConsoleCursorInfo(consoleHandle, &info);
    }

    std::vector<int> Static::check_console_size() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
            int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
            std::vector<int> result = {height, width};
            return result;
        }
        std::vector<int> result = {0, 0};
        return result;
    }


}