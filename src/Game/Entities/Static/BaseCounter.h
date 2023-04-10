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
        virtual void showItem();

};

class StoveCounter: public BaseCounter {
    private:
        Item *current_item;
        bool cooking;
        bool pattyCooked=false;
        int ticks = 0;
        int time=200;

    public:
        StoveCounter(int x, int y, int width, int height, Item* c_item, Item* u_item, ofImage sprite);
        Item *u_item;
        Item *c_item;
        Item* getItem(){return this->current_item;};
        void setCurrent_Item(Item* item){this->current_item=item;}
        void showItem();
        void tick();
        void update();
        void startCooking();
        void pickupItem();
        bool isPattyCooked() {return pattyCooked;}
};
