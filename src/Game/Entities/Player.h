#pragma once
#include "Animation.h"
#include "Burger.h"
#include "EntityManager.h"
#include "BaseCounter.h"
class Player: public Entity{

    private:
        int speed = 5;
        string facing = "right";
        bool stop; //Encargado de que el chef se quede quieto si no se estan presionando los arrows
        Animation *chefAnim;
        Burger *burger;
        EntityManager* entityManager;
    public:
        Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void mousePressed(int, int, int);
        void setFacing(string);
        void setPlayerStop(bool);
        BaseCounter* getActiveCounter();
        Burger* getBurger();
        void discardBurger();
        
};