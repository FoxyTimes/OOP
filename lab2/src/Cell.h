#pragma once

namespace LifeGame {


    class Cell {
    private:
        char neighbors = 0;
        bool is_life = false;
    public:
        Cell();

        bool get_is_life();
        void set_is_life(bool to_set);
        void add_the_neighbor();
        void zero_neighbor();
        int get_the_neighbors() const;
    };
}

