#include "Player.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){

    vector<ofImage> chefAnimframes;
    ofImage temp;
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    this->entityManager = em;
    
}
void Player::tick(){
    chefAnim->tick();
    
    if(facing == "left"  && stop==false){ //FIX Minor bugs respecto al movimiento del chef cuando toca un limite.
        x-=speed;
    }else if(facing == "right"  && stop==false){
        x+=speed;
    }
    //Limites
    if(x <= 0){
        facing = "right";
    }else if(x + width >= ofGetWidth()){
        facing = "left";
    }
}

void Player::render(){
    BaseCounter *ac = getActiveCounter();
    if (ac != nullptr) {
        ac->showItem();
    }
    ofSetColor(256, 256, 256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if (facing == "left") {
        currentFrame.mirror(false, true);
    }
    currentFrame.draw(x, y, width, height);
    burger->render();
}

void Player::keyPressed(int key){
    if(key == 'e'){
        BaseCounter* ac = getActiveCounter();
        if(ac != nullptr){
            Item* item = ac->getItem();
            if(item != nullptr){
                burger->addIngredient(item);
                burger->order[item->name]++; //IDEA: Deberia recuperar su dolar, por tener de vuelta su igrediente
            }
        }
    }
    if(key == 'u'){
        if(burger->hasIngredients()){
            burger->undoIngredient();
        }
    }

    if(key == OF_KEY_LEFT){ //el chef se mueve para la izquierda cuando se presiona left arrow
        setFacing("left");
        setPlayerStop(false);
    }
    else if (key == OF_KEY_RIGHT){ //el chef se mueve para la derecha cuando se presiona right arrow
        setFacing("right");
        setPlayerStop(false);
    }

}
BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}

void Player::keyReleased(int key) {
    if(key == OF_KEY_RIGHT || key == OF_KEY_LEFT){
       setPlayerStop(true);
    }
    
}
void Player::mousePressed(int x, int y, int button) {
}

void Player::setFacing(string facing){ this->facing = facing; }

void Player::setPlayerStop(bool t){
    this->stop=t;
}

void Player::discardBurger(){ //discards the already served burger, and its quantitys registered
    // this->burger = new Burger(ofGetWidth()-110, 100, 100, 50); //working method placed just in case the code needs to be refactored for other implementations.
    this->burger->clear();
    this->burger->order={
      {"tomato",0},
      {"lettuce",0},
      {"cheese",0},
      {"patty",0}  
    };
}

Burger* Player::getBurger(){
    return burger;
}