//
// Created by joshu on 11/3/2020.
//

#pragma once

#include "Item.h"
#include "Entity.h"

class BaseCounter: public Entity {
    private:
        Item *item;

    public:
        BaseCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        Item* getItem();
        void showItem();

};

class StoveCounter: public BaseCounter {
    private:
        Item *current_item;

        bool cooking=false;
        bool pattyCooked=false;
        int ticks = 0;
        int time=200;

    public:
        StoveCounter(int x, int y, int width, int height, Item* c_item, Item* u_item, ofImage sprite);
        Item* getItem(){return current_item;};
        Item *u_item;
        Item *c_item;
        void showItem();
        void tick();
        void update();
        void startCooking();
        void pickupItem();
        bool isPattyCooked() {return pattyCooked;}
};
