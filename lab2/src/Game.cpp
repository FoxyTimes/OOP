#include "Game.h"
#include "Field.h"
#include "fstream"
#include "Static.h"
#include "unistd.h"
#include "iostream"
#include "conio.h"
#include "memory"
#include "mutex"

#define default_wdh 10
#define default_hgt 10

#define help_ "-help-\n'exit' - quit the program\n'pause' - pause the program\n'unpause' - unpause the program\n'tick <n=1>' - calculate n (default is 1) iterations and print the result\n'dump <filename>' - save the universe to a file\n\n IF YOU HAVE PROBLEMS WITH OUTPUT TO THE CONSOLE, THEN WRITE 'reload'"



using namespace std;

namespace LifeGame {

    Game::Game():game_field(Field(default_wdh, default_hgt)), cfg(Config()), printer(std::make_unique<Printer>(game_field)) {
    }
    Game::~Game() = default;

    void Game::run_the_game() {

        //первый кадр
        int reload_console = 10;

        if (!exit_flag) {
            Static::hide_cursor();
            (*printer).update_config(cfg);
            (*printer).print_game_cycle(game_field);
            usleep(100000);
        }


        //дебаг текстур из-за изменения размеров консоли
        previous_console_size = Static::check_console_size();

        while (!exit_flag) {
            reload_console--;
            if (reload_console==0) {
                Static::clear_console();
                reload_console=10;
            }
            vector<int> new_console_size = Static::check_console_size();
            if (previous_console_size[0]!=new_console_size[0]||previous_console_size[1]!=new_console_size[1]) {
                Static::clear_console();
                Static::hide_cursor();
            }
            previous_console_size = new_console_size;

            //Static::clear_console();

            //вывод остальных кадров

            while(pause_flag&&!exit_flag) {}

            one_game_cycle();
            Static::move_console_to_zero();
            (*printer).print_game_cycle(game_field);
            usleep(100000);

        }

        //возвращение стандартного вывода консоли

        Static::make_console_standart();
    }

    void Game::run_offline(int iterations, const string& name_output) {
        for (int i=0; i!=iterations; i++) {
            one_game_cycle();
        }
        load_to_file(name_output);
    }

    void Game::exit_the_game() {
        exit_flag=true;
    }



    bool Game::load_to_file(const std::string &name_of_file) {
        if (!name_of_file.empty()) {
            ofstream universe_file(name_of_file);

            if (!universe_file.is_open()) {
                return false;
            }

            //загрузка констант

            universe_file << "#N " << cfg.get_name() << endl;
            universe_file << "#C " << cfg.get_comment() << endl;
            universe_file << "#S " << cfg.get_size()[0] << " " << cfg.get_size()[1] << endl;
            universe_file << "#R " << cfg.get_rules()[0] << " " << cfg.get_rules()[1] << endl;


            //загрузка живых клеток

            for (int y=0; y!=cfg.get_size()[0]; y++) {
                for (int x=0; x!=cfg.get_size()[1]; x++) {
                    if (game_field.get_element(y, x).get_is_life()) {
                        universe_file << x << " " << y << endl;
                    }
                }
            }

            universe_file.close();
        }
        return true;
    }

    void Game::pause_the_game() {
        pause_flag = true;
        printer->set_condition("PAUSED");
    }

    void Game::next_iteration() {
        //ЛОГИКА
        vector<int> size = get_field().get_size();
        int flag_to_live = false;
        vector<int> to_live = Static::from_number_to_digit(cfg.get_to_live());
        vector<int> to_born = Static::from_number_to_digit(cfg.get_to_born());
        for (int y=0; y!=size[1]; y++) {
            for (int x=0; x!=size[0]; x++) {
                for (int i=0; to_born[i]!=0; i++) {
                    if (game_field.get_element(y, x).get_the_neighbors()==to_born[i]) {
                        game_field.get_element(y, x).set_is_life(true);
                    }
                }
                for (int i=0; to_live[i]!=0; i++) {
                    if (game_field.get_element(y, x).get_the_neighbors()==to_live[i]) {
                        flag_to_live = true;
                    }
                }
                if (flag_to_live==false) {
                    game_field.get_element(y, x).set_is_life(false);
                }
                flag_to_live = false;
            }
        }
    }

    void Game::new_generation() {
        game_field.recount_the_neighbors_for_all();
        next_iteration();
    }

    void Game::one_game_cycle() {
        new_generation();
        game_field.zero_neighbors();
    }

