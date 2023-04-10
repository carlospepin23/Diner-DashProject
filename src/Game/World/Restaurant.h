//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* u_burger;
        Item* botBread;
        Item* topBread;
        ofImage Table_PNG;
        ofImage floor;
        ofImage plant1;
        ofImage plant2;
        ofImage plant3;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        void keyReleased(int key){player->keyReleased(key);}
        EntityManager* getEntityManager(){return entityManager;}
        int getMoney(){return this->money;}
};
