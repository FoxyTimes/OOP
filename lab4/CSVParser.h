#pragma once
#include <iostream>
#include <fstream>
#include <tuple>
#include <string>
#include <sstream>
#include "Static.h"
#include <vector>
#include "TupleConverter.h"

// Шаблонный класс CSVParser
template <typename... Args>
class CSVParser {
private:
    std::ifstream &file;
    int start_string;

public:
    CSVParser(std::ifstream &file, int start) : file(file), start_string(start) {}


    class CSViterator {
    private:
        int current_line;
        std::ifstream &file;
        std::string buffer;
    public:
        CSViterator(std::ifstream &file, int start, CSVParser& parser) : file(file), current_line(start) {
            if (current_line!=-1) {
                if(!std::getline(file, buffer)) {
                    current_line=-1;
                }
            }
        }

        bool operator!=(const CSViterator& other) {
            return current_line != other.current_line;
        }

        CSViterator& operator++() {

            if(std::getline(file, buffer)) {
                current_line++;
            }
            else {
                current_line=-1;
            }

            return *this;
        }

        std::tuple<Args...> operator*() {
            if (!buffer.empty()) {
                return parse_line(buffer);
            } else {
                return std::tuple<Args...>{};
            }
        }

        std::tuple<Args...> parse_line(const std::string& line) {

            auto splited_string = Static::split_str(line, ',', '"');
            auto tup = vector_to_tuple<Args...>(splited_string);
            return tup;
        }
    };

    CSViterator begin() {
        return CSViterator(file, start_string, *this);
    }

    CSViterator end() {
        return CSViterator(file, -1, *this);
    }
};