    void Game::read_the_file(const string& name_of_file="") {
        //открытие файла
        if (!name_of_file.empty()) {
            ifstream universe_file(name_of_file);
            //имя
            string format;
            getline(universe_file, format);
            cfg.rename(format);
            //комментарий
            string comment;
            getline(universe_file, comment);
            cfg.recomment(comment);
            //размер
            string size;
            getline(universe_file, size);
            cfg.resizec(size);
            game_field = Field(cfg.get_size()[1], cfg.get_size()[0]);
            //правила
            string rules;
            getline(universe_file, rules);
            cfg.rerules(rules);

            string i_line;
            int y, x;

            //живые клетки
            while (getline(universe_file, i_line)) {
                vector<string> splited_string = Static::split_str(i_line, " ");
                x = stoi(splited_string[0]);
                y = stoi(splited_string[1]);
                game_field.set_life(Static::count_the_true_index(y, cfg.get_size()[0]), Static::count_the_true_index(x, cfg.get_size()[1]), true);
            }
            universe_file.close();
        }
        else {
            //стандартное поле
            game_field.set_life(Static::count_the_true_index(0, cfg.get_size()[0]), Static::count_the_true_index(-1, cfg.get_size()[1]), true);
            game_field.set_life(Static::count_the_true_index(1, cfg.get_size()[0]), Static::count_the_true_index(0, cfg.get_size()[1]), true);
            game_field.set_life(Static::count_the_true_index(-1, cfg.get_size()[0]), Static::count_the_true_index(1, cfg.get_size()[1]), true);
            game_field.set_life(Static::count_the_true_index(0, cfg.get_size()[0]), Static::count_the_true_index(1, cfg.get_size()[1]), true);
            game_field.set_life(Static::count_the_true_index(1, cfg.get_size()[0]), Static::count_the_true_index(1, cfg.get_size()[1]), true);
        }

    }


    Printer &Game::get_printer() {
        return (*printer);
    }
    Field &Game::get_field() {
        return game_field;
    }



    void Game::game_input() {

        //поток ввода

        char ch;
        string command; // команда для парса
        while (!exit_flag) {

            //ввод символа
            if (kbhit())
            {
                ch = _getch();

                //backspace
                if (ch == '\b') {
                    (*printer).remove_char_from_command();
                    if (command.length()!=0) {
                        command.pop_back();
                    }
                }
                else {
                    (*printer).add_char_to_command(ch);
                    command += ch;
                }
            }
            //выход

            if (command == "exit\r") {
                exit_the_game();
                break;
            }

            //пауза
            if (command == "pause\r") {
                (*printer).zero_command();
                printer->set_condition("PAUSED");
                command="";
                pause_flag = true;
                ch=0;
            }

            //снятие с паузы
            if (command == "unpause\r") {
                (*printer).zero_command();
                printer->set_condition("UNPAUSED");
                command="";
                pause_flag = false;
                ch=0;
            }

            //перезагрузка консоли
            if (command == "reload\r") {
                (*printer).zero_command();
                printer->set_condition("");
                command="";
                ch=0;
            }

            //cправка
            if (command == "help\r") {
                (*printer).zero_command();
                printer->set_condition(help_);
                command="";
                ch=0;
            }

            //сохранение в файл
            if (command.find("dump ")!=string::npos) {
                vector<string> splited_string = Static::split_str(command, " ");
                if (splited_string[1].find('\r')!=string::npos) {
                    splited_string[1].pop_back();
                    int result = load_to_file(splited_string[1]);
                    (*printer).zero_command();
                    if (result) {
                        printer->set_condition("load is successful");
                    }
                    else {
                        printer->set_condition("load is NOT successful");
                    }
                    command="";
                    ch=0;
                }
            }

            //вывод n тиков + пауза
            if (command.find("tick")!=string::npos||command.find("t")!=string::npos) {
                vector<string> splited_string = Static::split_str(command, "tick ");
                if (splited_string[0].find('\r')!=string::npos) {
                    splited_string[0].pop_back();
                    pause_the_game();
                    if (splited_string[0].empty()) {
                        splited_string[0] = '1';
                    }
                    try {
                        for (int i = 0; i != abs(stoi(splited_string[0])); i++) {
                            one_game_cycle();
                        }
                    }
                    catch (std::exception) {}
                    printer->zero_command();
                    printer->set_condition("PAUSED");
                    command="";
                    Static::clear_console();
                    Static::move_console_to_zero();
                    (*printer).print_game_cycle(game_field);
                    ch=0;
                }
            }

            //вывод после паузы
            if (pause_flag) {
                Static::clear_console();
                printer->print_field_to_console();
            }

            //неправильная команда
            if (ch=='\r') {
                printer->zero_command();
                printer->set_condition("WRONG COMMAND");
                command="";
                Static::move_console_to_zero();
                (*printer).print_field_to_console();
                ch=0;
            }
            usleep(100000);
        }
        Static::make_console_standart();
    }
}