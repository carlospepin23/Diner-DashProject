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
    map<string,int> order={
      {"tomato",0},
      {"lettuce",0},
      {"cheese",0},
      {"patty",0}  
    };
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
