#include "Object.h"

Object::Object(double x, double y, double width, double height) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                if (i < 2) {
                    vertices[i][j] = x - (width/2.0);
                }
                else {
                    vertices[i][j] = x + (width/2.0);
                }
            }
            else {
                if (i % 2 == 0) {
                    vertices[i][j] = y - (width/2.0);
                }
                else {
                    vertices[i][j] = y + (width/2.0);
                }
            }
        }
    }
    coordinates[0] = x;
    coordinates[1] = y;
}

void MotionObject::move() {

}