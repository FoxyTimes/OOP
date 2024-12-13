#include "Static.h"
namespace SoundProcessor {


    std::string Static::copy_str(std::string str, int from_index, int to_index) {
        std::string to;
        for (int i = from_index; i != to_index; i++) {
            to.push_back(str[i]);
        }
        return to;
    }

    std::vector<std::string> Static::split_str(std::string str, std::string delim) {
        std::vector<std::string> result(10000);
        int index_in_result = 0, the_previous_index = 0, the_new_index = 0;
        for (int i = 0; i != str.length(); i++, the_new_index = i) {
            for (int j = 0; j != delim.length(); j++) {
                if (str[i] == delim[j]) {
                    result[index_in_result] = copy_str(str, the_previous_index, i);
                    if (the_previous_index != i) {
                        index_in_result++;
                    }
                    the_previous_index = i + 1;
                    break;
                }
            }
        }
        result[index_in_result] = copy_str(str, the_previous_index, the_new_index);
        return result;
    }
}