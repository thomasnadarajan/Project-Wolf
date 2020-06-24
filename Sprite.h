#include "Object.h"

class Sprite {
    Object o;
    int allegiance;
    Sprite(Object& obj, int allegiance) {
        o = obj;
        this->allegiance = allegiance;
    }
}

