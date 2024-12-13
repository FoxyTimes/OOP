#include <iostream>
#include <stdexcept>
#include "FileManager.h"
#include "ConfigParser.h"
#include "string"
#include "vector"
#include "BaseArg.h"
#include "SoundProc.h"
#include "Printer.h"
#include <windows.h> // Для работы с цветами в консоли Windows

using namespace SoundProcessor;

void set_red_text() {
    // Получаем дескриптор стандартного потока ошибок (stderr)
    HANDLE hConsole = GetStdHandle(STD_ERROR_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        return;  // Ошибка получения дескриптора
    }

    // Устанавливаем красный цвет для текста
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void reset_text_color() {
    // Сбрасываем цвет на стандартный
    HANDLE hConsole = GetStdHandle(STD_ERROR_HANDLE);
    if (hConsole != INVALID_HANDLE_VALUE) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);  // Белый цвет
    }
}

int main(int argc, char** argv)
{
    SoundProc sd;
    try {
        sd.run(argc, argv);
    }
    catch (std::exception &e) {
        set_red_text();
        std::cerr << std::endl <<std::endl << "!!!!!!Error: " << e.what() << "!!!!!!" << std::endl << std::endl;
        reset_text_color();
        Printer::print_help();
    }

    return 0;
}
