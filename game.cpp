#include <iostream>
#include "Object.h"
Player(double x, double y, double width, double height, double move){
    health_points = 100;
}

Game(double x, double y, double width, double height, double move) {
    p(x, y, width, height, move);
}
void add_object(double x, double y, double width, double height, int motion) {
    if (motion == 1) {
        MotionObject o(x, y, width, height, );
        objects.push_back(o);
    }
    else {
        Object o(x, y, width, height);
        objects.push_back(o);
    }
}

