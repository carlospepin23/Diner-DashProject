
#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* u_item, Item* c_item, ofImage sprite): BaseCounter(x, y, width, height, c_item, sprite) {
    cooking = false;  // Inicializa el bool cooking a falso
    this->c_item=c_item; //Objeto cocinado y el crudo estan invertidos on purpose
    this->u_item=u_item;
    setCurrent_Item(this->u_item);
    
//--------SOUND SETTER--------------------------------
    sound_cooking.load("cooking.wav");
    sound_cooked.load("cooked.wav");
    sound_cooking.setVolume(1);
    sound_cooked.setVolume(1);

}

void StoveCounter::showItem(){
    if (getItem()!= nullptr){
        getItem()->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}

void StoveCounter::tick(){
    if (!pattyCooked) {  // Si no esta cocinado, entonces lo incrementa
        ticks++;
        if(ticks >= time){
            sound_cooking.stop();
            pattyCooked=true;
            sound_cooked.play();
        }
    }
}

void StoveCounter::startCooking() {
    if (!cooking && !pattyCooked) {  // Solo empieza a cocinar si no se esta cocinando ni esta ya cocinado
        cooking = true;  // Establece el bool cooking a cierto
    }
    sound_cooking.play();
    while (cooking) {  // Si esta cocinando, continua el proceso de update
        tick();  // Continua llamando los ticks
        if (pattyCooked) {  // Si el patty esta cocinado, actualiza el objeto por el cocinado, y restablece el bool de cooking
            setCurrent_Item(this->c_item);  // Cambia el objeto actual por el cocinado
            cooking = false;  // Restablece el bool de cooking
        }
    }
    
}

void StoveCounter::pickupItem() {
    if (pattyCooked) { 
        setCurrent_Item(this->u_item);
        pattyCooked = false;
        resetTicks();
    }
}