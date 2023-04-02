//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::undoIngredient() {
    ingredients.pop_back();
}

void Burger::render(){
    int counter = 1;
    ofSetColor(256,256,256);
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.clear();  //empty function wasnt working so it was re-defined
}

bool Burger::hasIngredients(){
    if(!ingredients.empty()){
        return true;
    }
    else{
        return false;
    }
}

bool Burger::equals(Burger* player_b){
    
    if((player_b->ingredients[0]->name!="bottomBun") && (player_b->ingredients[ingredients.size()-1]->name!="topBun")) return false;

    if(this->ingredients.size()!=player_b->ingredients.size()) return false;
    
    int buns=0;
    for(Item *ingredients: player_b->ingredients){
        if(ingredients->name=="bottomBun" || ingredients->name=="topBun") buns+=1;
        
    }
    if(buns<2) return false;

    return true;

    }