#include "Static.h"
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> Static::split_str(const std::string& input_str, char separator, char escape_char) {

    std::vector<std::string> result_strings;
    std::string current_string;

    bool is_screening = false;

    for (int i = 0; i !=input_str.size(); i++) {
        if (!is_screening && input_str[i] == escape_char) {
            is_screening = true;
            continue;
        }
        if (is_screening && input_str[i] == escape_char) { //экранирование escapechar
            is_screening = false;
            current_string.push_back(escape_char);
            continue;
        }
        if (is_screening && input_str[i] == separator) { //экранирование separator
            is_screening = false;
            current_string.push_back(separator);
            continue;
        }
        if (!is_screening && input_str[i] == separator) {
            result_strings.push_back(current_string);
            current_string="";
            continue;
        }
        current_string.push_back(input_str[i]);
    }

    result_strings.push_back(current_string);

    return result_strings;
}
