//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;
    vector<Item *> ingredients;

public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void undoIngredient();
    bool hasIngredients();
    void render();
    void clear();
    bool equals(Burger*);
    void setY(int y) {
        this->y = y;
    }
};
