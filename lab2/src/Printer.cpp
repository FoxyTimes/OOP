#include "iostream"
#include "Printer.h"
#include <utility>
#include "Static.h"


namespace LifeGame {
    Printer::Printer(Field &printer_field_new):printer_field(printer_field_new), is_printing(false) {
    }


    void Printer::update_config(Config &cfg_new) {
        cfg = cfg_new;
    }

    void Printer::add_char_to_command(char ch) {
        user_command += ch;
    }

    void Printer::remove_char_from_command() {
        if (user_command.length()!=0) {
            user_command.pop_back();
            print_field_to_console();
            Static::clear_console();
        }
    }

    void Printer::zero_command() {
        user_command = "";
        is_printing=true;
        Static::clear_console();
        is_printing=false;
    }

    void Printer::print_standart_endl() {
        Static::set_console_color(Black, Black);
        cout << endl;
    }

    void Printer::print_field_to_console() {

        //предохранитель
        while (is_printing) {}
        //включение предохранителя
        is_printing=true;

        //постановка курсора
        Static::move_console_to_zero();
        Static::set_console_color(Magenta, Black);
        //вывод констант
        cout << cfg.get_name() << endl << cfg.get_comment() << endl;
        print_standart_endl();
        string out_life;
        string out_dead;
        vector<int> size = printer_field.get_size();
        //оптимизированный вывод
        for (int y=0; y!=size[1]; y++) {
            for (int x=0; x!=size[0]; x++) {
                if (printer_field.get_element(y, x).get_is_life()) {
                    if (out_dead.length()!=0) {
                        Static::set_console_color(White, White);
                        cout << out_dead;
                        out_dead = "";
                    }
                    out_life += "  ";
                }

                else {
                    if (out_life.length()!=0) {
                        Static::set_console_color(Green, Green);
                        cout << out_life;
                        out_life = "";
                    }
                    out_dead += "  ";
                }
                Static::set_console_color(Black, Black);
            }
            if (out_dead.length()!=0) {
                Static::set_console_color(White, White);
                cout << out_dead;
                out_dead="";
            }
            if (out_life.length()!=0) {
                Static::set_console_color(Green, Green);
                cout << out_life;
                out_life="";
            }
            print_standart_endl();
        }

        //вывод конечных констант
        print_standart_endl();
        Static::set_console_color(Magenta, Black);
        cout << user_command;
        print_standart_endl();
        Static::set_console_color(Magenta, Black);
        cout<<condition;
        print_standart_endl();
        //выключение предохранителя
        is_printing=false;
    }

    void Printer::update_printer_field(const Field& the_field) {
        printer_field = the_field;
    }

    void Printer::set_condition(string cond) {
        condition = std::move(cond);
    }

    void Printer::print_game_cycle(const Field& the_field) {
        update_printer_field(the_field);
        print_field_to_console();
    }
}