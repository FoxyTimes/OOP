#include "Config.h"
#include <utility>
#include "Static.h"

using namespace std;


namespace LifeGame {
    Config::Config(string name, string comment, vector<int> size, vector<int> rules) {
        this->name = std::move(name);
        this->comment = std::move(comment);
        this->size = std::move(size);
        this->rules = std::move(rules);
    }

    void Config::rename(string new_name) {
        vector<string> splited_str = Static::split_str(std::move(new_name), "#N ");
        name = splited_str[0];
    }
    void Config::recomment(string new_comment) {
        vector<string> splited_str = Static::split_str(std::move(new_comment), "#C ");
        comment = splited_str[0];
    }

    void Config::resizec(string new_size) {
        vector<string> splited_str = Static::split_str(std::move(new_size), "#S ");
        int height = stoi(splited_str[0]);
        int width = stoi(splited_str[1]);
        vector<int> normal_size = {height, width};
        size = normal_size;
    }

    void Config::rerules(string new_rules) {
        vector<string> splited_str = Static::split_str(std::move(new_rules), "#R B/S");
        int to_born = stoi(splited_str[0]);
        int to_live = stoi(splited_str[1]);
        vector<int> normal_rules = {to_born, to_live};
        rules = normal_rules;
    }

    vector<int> Config::get_rules() {
        return rules;
    }

    int Config::get_to_live() {
        return rules[1];
    }

    vector<int> Config::get_size() {
        return size;
    }

    string Config::get_comment() {
        return comment;
    }

    int Config::get_to_born() {
        return rules[0];
    }

    string Config::get_name() {
        return name;
    }
}