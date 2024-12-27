#include <iostream>
#include <tuple>
#include <string>
#include <iostream>
#include "printer.h"
#include "iostream"
#include "CSVParser.h"

int main(int, char**){
    std::ifstream file("test.csv");
    CSVParser<int, float, std::string> parser(file, 0);
    for (std::tuple<int, float, std::string> rs : parser) {
        std::cout<<rs<<std::endl;
    }
}