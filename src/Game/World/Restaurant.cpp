//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    ofImage variousSprites,door;
    floor.load("images/floor.jpg");
    variousSprites.load("images/sprite.png");
    door.cropFrom(variousSprites,263,116,32,49);
    doorEntrance=door;
    //Cargando las imagenes
    plant1.load("images/P1_PNG.png");
    plant2.load("images/P2_PNG.png");
    plant3.load("images/P3_PNG.png");
    Table_PNG.load("images/table_PNG.png"); 

    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, burger_fSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, u_burgerImg, onionImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    burger_fSpriteSheet.load("images/burger_f.png");

    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    u_burgerImg.cropFrom(burger_fSpriteSheet, 30, 134, 103, 48); // uncooked patty
    onionImg.cropFrom(burgerSpriteSheet, 319, 157,104, 40); //onion               
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate
    

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    u_burger = new Item(u_burgerImg, "patty");
    onion = new Item(onionImg,"onion");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, onionCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    onionCounterImg.cropFrom(counterSheet,65,204,32,43);//Cebolla                                                 
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, u_burger, burger, stoveCounterImg)); 
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, onionCounterImg)); //cambiar nullptr por cebolla
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    if((entityManager->firstClient->getPatience() == 1) && (dynamic_cast<Inspector*>(entityManager->firstClient))) money = money/2;
    ticks++;
    if(ticks % 400 == 0){
        generateClient();
    }
    player->tick();
    entityManager->tick();

}


void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    for(int i = 0; i < ofRandom(1,3); i++)
    {
        int randNum = ofRandom(1,5);
        if(randNum == 1){
            b->addIngredient(burger);
            b->order[burger->name]++;
        }
        else if(randNum == 2){
            b->addIngredient(cheese);
            b->order[cheese->name]++;
        }
        else if(randNum == 3){
            b->addIngredient(tomato);
            b->order[tomato->name]++;
        }
        else if(randNum == 4){
            b->addIngredient(lettuce);
            b->order[lettuce->name]++;
        }
    }
    b->addIngredient(topBread);
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    doorEntrance.draw(250,0,75,100); //dibuja la puerta de entrada
    Table_PNG.draw(500, 50, 100, 100); //dibuja mesa #1
    plant1.draw(525,30, 50, 50); //dibuja planta de mesa #1
    Table_PNG.draw(500, 150, 100, 100); //dibuja mesa #2
    plant2.draw(525,120, 60, 60); //dibuja planta de mesa #2
    Table_PNG.draw(500, 250, 100, 100); //dibuja mesa #3
    plant3.draw(525,220, 60, 60); //dibuja planta de mesa #3
    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2, 10);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        money += entityManager->firstClient->serve(player->getBurger());
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's' && player->getBurger()->hasIngredients()){ 
        serveClient();
        player->discardBurger();
    }
    if(key == 'e'){
        money-=1; //Aplica el costo de los ingredientes al total
    }
    // if(key == 'p'){
    //     money-=10; //Aplica el costo de los ingredientes al total
    // }

}