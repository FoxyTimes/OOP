#pragma once

#include "vector"
#include "Cell.h"


using namespace std;

namespace LifeGame {

    class Field {
    private:
        int width;
        int height;
        vector<vector<Cell>> field;
    public:
        Field();
        ~Field();

        Field(int width, int height);

        Cell &get_element(int y, int x);
        void set_life(int y, int x, bool to_set);

        [[nodiscard]] vector<int> get_size() const;

        void recount_the_neighbors_for_one(int y, int x);
        void recount_the_neighbors_for_all();
        void zero_neighbors();
    };
}
