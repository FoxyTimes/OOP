#pragma once
#include "string"
#include "vector"

using namespace std;

namespace LifeGame {

    class Config {
    private:
        string name;
        string comment;
        vector<int> size;
        vector<int> rules;
    public:
        explicit Config(string name="glider", string comment="default", vector<int> size={10, 10}, vector<int> rules={3, 23});
        void rename(string new_name);
        void recomment(string new_comment);
        int get_to_live();
        void resizec(string new_size);
        void rerules(string new_rules);
        vector<int> get_size(); //height width
        vector<int> get_rules();
        int get_to_born();
        string get_comment();
        string get_name();

    };
}