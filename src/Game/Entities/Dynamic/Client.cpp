#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger) : Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}

int Client::getPatience()
{
    return patience;
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
        if(this->burger->equals(b)){
            isLeaving = true;
            return burger->getBurgerCost(burger);
        }
        else
        {
            if(nextClient != nullptr)
            {
                return nextClient->serve(b);
            }
            else
            {
                isLeaving = false;
                return 0;
            }
        }
        return 0; //No quitar! Es para que el equal method funcione, y no de problemas con el return type
    }
    else
    {
        isLeaving = true;
        return 0;
    }
   
}