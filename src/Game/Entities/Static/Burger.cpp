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
    
    //Chequea si el primer ingrendiente es botBread y el ultimo topBread
    if((player_b->ingredients[0]->name!="bottomBun") && (player_b->ingredients[ingredients.size()-1]->name!="topBun")) return false;

    //Chequea por un mismo size de ingredientes
    if(this->ingredients.size()!=player_b->ingredients.size()) return false;
    
    //Chequea por duplicados de pan
    int buns=0;
    for(Item *ingredients: player_b->ingredients){
        if(ingredients->name=="bottomBun" || ingredients->name=="topBun") buns+=1;
        
    }
    if(buns<2) return false;

    //Chequea si la cantidad de ingredientes del medio, concuerda con el burger preparado
    for(int i = 1; i < ingredients.size() - 1; i++){
        int c=0;
        bool itHas_Ingredient=false;
        
        for(int j=1;j<player_b->ingredients.size()-1;j++){
            if(player_b->ingredients[j]->name==this->ingredients[i]->name){
                c++;
                itHas_Ingredient=true;
            }
        }

        if(itHas_Ingredient == false|| c!=player_b->order[ingredients[i]->name]) return false;
        
    }

    //Si pasa todas las pruebas, es cierto
    return true;

    }

int Burger::getBurgerCost(Burger* burger){
    int totVal = 2; // Burger will always have 2 buns 
    for(int i = 1; i <= burger->ingredients.size()-2; i++)
    {
        if(burger->ingredients[i]->name == "cheese") totVal += 3;
        else if(burger->ingredients[i]->name == "lettuce") totVal += 2;
        else if(burger->ingredients[i]->name == "tomato") totVal += 2;
        else if(burger->ingredients[i]->name == "patty") totVal += 4;
    } 
    return totVal;
}