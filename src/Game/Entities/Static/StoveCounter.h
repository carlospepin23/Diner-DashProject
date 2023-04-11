#include "BaseCounter.h"


class StoveCounter: public BaseCounter {
    private:
        Item *current_item;
        Item *u_item;
        Item *c_item;
        bool cooking;
        bool pattyCooked=false;
        long long int ticks = 0;
        long long int time=500000000; //5x10^8
        ofSoundPlayer sound_cooking;
        ofSoundPlayer sound_cooked;

    public:
        StoveCounter(int x, int y, int width, int height, Item* c_item, Item* u_item, ofImage sprite);

        Item* getItem(){return this->current_item;};
        void resetTicks(){this->ticks=0;}
        void setCurrent_Item(Item* item){this->current_item=item;}
        void showItem();
        void tick();
        void startCooking();
        void pickupItem();
        bool isPattyCooked() {return pattyCooked;}
};
