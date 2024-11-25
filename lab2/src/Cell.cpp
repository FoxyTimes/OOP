//
// Created by qawwa on 04.11.2024.
//
#include "Cell.h"

namespace LifeGame {
    Cell::Cell() {
        is_life = false;
        neighbors = 0;
    }

    bool Cell::get_is_life() {
        return is_life;
    }

    void Cell::set_is_life(bool to_set) {
        this->is_life=to_set;
    }

    void Cell::add_the_neighbor() {
        neighbors++;
    }

    void Cell::zero_neighbor() {
        neighbors=0;
    }

    int Cell::get_the_neighbors() const {
        return neighbors;
    }
}