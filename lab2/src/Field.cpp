//
// Created by qawwa on 04.11.2024.
//
#include "iostream"
#include "Field.h"
#include "Static.h"

#define default_wdh 10
#define default_hgt 10

namespace LifeGame {

    Field::Field() {
        height=default_hgt;
        width=default_wdh;
    };
    Field::~Field() = default;

    Field::Field(int width, int height) {
        this->width = width;
        this->height = height;

        field.resize(height);
        for (int i = 0; i != height; i++) {
            field[i].resize(width);
        }
    }

    Cell &Field::get_element(int y, int x) {
        return field[y][x];
    }

    void Field::set_life(int y, int x, bool to_set) {
        field[y][x].set_is_life(to_set);
    }

    vector<int> Field::get_size() const {
        vector<int> size = {width, height};
        return size;
    }

    void Field::zero_neighbors() {
        for (int y=0; y!=height; y++) {
            for (int x=0; x!=width; x++) {
                get_element(y, x).zero_neighbor();
            }
        }
    }

    void Field::recount_the_neighbors_for_one(int y, int x) {
        for (int i=-1; i!=2; i++) {
            for (int j=-1; j!=2; j++) {
                if (i==0&&j==0) {
                    continue;
                }
                if (get_element(Static::count_the_true_index(y + i, get_size()[1]), Static::count_the_true_index(x + j, get_size()[0])).get_is_life() == 1) {
                    get_element(y, x).add_the_neighbor();
                }
            }
        }
    }

    void Field::recount_the_neighbors_for_all() {
        for (int y=0; y!=height; y++) {
            for (int x=0; x!=width; x++) {
                recount_the_neighbors_for_one(y, x);
            }
        }
    }
}


