#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger) : Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}

void Client::render(){
    burger->render();
    if((patience < 1500) && (patience > 1000))
    {
        ofSetColor(ofColor::lightPink);
    }
    else if( (patience < 1000) && (patience > 500))
    {
        ofSetColor(ofColor::red);
    }
    else if(patience < 500)
    {
        ofSetColor(ofColor::darkRed);
    }
    sprite.draw(x, y, width, height);
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0)
    {
        isMad = true;
        isLeaving = true; 
    }
    if(nextClient != nullptr)
    {
        nextClient->tick();
    }
}

int Client::serve(Burger* b){
    if(isMad == false){
        if(this->burger->equals(b)){ //burger igual al primer cliente
            isLeaving = true;
            return burger->getBurgerCost(burger);
        }
        else //Si no es igual al primero se lo ofrece al siguiente
        {
            if(nextClient != nullptr) return nextClient->serve(b);
            
            else return 0;
        }
    }
    else
    {
        isLeaving = true;
        return 0;
    }
   
}