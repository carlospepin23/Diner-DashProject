//
// Created by joshu on 11/3/2020.
//


#include "BaseCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* c_item, Item* u_item, ofImage sprite): BaseCounter(x, y, width, height, c_item, sprite) {
    cooking = false;  // Initialize cooking flag to false
}

void StoveCounter::showItem(){
    if(pattyCooked){
        current_item=c_item;
    }
    else{
        current_item=u_item;
    }


    if (current_item!= nullptr){
        current_item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}


void StoveCounter::tick(){
    if (!pattyCooked) {  // Only increment ticks if patty is not already cooked
        ticks++;
        if(ticks >= time){
            pattyCooked=true;
        }
    }
}

void StoveCounter::update() {
    while (cooking) {  // If cooking flag is true, update the cooking process
        tick();  // Call tick() to progress cooking
        if (pattyCooked) {  // If patty is cooked, update item state and reset cooking flag
            current_item = c_item;  // Change current item to cooked item
            cooking = false;  // Reset cooking flag
        }
    }
}

void StoveCounter::startCooking() {
    if (!cooking && !pattyCooked) {  // Only start cooking if not already cooking and patty is not cooked
        cooking = true;  // Set cooking flag to true
    }
    update();
    
}

void StoveCounter::pickupItem() {
    if (pattyCooked) {  // Only pickup item if patty is cooked
        current_item = nullptr;  // Set current item to nullptr
        pattyCooked = false;  // Reset patty cooked flag
    }
}